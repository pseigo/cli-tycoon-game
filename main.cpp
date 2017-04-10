#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "include/FGraphic.h"
#include "include/Tycoon.h"

using namespace std;

string toString(int number);

void PrintIntro(FGraphic Box);
bool AskToPlayGame();
void PlayGame();

int main()
{
    FGraphic Box;

    // Main game loop
    do
    {
        PrintIntro(Box);

        if (AskToPlayGame()) {

            PlayGame();
            break;
        } else { break; }
    } while (true);

    cout << "Thanks for playing!" << endl;
    return 0;
}

string toString(int number)
{
    string answer = "";

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

void PrintIntro(FGraphic Box)
{
    vector<string> boxItems = {"Welcome to Candy Tycoon.", "0. Exit Game", "1. Start Game", "", "------------------------", "To go where no second", "grader has gone before."};
    Box.drawBox(26, boxItems);
}

bool AskToPlayGame()
{
    int userChoice = 1;

    while (true)
    {
        cout << ">> ";
        cin >> userChoice;
        //cout << '\n';

        if (!cin.good() || (userChoice != 0 && userChoice != 1)) {
            cout << "Invalid input. Must choose 0 or 1. \n" << endl;
            cin.clear();
            cin.ignore(128, '\n');
        } else {
            break;
        }
    }

    return userChoice;
}

void PlayGame()
{
    Tycoon Candy;

    Candy.PrintStoryIntro();
}
