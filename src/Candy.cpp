#include "../include/Candy.h"

Candy::Candy()
{
    id = "NULL_ID";
    name = "NULL_NAME";
    type = "NULL_TYPE";
    buyPrice = 0;
    sellPrice = 0;
    quantity = 0;
}

Candy::~Candy()
{
    //dtor
}

// getter methods
std::string Candy::GetId() const { return id; }
std::string Candy::GetName() const { return name; }
std::string Candy::GetType() const { return type; }
int Candy::IGetBuyPrice() const { return buyPrice; }
int Candy::IGetSellPrice() const { return sellPrice; }
int Candy::IGetQuantity() const { return quantity; }

std::string Candy::SGetBuyPrice() { return Box.toString(buyPrice); }
std::string Candy::SGetSellPrice() { return Box.toString(sellPrice); }
std::string Candy::SGetQuantity() { return Box.toString(quantity); }

// setter methods
void Candy::SetId(std::string input)
{
    id = input;
    SetAttributes();
    return;
}

void Candy::SetAttributes()
{
    if (id == "CHOCNUT") {
        name = "Chocolate Covered Nuts";
        type = "Chocolate";
        buyPrice = 2;
        sellPrice = 3;
    } else if (id == "CHOCBAR") {
        name = "Mini Chocolate Bar";
        type = "Chocolate";
        buyPrice = 3;
        sellPrice = 4;
    } else if (id == "SOURSOOTHER") {
        name = "Sour Soother";
        type = "Sour Candy";
        buyPrice = 5;
        sellPrice = 7;
    } else if (id == "SOURPEACH") {
        name = "Fuzzy Peaches";
        type = "Sour Candy";
        buyPrice = 13;
        sellPrice = 14;
    } else if (id == "SOURKIDS") {
        name = "Sour Patch Kids";
        type = "Sour Candy";
        buyPrice = 19;
        sellPrice = 25;
    } else if (id == "GUMMYBEAR") {
        name = "Gummy Bear";
        type = "Gummy Candy";
        buyPrice = 15;
        sellPrice = 18;
    } else if (id == "GUMMYWORM") {
        name = "Gummy Worm";
        type = "Gummy Candy";
        buyPrice = 16;
        sellPrice = 22;
    } else if (id == "GUMSPEARMINT") {
        name = "Spearmint Gum";
        type = "Gum";
        buyPrice = 31;
        sellPrice = 41;
    } else if (id == "GUMDUBBLE") {
        name = "Dubble Bubble Gum";
        type = "Gum";
        buyPrice = 1;
        sellPrice = 2;
    } else {
        std::cerr << "NULL_ID (" << id << "): Can't set attributes of candy!" << std::endl;
    }

    return;
}

void Candy::AddQuantity(int purchaseAmount)
{
    quantity += purchaseAmount;
    return;
}
