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
        // the number we want to subtract from the original number
        /* Using pow(x,y) leads to rounding errors that are not acceptable so I am using
            repeated division by 10 to eliminate that error.  Multiplier is a copy of the number
            because I will be changing the number as I operate on it.
        */
        int multiplier = number;
        while (multiplier > 9) {
            multiplier /= 10;
        }
        // cout << "multiplier:" << multiplier << endl;

        /* Now I know what the left most number is (multiplier), so I can add it to the string*/
        answer += (char)(multiplier + 48);
        //cout << "Answer so far: " << answer << endl;

        /* Since I can't use pow(x,y), I am using repeated multiplication by 10 to get the right divisor*/
        int base = 1;
        for (int x = 0; x < length - 1; x++) {
            base *= 10;
        }
        // cout << "base:" <<base << endl;

        /* At this point, I have the leftmost number (multiplier) and the place value (base) as integers
            so I can mulitply them and subtract them from the number*/
        number = number - (base * multiplier);

        length--;
    } while (length > 0);

    return answer;
}
