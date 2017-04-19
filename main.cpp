#include <iostream>
#include <string>
#include <vector>
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

    // cout << Box.centsToString(1234567) << endl;
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

void PrintIntro(FGraphic Box)
{
    vector<string> boxItems = {"Welcome to Candy Tycoon.", "1. Start Game", "0. Exit Game", "", Box.div, "To go where no second", "grader has gone before."};
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
    Tycoon Tc;
    int mainMenuChoice;
    bool exitGame = false;

    Tc.PrintStoryIntro();

    do { // main game loop
        ClearScreen();
        Tc.PrintMainMenu();
        mainMenuChoice = Tc.GetMainMenuInput();

        switch (mainMenuChoice) {
        case 1: // inventory
            Tc.PrintInventory();
            break;
        case 2: // shop
            do {
                Tc.PrintShop();
            } while (Tc.GetShopInput());

            break;
        case 3:
            do {
                Tc.PrintUpgrades();
            } while (Tc.GetUpgradesInput());
            break;
        case 4: // start the day
            if (Tc.PlayDay() == 0) {
                exitGame = true;
            }
            break;
        default:
            exitGame = Tc.AskToQuit();
        }
    } while (exitGame == false);
}
