#ifndef CANDY_H
#define CANDY_H

#include <iostream>
#include <string>

class Candy
{
    public:
        Candy();
        virtual ~Candy();

        std::string GetId() const;
        std::string GetName() const;
        std::string GetType() const;
        int GetBuyPrice() const;
        int GetSellPrice() const;

        void SetId(std::string);
        void SetAttributes();

    protected:
    private:
        std::string id; // used to identify candy in class
        std::string name; // in-game name
        std::string type; // category of candy
        int buyPrice;
        int sellPrice;
};

#endif // CANDY_H
