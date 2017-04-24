#include "../include/Tycoon.h"

Tycoon::Tycoon() { Reset(); }
Tycoon::~Tycoon() { /*dtor*/ }

void Tycoon::Reset()
{
    boxItems.clear();

    day = 1;
    money = 100; // default is 100 .. all money is in cents!
    bullyMoney = 0;
    currency = '$';

    dayIncome = 0;

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

    // push candy pointers to candyList
    Candy *candyArray[] = {
        &ChocolateNut,   // 0
        &ChocolateBar,   // 1
        &SourSoother,    // 2
        &SourFuzzyPeach, // 3
        &SourPatchKids,  // 4
        &GummyBear,      // 5
        &GummyWorm,      // 6
        &GumSpearmint,   // 7
        &GumDubbleBubble // 8
    };

    candyList.clear();
    for (int i = 0; i < sizeof(candyArray) / sizeof(candyArray[0]); i++) {
        candyList.push_back(candyArray[i]);
        //std::cout << "Element " << i << " of candyList: " << candyList[i]->GetName() << std::endl;
    }

    // Push upgrade pointers to upgradesList
    Upgrade *upgradesArray[] = {
        &Backpack,   // 0
        &DuffleBag,   // 1
    };

    upgradesList.clear();
    for (int i = 0; i < sizeof(upgradesArray) / sizeof(upgradesArray[0]); i++) {
        upgradesList.push_back(upgradesArray[i]);
        //std::cout << "Element " << i << " of candyList: " << candyList[i]->GetName() << std::endl;
    }

    // Upgrades
    Backpack.SetId("BACKPACK");
    DuffleBag.SetId("DUFFLEBAG");
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
    boxItems.push_back("1. View inventory");
    boxItems.push_back("2. Go to the store");
    boxItems.push_back("3. View upgrades");
    boxItems.push_back("4. Start the day");
    boxItems.push_back(""); // line break
    boxItems.push_back("0. Exit game");
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

        if (!std::cin.good() || (userChoice < 0 || userChoice > 4)) {
            std::cout << "Invalid input. Must choose from 1-4 or 0. \n" << std::endl;
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
    boxItems.push_back("Inventory || Money: " + currency + Box.centsToString(money));
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
    boxItems.push_back("Shop || Money: " + currency + Box.centsToString(money));
    boxItems.push_back(Box.div);
    boxItems.push_back("BULK: 50+ for 10% off, 100+ for 20% off!");
    boxItems.push_back(""); // line break

    boxItems.push_back("== Chocolate ==");
    boxItems.push_back("1. " + currency + ChocolateNut.SGetBuyPrice() + priceText + ChocolateNut.GetName() + " (have " + ChocolateNut.SGetQuantity() + ")");
    boxItems.push_back("2. " + currency + ChocolateBar.SGetBuyPrice() + priceText + ChocolateBar.GetName() + " (have " + ChocolateBar.SGetQuantity() + ")");
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
    boxItems.push_back("What would you like to do?");
    boxItems.push_back("    1-9. Buy item");
    boxItems.push_back("    0. Exit shop");

    Box.drawBox(-1, boxItems);
    return;
}

bool Tycoon::GetShopInput() // TODO: bulk discounts
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

    /*
     * If the user can afford the item -> ValidPurchase(price, amount, name);
     *      remove money according to the buy price * buy amount
     *      add quantity bought to inventory
    */
    int candyIndex = shopMenuChoice - 1;
    if ( ValidPurchase(candyList[candyIndex]->IGetBuyPrice(), purchaseAmount, candyList[candyIndex]->GetName()) ) {
            money -= (candyList[candyIndex]->IGetBuyPrice() * purchaseAmount);
            candyList[candyIndex]->AddQuantity(purchaseAmount);
    }

    system("pause");
    return true;
}

