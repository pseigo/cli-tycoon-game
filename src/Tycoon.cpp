#include "../include/Tycoon.h"

Tycoon::Tycoon() { Reset(); }
Tycoon::~Tycoon() { /*dtor*/ }

void Tycoon::Reset()
{
    boxItems.clear();

    day = 0;
    money = 15;
    currency = '$';

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
    boxItems.push_back("Main Menu || Day: " + Box.toString(day));
    boxItems.push_back(Box.div);
    boxItems.push_back("0. Exit game");
    boxItems.push_back("1. View inventory");
    boxItems.push_back("2. Go to the store");
    boxItems.push_back("3. Start the day");
    Box.drawBox(-1, boxItems);
}

int Tycoon::GetMainMenuInput()
{
    int userChoice = 1;

    while (true)
    {
        std::cout << ">> ";
        std::cin >> userChoice;
        std::cout << '\n';

        if (!std::cin.good() || (userChoice != 0 && userChoice != 1 && userChoice != 2 && userChoice != 3)) {
            std::cout << "Invalid input. Must choose 0, 1, 2, or 3. \n" << std::endl;
            std::cin.clear();
            std::cin.ignore(128, '\n');
        } else {
            break;
        }
    }

    return userChoice;
}

void Tycoon::PrintInventory()
{
    boxItems.clear();
    boxItems.push_back("Inventory || Money: " + currency + Box.toString(money));
    boxItems.push_back(Box.div);
    boxItems.push_back("== Chocolate ==");
    boxItems.push_back(ChocolateNut.SGetQuantity() + ' ' + ChocolateNut.GetName());
    boxItems.push_back(ChocolateBar.SGetQuantity() + ' ' + ChocolateBar.GetName());
    boxItems.push_back(""); // line break
    boxItems.push_back("== Sour Candy ==");
    boxItems.push_back(SourSoother.SGetQuantity() + ' ' + SourSoother.GetName());
    boxItems.push_back(SourFuzzyPeach.SGetQuantity() + ' ' + SourFuzzyPeach.GetName());
    boxItems.push_back(SourPatchKids.SGetQuantity() + ' ' + SourPatchKids.GetName());
    boxItems.push_back(""); // line break
    boxItems.push_back("== Gummy Candy ==");
    boxItems.push_back(GummyBear.SGetQuantity() + ' ' + GummyBear.GetName());
    boxItems.push_back(GummyWorm.SGetQuantity() + ' ' + GummyWorm.GetName());
    boxItems.push_back(""); // line break
    boxItems.push_back("== Gum ==");
    boxItems.push_back(GumSpearmint.SGetQuantity() + ' ' + GumSpearmint.GetName());
    boxItems.push_back(GumDubbleBubble.SGetQuantity() + ' ' + GumDubbleBubble.GetName());

    Box.drawBox(-1, boxItems);
    system("pause");
    return;
}

