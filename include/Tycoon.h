#ifndef TYCOON_H
#define TYCOON_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <windows.h>
#include "../include/FGraphic.h"
#include "../include/Candy.h"

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

        void PlayDay();

    protected:
    private:
        FGraphic Box;
        std::vector<std::string> boxItems;

        int day;
        int money;
        std::string currency;

        // candy
        Candy ChocolateNut, ChocolateBar;
        Candy SourSoother, SourFuzzyPeach, SourPatchKids;
        Candy GummyBear, GummyWorm;
        Candy GumSpearmint, GumDubbleBubble;
};

#endif // TYCOON_H