bool Tycoon::ValidPurchase(int candyPrice, int amount, std::string candyName)
{
    // check if can afford
    if ((candyPrice * amount) > money) {
        std::cout << "INSUFFICIENT FUNDS. " << candyName << " costs " << currency << Box.centsToString(candyPrice * amount)
            << ", but you only have " << currency << Box.centsToString(money) << "!" << std::endl;
        // std::cout << "\tCancelling transaction. \n" << std::endl;
        return false;
    } else {
        boxItems.clear();
        boxItems.push_back("CONFIRM: Are you sure you want to buy this?");
        boxItems.push_back(" ~ " + Box.toString(amount) + ' ' + candyName + " for " + currency + Box.centsToString(candyPrice * amount) + " @ " + currency + Box.centsToString(candyPrice) + " each.");
        boxItems.push_back(""); // line break
        boxItems.push_back("1. Yes, buy!");
        boxItems.push_back("0. No, cancel");
        Box.drawBox(-1, boxItems);

        int purchaseConfirm = 0;
        while (true)
        {
            std::cout << ">> ";
            std::cin >> purchaseConfirm;
            std::cout << '\n';

            if (!std::cin.good() || (purchaseConfirm != 0 && purchaseConfirm != 1)) {
                std::cout << "Invalid input. Must choose 1 or 0. \n" << std::endl;
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
            std::cout << "Purchase complete! Lost " << currency << Box.centsToString(candyPrice * amount) << '.' << std::endl;
            return true;
        }
    }
}

void Tycoon::PrintUpgrades()
{
    std::string separator = " | ";
    std::string menuTab = "    ";

    ClearScreen();
    boxItems.clear();
    boxItems.push_back("Upgrades || Money: " + currency + Box.centsToString(money));
    //boxItems.push_back(""); // line break
    boxItems.push_back(Box.div + " Supply " + Box.div);
    boxItems.push_back("1. " + Backpack.SGetHaveUpgrade() + separator + Backpack.SGetName());
    boxItems.push_back(menuTab + Backpack.SGetDescription());
    boxItems.push_back("");
    boxItems.push_back("2. " + DuffleBag.SGetHaveUpgrade() + separator + DuffleBag.SGetName());
    boxItems.push_back(menuTab + DuffleBag.SGetDescription());
    boxItems.push_back(""); // line break
    boxItems.push_back("What would you like to do?");
    boxItems.push_back(menuTab + "1-2. Buy upgrade (if not already owned)");
    boxItems.push_back(menuTab + "0. Exit upgrade shop");

    Box.drawBox(-1, boxItems);
    return;
}

bool Tycoon::GetUpgradesInput()
{
    int upgradeMenuChoice = 0;

    while (true)
    {
        std::cout << ">> ";
        std::cin >> upgradeMenuChoice;
        std::cout << '\n';

        if (!std::cin.good() || (upgradeMenuChoice < 0 || upgradeMenuChoice > 2)) {
            std::cout << "Invalid input. Must choose an item from 1-2 or 0 to exit shop. \n" << std::endl;
            std::cin.clear();
            std::cin.ignore(128, '\n');
        } else {
            break;
        }
    }

    if (upgradeMenuChoice == 0) { return false; }

    // BEGIN purchase item algorithm with error checking
    int purchaseChoice = upgradeMenuChoice - 1;
    int purchaseAmount = 1;
    bool alreadyOwnUpgrade = upgradesList[purchaseChoice]->BGetHaveUpgrade();

    std::cout << "thing: " << upgradesList[purchaseChoice] << std::endl;
    // std::cout << "have prereq: " << HaveUpgradePrereq[upgradesList[purchaseChoice]] << std::endl;
    //bool havePrerequisite = HaveUpgradePrereq[upgradesList[purchaseChoice]];
    bool havePrerequisite = false;

    if (alreadyOwnUpgrade) {
        std::cout << "You already own that upgrade!" << std::endl;
        system("pause");
        return true;
    } else if (!havePrerequisite) {
        std::cout << "You don't have the prerequisite for that upgrade!" << std::endl;
        system("pause");
        return true;
    }

    if ( ValidPurchase(upgradesList[purchaseChoice]->IGetBuyPrice(), purchaseAmount, upgradesList[purchaseChoice]->SGetName()) ) {
        money -= upgradesList[purchaseChoice]->IGetBuyPrice();
        upgradesList[purchaseChoice]->SetOwnership();
    }

    system("pause");
    return true;
}

bool Tycoon::HaveUpgradePrereq(Upgrade *currentUpgrade)
{
    std::cout << currentUpgrade->SGetName();
    return false;
}

/* DAY ================================================ */
bool Tycoon::PlayDay()
{
    day++;

    // chance for teacher to patrol
        // choice: continue selling for 3x bonus (risk), forfeit to end day (safe)
    DayPatrol();

    // customers buy candy
        // demand for a type of candy increases money earned from that type
    DayCustomers();

    ReportIncome();
    ReportTotalBullyTax();

    if (GameIsWon() || GameIsLost()) {
        EndGame();
        return false;
    }

    system("pause");
    return true;
}

void Tycoon::DayPatrol()
{

}

void Tycoon::DayCustomers()
{
    // TODO: random demand

    // buy from stock
        // add to money for each purchase
        // remove item from stock

    srand( unsigned(time(0)) );
    dayIncome = 0;

    for (int currentCandy = 0; currentCandy < CANDY_AMOUNT; currentCandy++) {
        int currentCandyStock = candyList[currentCandy]->IGetQuantity();

        if (currentCandyStock <= 4 && currentCandyStock > 0) {
            DayCustomersBuyCandy(candyList[currentCandy], currentCandyStock); // customers buy all the stock

        } else if (currentCandyStock > 4) {
            int buyMin = (int)(currentCandyStock / 3);
            int buyMax = currentCandyStock - 2;
            int randomBuyAmount = rand() % (buyMax - buyMin + 1) + buyMin;
            DayCustomersBuyCandy(candyList[currentCandy], randomBuyAmount);
        }
    }

    return;
}

void Tycoon::DayCustomersBuyCandy(Candy *currentCandy, int amountSold)
{
    int income = (currentCandy->IGetSellPrice() * amountSold);
    int tax = BullyTax(income);

    std::cout << currentCandy->GetName() << ": sold " << amountSold << " for " << currency << Box.centsToString(income) << std::endl;
    if (tax > 0) {
        std::cout << "    Lost " << currency << Box.centsToString(tax) << " to bully tax." << std::endl << std::endl;
    }

    currentCandy->RemoveQuantity(amountSold);
    money += income;
    dayIncome += income;

    return;
}

// Returns taxed money
int Tycoon::BullyTax(int moneyToTax)
{
    int tax = (int)(moneyToTax * 0.05);
    bullyMoney += tax;

    return tax;
}

void Tycoon::ReportTotalBullyTax()
{
    bullyMoney += 15; // daily income, so you can't just wait around

    std::cout << "Bully money: " << currency << Box.centsToString(bullyMoney) << std::endl;
    return;
}

void Tycoon::ReportIncome()
{
    std::cout << "Today's income: " << currency << Box.centsToString(dayIncome) << std::endl;
    return;
}


bool Tycoon::GameIsWon()
{
    if (money >= 50000000) {
        return true;
    }
    return false;
}

bool Tycoon::GameIsLost()
{
    return false;
}

void Tycoon::EndGame()
{
    ClearScreen();
    boxItems.clear();

    boxItems.push_back("=== GAME OVER. ====");
    if (GameIsWon()) {
        boxItems.push_back("Congratulations, you won! The legacy of your Candy Tycoon will live on forever.");
    } else {
        boxItems.push_back("Sorry, you lost. The legacy of Candy Tycoon will live on forever.");
    }

    boxItems.push_back(""); // line break
    boxItems.push_back("You finished with " + currency + Box.centsToString(money));
    boxItems.push_back("The bullies collected " + currency + Box.centsToString(bullyMoney));

    Box.drawBox(-1, boxItems);
}

bool Tycoon::AskToQuit()
{
    boxItems.clear();
    boxItems.push_back("Are you sure you want to quit? You will lose ALL of your progress!");
    boxItems.push_back(""); // line break;
    boxItems.push_back("1. Yes, quit the game AND lose my progress");
    boxItems.push_back("0. No, keep playing");
    Box.drawBox(68, boxItems);

    int quitConfirm = 0;
        while (true)
        {
            std::cout << ">> ";
            std::cin >> quitConfirm;
            std::cout << '\n';

            if (!std::cin.good() || (quitConfirm != 0 && quitConfirm != 1)) {
                std::cout << "Invalid input. Must choose 1 or 0. \n" << std::endl;
                std::cin.clear();
                std::cin.ignore(128, '\n');
            } else {
                if (quitConfirm) return true;
                else return false;
            }
        }
}
