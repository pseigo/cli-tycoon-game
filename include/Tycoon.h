#ifndef TYCOON_H
#define TYCOON_H

#include <iostream>
#include <string>
#include <vector>
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
        void GetMainMenuInput();

        void PrintShop();
        void GetShopInput();

        void PlayDay();

    protected:
    private:
        FGraphic Box;
        std::vector<std::string> boxItems;

        std::string boxDivider;

        // inventory

        // candy
        Candy ChocolateNut, ChocolateBar;
        Candy SourSoother, SourFuzzyPeach, SourPatchKids;
        Candy GummyBear, GummyWorm;
        Candy GumSpearmint, GumDubbleBubble;
};

#endif // TYCOON_H