void Tycoon::PrintShop()
{
    ClearScreen();
    std::string priceText = "/per ";

    boxItems.clear();
    boxItems.push_back("Shop || Money: " + currency + Box.toString(money));
    boxItems.push_back(Box.div);
    boxItems.push_back("BULK: 50+ for 10% off, 100+ for 20% off!");
    boxItems.push_back(""); // line break

    boxItems.push_back("== Chocolate ==");
    boxItems.push_back("1. " + currency + ChocolateNut.SGetBuyPrice() + priceText + ChocolateNut.GetName() + " (have " + ChocolateNut.SGetQuantity() + ")");
    boxItems.push_back("2. " + currency + ChocolateBar.SGetBuyPrice() + priceText + ChocolateBar.GetName() + " (have " + ChocolateNut.SGetQuantity() + ")");
    boxItems.push_back(""); // line break
    boxItems.push_back("== Sour Candy ==");
    boxItems.push_back("3. " + currency + SourSoother.SGetBuyPrice() + priceText + SourSoother.GetName() + " (have " + SourSoother.SGetQuantity() + ")");
    boxItems.push_back("4. " + currency + SourFuzzyPeach.SGetBuyPrice() + priceText + SourFuzzyPeach.GetName() + " (have " + SourFuzzyPeach.SGetQuantity() + ")");
    boxItems.push_back("5. " + currency + SourPatchKids.SGetBuyPrice() + priceText + SourPatchKids.GetName() + " (have " + SourPatchKids.SGetQuantity() + ")");
    boxItems.push_back(""); // line break
    boxItems.push_back("== Gummy Candy ==");
    boxItems.push_back("6. " + currency + GummyBear.SGetBuyPrice() + priceText + GummyBear.GetName() + " (have " + GummyBear.SGetQuantity() + ")");
    boxItems.push_back("7. " + currency + GummyWorm.SGetBuyPrice() + priceText + GummyWorm.GetName() + " (have " + GummyWorm.SGetQuantity() + ")");
    boxItems.push_back(""); // line break
    boxItems.push_back("== Gum ==");
    boxItems.push_back("8. " + currency + GumSpearmint.SGetBuyPrice() + priceText + GumSpearmint.GetName() + " (have " + GumSpearmint.SGetQuantity() + ")");
    boxItems.push_back("9. " + currency + GumDubbleBubble.SGetBuyPrice() + priceText + GumDubbleBubble.GetName() + " (have " + GumDubbleBubble.SGetQuantity() + ")");

    /* possible change: shows sell price, but maybe it's better for the players to figure that out for themselves?
    boxItems.push_back("1. " + ChocolateNut.GetName() + " (have " + ChocolateNut.SGetQuantity() + ")");
    boxItems.push_back("     Buy: " + currency + ChocolateNut.SGetBuyPrice() + priceText + "Sell: " + currency + ChocolateNut.SGetSellPrice() + priceText);
    */

    boxItems.push_back(""); // line break
    boxItems.push_back("What would you like to buy?");
    boxItems.push_back("    0. Exit store");

    Box.drawBox(-1, boxItems);
    return;
}

