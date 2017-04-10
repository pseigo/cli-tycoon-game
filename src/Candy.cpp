#include "../include/Candy.h"

Candy::Candy()
{
    id = "NULL_ID";
    name = "NULL_NAME";
    type = "NULL_TYPE";
    buyPrice = 1;
    sellPrice = 1;
}

Candy::~Candy()
{
    //dtor
}

// getter methods
std::string Candy::GetId() const { return id; }
std::string Candy::GetName() const { return name; }
std::string Candy::GetType() const { return type; }
int Candy::GetBuyPrice() const { return buyPrice; }
int Candy::GetSellPrice() const { return sellPrice; }

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
        name = "Chocolate Nuts";
        type = "Chocolate";
        buyPrice = 4.50;
        sellPrice = 2;
    } else if (id == "CHOCBAR") {
        name = "Chocolate Bar";
        type = "Chocolate";
        buyPrice = 4;
        sellPrice = 2;
    } else if (id == "SOURSOOTHER") {
        name = "Sour Soother";
        type = "Sour Candy";
        buyPrice = 4;
        sellPrice = 2;
    } else if (id == "SOURPEACH") {
        name = "Fuzzy Peach";
        type = "Sour Candy";
        buyPrice = 4;
        sellPrice = 2;
    } else if (id == "SOURKIDS") {
        name = "Sour Patch Kids";
        type = "Sour Candy";
        buyPrice = 4;
        sellPrice = 2;
    } else if (id == "GUMMYBEAR") {
        name = "Gummy Bear";
        type = "Gummy Candy";
        buyPrice = 4;
        sellPrice = 2;
    } else if (id == "GUMMYWORM") {
        name = "Gummy Worm";
        type = "Gummy Candy";
        buyPrice = 4;
        sellPrice = 2;
    } else if (id == "GUMSPEARMINT") {
        name = "Gum Spearmint";
        type = "Gum";
        buyPrice = 4;
        sellPrice = 2;
    } else if (id == "GUMDUBBLE") {
        name = "Dubble Bubble";
        type = "Gum";
        buyPrice = 4;
        sellPrice = 2;
    } else {
        std::cerr << "NULL_ID: Can't set attributes of candy!" << std::endl;
    }

    return;
}
