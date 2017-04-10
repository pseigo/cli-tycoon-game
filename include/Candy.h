#ifndef CANDY_H
#define CANDY_H

#include <iostream>
#include <string>
#include "../include/FGraphic.h"

class Candy
{
    public:
        Candy();
        virtual ~Candy();

        std::string GetId() const;
        std::string GetName() const;
        std::string GetType() const;
        int IGetBuyPrice() const;
        int IGetSellPrice() const;
        int IGetQuantity() const;
        std::string SGetBuyPrice();
        std::string SGetSellPrice();
        std::string SGetQuantity();

        void SetId(std::string);
        void SetAttributes();
        void AddQuantity(int purchaseAmount);

    protected:
    private:
        FGraphic Box;

        std::string id; // used to identify candy in class
        std::string name; // in-game name
        std::string type; // category of candy
        int buyPrice;
        int sellPrice;
        int quantity;
};

#endif // CANDY_H