bool Tycoon::GetShopInput()
{
    int shopMenuChoice = 0;

    while (true)
    {
        std::cout << ">> ";
        std::cin >> shopMenuChoice;
        std::cout << '\n';

        if (!std::cin.good() || (shopMenuChoice < 0 || shopMenuChoice > 9)) {
            std::cout << "Invalid input. Must choose an item from 1-9 or 0 to exit shop. \n" << std::endl;
            std::cin.clear();
            std::cin.ignore(128, '\n');
        } else {
            break;
        }
    }

    if (shopMenuChoice == 0) { return false; }

    /*
     * user chooses item
     * ask for amount they want
     * error check to make sure they have sufficient funds
     * then confirm with price to buy or not
     * loop back.
    */

    /* std::map<int, std::string> candyMap{ {1, "ChocolateNut"} };
    std::cout << candyMap[1].GetName() << std::endl; */

    std::cout << "How many would you like to buy?" << std::endl;

    int purchaseAmount = 0;
    while (true)
    {
        std::cout << ">> ";
        std::cin >> purchaseAmount;
        std::cout << '\n';

        if (!std::cin.good() || (purchaseAmount < 0)) {
            std::cout << "Invalid input. Must be a positive number. \n" << std::endl;
            std::cin.clear();
            std::cin.ignore(128, '\n');
        } else {
            break;
        }
    }

    switch (shopMenuChoice) {
    case 1:
        if ( ValidPurchase(ChocolateNut.IGetBuyPrice(), purchaseAmount, ChocolateNut.GetName()) ) {
            money -= (ChocolateNut.IGetBuyPrice() * purchaseAmount);
            ChocolateNut.AddQuantity(purchaseAmount);
        } break;
    case 2:
        if ( ValidPurchase(ChocolateBar.IGetBuyPrice(), purchaseAmount, ChocolateBar.GetName()) ) {
            money -= (ChocolateBar.IGetBuyPrice() * purchaseAmount);
            ChocolateBar.AddQuantity(purchaseAmount);
        } break;
    case 3:
        if ( ValidPurchase(SourSoother.IGetBuyPrice(), purchaseAmount, SourSoother.GetName()) ) {
            money -= (SourSoother.IGetBuyPrice() * purchaseAmount);
            SourSoother.AddQuantity(purchaseAmount);
        } break;
    case 4:
        if ( ValidPurchase(SourFuzzyPeach.IGetBuyPrice(), purchaseAmount, SourFuzzyPeach.GetName()) ) {
            money -= (SourFuzzyPeach.IGetBuyPrice() * purchaseAmount);
            SourFuzzyPeach.AddQuantity(purchaseAmount);
        } break;
    case 5:
        if ( ValidPurchase(SourPatchKids.IGetBuyPrice(), purchaseAmount, SourPatchKids.GetName()) ) {
            money -= (SourPatchKids.IGetBuyPrice() * purchaseAmount);
            SourPatchKids.AddQuantity(purchaseAmount);
        } break;
    case 6:
        if ( ValidPurchase(GummyBear.IGetBuyPrice(), purchaseAmount, GummyBear.GetName()) ) {
            money -= (GummyBear.IGetBuyPrice() * purchaseAmount);
            GummyBear.AddQuantity(purchaseAmount);
        } break;
    case 7:
        if ( ValidPurchase(GummyWorm.IGetBuyPrice(), purchaseAmount, GummyWorm.GetName()) ) {
            money -= (GummyWorm.IGetBuyPrice() * purchaseAmount);
            GummyWorm.AddQuantity(purchaseAmount);
        } break;
    case 8:
        if ( ValidPurchase(GumSpearmint.IGetBuyPrice(), purchaseAmount, GumSpearmint.GetName()) ) {
            money -= (GumSpearmint.IGetBuyPrice() * purchaseAmount);
            GumSpearmint.AddQuantity(purchaseAmount);
        } break;
    case 9:
        if ( ValidPurchase(GumDubbleBubble.IGetBuyPrice(), purchaseAmount, GumDubbleBubble.GetName()) ) {
            money -= (GumDubbleBubble.IGetBuyPrice() * purchaseAmount);
            GumDubbleBubble.AddQuantity(purchaseAmount);
        } break;
    }

    system("pause");
    return true;
}

bool Tycoon::ValidPurchase(int candyPrice, int amount, std::string candyName)
{
    // check if can afford
    if ((candyPrice * amount) > money) {
        std::cout << "INSUFFICIENT FUNDS. " << candyName << " costs " << currency << candyPrice * amount
            << ", but you only have " << currency << money << "!" << std::endl;
        std::cout << "\tCancelling transaction. \n" << std::endl;
        return false;
    } else {
        boxItems.clear();
        boxItems.push_back("CONFIRM: Are you sure you want to buy this?");
        boxItems.push_back(" ~ " + Box.toString(amount) + ' ' + candyName + " for " + currency + Box.toString(candyPrice * amount) + " @ " + currency + Box.toString(candyPrice) + " each.");
        boxItems.push_back(""); // line break
        boxItems.push_back("0. Cancel, I changed my mind!");
        boxItems.push_back("1. Confirm purchase");
        Box.drawBox(-1, boxItems);

        int purchaseConfirm = 0;
        while (true)
        {
            std::cout << ">> ";
            std::cin >> purchaseConfirm;
            std::cout << '\n';

            if (!std::cin.good() || (purchaseConfirm != 0 && purchaseConfirm != 1)) {
                std::cout << "Invalid input. Must choose 0 or 1. \n" << std::endl;
                std::cin.clear();
                std::cin.ignore(128, '\n');
            } else {
                break;
            }
        }

        if (purchaseConfirm == 0) {
            std::cout << "Cancelled, nothing was spent." << std::endl;
            return false;
        } else {
            std::cout << "Purchase complete! Lost " << currency << (candyPrice * amount) << '.' << std::endl;
            return true;
        }
    }
}

void Tycoon::PlayDay()
{
    day++;
    return;
}
