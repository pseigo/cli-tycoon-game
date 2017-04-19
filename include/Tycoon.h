#ifndef TYCOON_H
#define TYCOON_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <windows.h>
#include <cstdlib> // rand and srand for customers buying
#include <ctime> // time for rand
#include "../include/FGraphic.h"
#include "../include/Candy.h"
#include "../include/Upgrade.h"

class Tycoon
{
    public:
        Tycoon(); // constructor
        virtual ~Tycoon(); // destructor

        void Reset();

        void PrintStoryIntro();

        void PrintMainMenu();
        int GetMainMenuInput();

        void PrintInventory();

        void PrintShop();
        bool GetShopInput();
        bool ValidPurchase(int candyPrice, int amount, std::string candyName);
        void PrintUpgrades();
        bool GetUpgradesInput();
        bool HaveUpgradePrereq(Upgrade *currentUpgrade);

        bool PlayDay();
        void DayPatrol();
        void DayCustomers();
        void DayCustomersBuyCandy(Candy *currentCandy, int amountPurchased);
        int BullyTax(int moneyToTax);
        void ReportTotalBullyTax();
        void ReportIncome();
        bool GameIsWon();
        bool GameIsLost();
        void EndGame();


        bool AskToQuit();

    protected:
    private:
        FGraphic Box;
        std::vector<std::string> boxItems;

        int day;
        int money;
        int bullyMoney;
        std::string currency;

        int dayIncome;

        // candy
        Candy ChocolateNut, ChocolateBar;
        Candy SourSoother, SourFuzzyPeach, SourPatchKids;
        Candy GummyBear, GummyWorm;
        Candy GumSpearmint, GumDubbleBubble;

        const int CANDY_AMOUNT = 9;

        // upgrades
        Upgrade Backpack, DuffleBag;
};

#endif // TYCOON_H
