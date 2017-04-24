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

std::string Candy::SGetBuyPrice() { return Box.centsToString(buyPrice); }
std::string Candy::SGetSellPrice() { return Box.centsToString(sellPrice); }
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
        buyPrice = 5;
        sellPrice = 9;
    } else if (id == "CHOCBAR") {
        name = "Mini Chocolate Bar";
        type = "Chocolate";
        buyPrice = 50;
        sellPrice = 63;
    } else if (id == "SOURSOOTHER") {
        name = "Sour Soother";
        type = "Sour Candy";
        buyPrice = 15;
        sellPrice = 25;
    } else if (id == "SOURPEACH") {
        name = "Fuzzy Peaches";
        type = "Sour Candy";
        buyPrice = 60;
        sellPrice = 54;
    } else if (id == "SOURKIDS") {
        name = "Sour Patch Kids";
        type = "Sour Candy";
        buyPrice = 25;
        sellPrice = 36;
    } else if (id == "GUMMYBEAR") {
        name = "Gummy Bear";
        type = "Gummy Candy";
        buyPrice = 10;
        sellPrice = 7;
    } else if (id == "GUMMYWORM") {
        name = "Gummy Worm";
        type = "Gummy Candy";
        buyPrice = 15;
        sellPrice = 18;
    } else if (id == "GUMSPEARMINT") {
        name = "Spearmint Gum";
        type = "Gum";
        buyPrice = 199;
        sellPrice = 219;
    } else if (id == "GUMDUBBLE") {
        name = "Dubble Bubble Gum";
        type = "Gum";
        buyPrice = 49;
        sellPrice = 58;
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

void Candy::RemoveQuantity(int purchaseAmount)
{
    quantity -= purchaseAmount;
    return;
}
