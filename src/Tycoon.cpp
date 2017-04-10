#include "../include/Tycoon.h"

Tycoon::Tycoon() { Reset(); }
Tycoon::~Tycoon() { /*dtor*/ }

void Tycoon::Reset()
{
    boxItems.clear();

    // Candy
    ChocolateNut.SetId("CHOCNUT");
    ChocolateBar.SetId("CHOCBAR");
    SourSoother.SetId("SOURSOOTHER");
    SourFuzzyPeach.SetId("SOURPEACH");
    SourPatchKids.SetId("SOURKIDS");
    GummyBear.SetId("GUMMYBEAR");
    GummyWorm.SetId("GUMMYWORM");
    GumSpearmint.SetId("GUMSPEARMINT");
    GumDubbleBubble.SetId("GUMDUBBLE");
}

void Tycoon::PrintStoryIntro()
{
    std::cout << R"(
It was September, the month of peace and breathing.
    )" << std::endl;

    system("pause");
    system("cls");

    return;
}

void Tycoon::PrintMainMenu()
{
    boxItems.clear();
    boxItems.push_back("Inventory:");
    boxItems.push_back(Box.div);
    boxItems.push_back(ChocolateBar.GetId());
    boxItems.push_back(ChocolateBar.GetName());
    boxItems.push_back(ChocolateBar.GetType());
    boxItems.push_back(Box.toString(ChocolateBar.GetBuyPrice()));
    boxItems.push_back(Box.toString(ChocolateBar.GetSellPrice()));
    Box.drawBox(-1, boxItems);
}

void Tycoon::GetMainMenuInput()
{

}

void Tycoon::PrintShop()
{

}

void Tycoon::GetShopInput()
{

}

void Tycoon::PlayDay()
{

}
