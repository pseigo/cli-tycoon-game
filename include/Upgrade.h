#ifndef UPGRADE_H
#define UPGRADE_H

#include <iostream>
#include <string>
#include "../include/FGraphic.h"

class Upgrade
{
    public:
        Upgrade();
        virtual ~Upgrade();

        std::string SGetId() const;
        std::string SGetName() const;
        std::string SGetDescription() const;
        std::string SGetBuyPrice();
        std::string SGetUpgradePrereq();
        int IGetBuyPrice() const;
        bool BGetHaveUpgrade() const;
        std::string SGetHaveUpgrade();


        void SetId(std::string input);
        void SetAttributes();
        void SetOwnership();

    protected:
    private:
        FGraphic Box;

        std::string id; // used to identify upgrade in class
        std::string name; // in-game name
        std::string description; // shop description
        int buyPrice;
        bool haveUpgrade;
        std::string preReqId; // id of a prerequisite

        std::string currency;
};

#endif // UPGRADE_H





