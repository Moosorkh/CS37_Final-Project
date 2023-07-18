// bobaorder.cpp
#include "bobaorder.h"
#include <iostream>

using namespace std;

BobaOrder::BobaOrder(const string &name, const string &date, const string &phone, float miles, const string &shopName)
    : DeliveryOrder(name, date, phone, miles), shopName(shopName)
{
    drinkCount = 0;
    cout << "BobaOrder created." << endl;
}

BobaOrder::~BobaOrder()
{
    cout << "BobaOrder destroyed." << endl;
}

void BobaOrder::addDrink(const string &drink, bool addPearls)
{
    float drinkPrice = 0;
    if (drink == "Green Tea Latte")
        drinkPrice = 5;
    else if (drink == "Brown Sugar Pearl Milk")
        drinkPrice = 6;
    else if (drink == "Iron Goddess")
        drinkPrice = 4;
    else
        throw InvalidInput(drink);

    drinkCount++;
    orderBalance += drinkPrice + (addPearls ? 1 : 0);
}

float BobaOrder::VIPdiscount() const
{
    if (orderBalance > 20)
        return 0.9;
    else if (orderBalance > 10)
        return 0.95;
    else
        return 1;
}

void BobaOrder::receipt() const
{
    std::cout << "\nOrder Detail:" << std::endl;
    std::cout << "\tName: " << customerName << std::endl;
    std::cout << "\tDate: " << date << std::endl;
    std::cout << "\tPhone: " << phone << std::endl;
    std::cout << "\tOrder Balance: $" << std::fixed << std::setprecision(2) << orderBalance << std::endl;
    std::cout << "\tDrinks Count: " << drinksCount << std::endl;
    std::cout << "Balance: $" << std::fixed << std::setprecision(2) << getTotalBalance() << std::endl;
    std::cout << "Discounted Balance: $" << std::fixed << std::setprecision(2) << getTotalBalance() * (1 - VIPdiscount()) << std::endl;
}