#include "../include/FGraphic.h"

void ClearScreen()
{
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
}

FGraphic::FGraphic() { div = "======================"; }
FGraphic::~FGraphic() { /*dtor*/}

// define boxwidth as an int. boxwidth < 1 will automatically set a width (slower).
void FGraphic::drawBox(int boxWidth, std::vector<std::string> items) const
{
    // Top Row
    std::cout << pCornerTopLeft;

    if (boxWidth < 1) {
        // auto length
        int longestItem = 0;
        for (std::string currentItem : items) {
            if (currentItem.length() > longestItem) {
                longestItem = currentItem.length();
            }
        }
        if (boxWidth == -100) { std::cout << "\nAuto box width is " << longestItem + 2 << std::endl; }
        boxWidth = longestItem + 2;
    }

    for (int i = 0; i < boxWidth; i++) { std::cout << pStraightHorizontal; }
    std::cout << pCornerTopRight << std::endl;

    // Content
    for (std::string currentItem : items) {
        std::cout << pStraightVertical << " ";
        std::cout << currentItem;
        //std::cout << items[currentItem];

        // Spaces to end of box
        for (int spaceCount = 0; spaceCount < (boxWidth - currentItem.length() - 1); spaceCount++) {
            std::cout << ' ';
        }

        std::cout << pStraightVertical << std::endl;
    }

    // Bottom Row
    std::cout << pCornerBottomLeft;
    for (int i = 0; i < boxWidth; i++) { std::cout << pStraightHorizontal; }
    std::cout << pCornerBottomRight << std::endl;

}

std::string FGraphic::toString(int number)
{
    std::string answer = "";

    if (number < 0)
    {
        answer += '-';
        number *= (-1);
    }
    else if (number == 0) { return "0"; }

    // calculating the length
    int length = 0;
    for (length; pow(10,length) < number; length++);

    do
    {
        /* Using pow(x,y) leads to rounding errors that are not acceptable so I am using
            repeated division by 10 to eliminate that error.  Multiplier is a copy of the number
            because I will be changing the number as I operate on it.
        */
        int multiplier = number;
        while (multiplier > 9) {
            multiplier /= 10;
        }

        /* Now I know what the left most number is (multiplier), so I can add it to the string*/
        answer += (char)(multiplier + 48);

        /* Since I can't use pow(x,y), I am using repeated multiplication by 10 to get the right divisor*/
        int base = 1;
        for (int x = 0; x < length - 1; x++) {
            base *= 10;
        }

        /* At this point, I have the leftmost number (multiplier) and the place value (base) as integers
            so I can mulitply them and subtract them from the number*/
        number -= (base * multiplier);

        length--;
    } while (length > 0);

    return answer;
}

std::string FGraphic::centsToString(int cents)
{
    /*
     * FAIR WARNING:
     * this method is extremely inefficient and hard to read.
     * it was written the night before the project's due date
     * so I didn't have much time to encapsulate this madness
     * into something useable. in fact, it only exists because
     * of my limited use boxDraw method which requires strings.
     * TODO: completely recreate this method
    */
    const int ASCII_NUM = 48;
    std::string answer = "";

    // Length of cents
    int length = 0;
    // int casting is necessary to avoid rounding errors!
    for (length; int(pow(10,length)) <= cents; length++);

    // Base multiplier of cents
    int base = 1;
    for (int x = 0; x < length - 1; x++) { base *= 10; }

    if (cents < 0)
    {
        answer += '-';
        cents *= (-1);
    }
    else if (cents == 0) { return "0"; }

    if (length == 1) { // 0.0x
        answer += (char)(0 + ASCII_NUM); // 0
        answer += (char)(46); // .
        answer += (char)(0 + ASCII_NUM); // 0
        answer += (char)(cents + ASCII_NUM); // x
    } else if (length == 2) { // 0.xx
        answer += (char)(0 + ASCII_NUM); // 0
        answer += (char)(46); // .
        answer += (char)((cents / 10) + ASCII_NUM); // x
        answer += (char)((cents - (cents / 10 * 10)) + ASCII_NUM); // x

    } else if (length >= 3) {
        if (cents % 100 == 0) { // x.00
            // begin: digits BEFORE the decimal
            int temp;
            for (int place = 2; place < length; place++) {
                temp = cents;
                temp = temp / base;

                // after first digit, we need to modulus by 10 to get the digit for that base
                if (place > 2) {
                    temp = temp % 10;
                }
                answer += (char)(temp + ASCII_NUM);

                // std::cout << "Added: " << temp << " with base " << base << std::endl;
                base /= 10; // drops down to next base
            } // end: digits BEFORE the decimal

            answer += (char)(46); // .
            answer += (char)(0 + ASCII_NUM); // 0
            answer += (char)(0 + ASCII_NUM); // 0
        } else { // if there is > 0 cents, eg. $2.01
            // begin: digits BEFORE the decimal
            int temp;
            for (int place = 2; place < length; place++) {
                temp = cents;
                temp = temp / base;

                // after first digit, we need to modulus by 10 to get the digit for that base
                if (place > 2) {
                    temp = temp % 10;
                }
                answer += (char)(temp + ASCII_NUM);

                // std::cout << "Added: " << temp << " with base " << base << std::endl;
                base /= 10; // drops down to next base
            } // end: digits BEFORE the decimal

            // answer += (char)((cents / 100) + ASCII_NUM); // x
            answer += (char)(46); // .

            if ( (cents - (cents / 100 * 100)) >= 10) { // if the cents are between 10 and 99
                answer += (char)((cents / 10 % 10) + ASCII_NUM); // first decimal place (0.x0)
                answer += (char)((cents % 100 % 10) + ASCII_NUM); // second decimal place (0.0x)
            } else { // if the cents are between 1 and 9
                answer += (char)(0 + ASCII_NUM); // 0
                answer += (char)((cents % 100) + ASCII_NUM); // x
            }

        }
    }

    return answer;
}
