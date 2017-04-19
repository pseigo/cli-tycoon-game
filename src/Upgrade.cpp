#include "Upgrade.h"

Upgrade::Upgrade()
{
    id = "NULL_ID";
    name = "NULL_NAME";
    description = "NULL_DESCRIPTION";
    buyPrice = 0;
    haveUpgrade = false;
    preReqId = "NULL_PREREQUISITE_ID";

    currency = '$';

    return;
}

Upgrade::~Upgrade()
{
    //dtor
}

std::string Upgrade::SGetId() const { return id; }
std::string Upgrade::SGetName() const { return name; }
std::string Upgrade::SGetDescription() const { return description; }
std::string Upgrade::SGetBuyPrice() { return Box.centsToString(buyPrice); }
std::string Upgrade::SGetUpgradePrereq() { return preReqId; }
int Upgrade::IGetBuyPrice() const { return buyPrice; }
bool Upgrade::BGetHaveUpgrade() const { return haveUpgrade; }

std::string Upgrade::SGetHaveUpgrade()
{
    std::string buyText = "Buy (" + currency + Box.centsToString(buyPrice) + ")";
    if (haveUpgrade)
        return "Owned";
    else
        return buyText;
}


// setter methods
void Upgrade::SetId(std::string input)
{
    id = input;
    SetAttributes();
    return;
}

void Upgrade::SetAttributes()
{
    if (id == "BACKPACK") {
        name = "Backpack";
        description = "Expands supply for any given candy from 10 to 30.";
        buyPrice = 5000;
        preReqId = "none";
    } else if (id == "DUFFLEBAG") {
        name = "Duffle Bag (requires Backpack)";
        description = "Expands supply for any given candy from 30 to 100.";
        buyPrice = 15000;
        preReqId = "Backpack";
    } else {
        std::cerr << "NULL_ID (" << id << "): Can't set attributes of candy!" << std::endl;
    }

    return;
}

void Upgrade::SetOwnership() { haveUpgrade = true; }
