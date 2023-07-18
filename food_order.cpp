#include "food_order.h"
#include "invalid_input.h"
#include <iostream>
#include <iomanip>

FoodOrder::FoodOrder(const std::string &name, const std::string &date, const std::string &phone, float miles, const std::string &restaurant)
    : DeliveryOrder(name, date, phone, miles), restaurantName(restaurant), foodCount(0)
{
}

FoodOrder::~FoodOrder()
{
    std::cout << "FoodOrder destroyed.\n";
}

const std::string &FoodOrder::getRestaurantName() const
{
    return restaurantName;
}

int FoodOrder::getFoodCount() const
{
    return foodCount;
}

void FoodOrder::addFood(const std::string &meal, int sides, bool addSoup) noexcept(false)
{
    float cost = 0.0;
    if (meal == "Thick Cauliflower Steaks")
    {
        cost = 15.0 + (6.0 * sides) + (addSoup ? 5.0 : 0.0);
    }
    else if (meal == "Rack of Lamb")
    {
        cost = 38.0 + (6.0 * sides) + (addSoup ? 5.0 : 0.0);
    }
    else if (meal == "Organic Scottish Salmon")
    {
        cost = 23.0 + (6.0 * sides) + (addSoup ? 5.0 : 0.0);
    }
    else if (meal == "Grilled Lobster Risotto")
    {
        cost = 46.0 + (6.0 * sides) + (addSoup ? 5.0 : 0.0);
    }
    else
    {
        throw InvalidInput(meal);
    }

    foodCount++;
    setOrderBalance(getOrderBalance() + cost);
}

float FoodOrder::VIPdiscount() const
{
    float balance = getTotalBalance();
    if (balance > 50.0)
    {
        return 0.85;
    }
    else if (balance > 30.0)
    {
        return 0.9;
    }
    else if (balance > 20.0)
    {
        return 0.95;
    }
    return 1.0;
}

void FoodOrder::receipt() const
{
    std::cout << "\nOrder Detail:" << std::endl;
    std::cout << "\tName: " << customerName << std::endl;
    std::cout << "\tDate: " << date << std::endl;
    std::cout << "\tPhone: " << phone << std::endl;
    std::cout << "\tOrder Balance: $" << std::fixed << std::setprecision(2) << orderBalance << std::endl;
    std::cout << "\tFood Count: " << foodCount << std::endl;
    std::cout << "Balance: $" << std::fixed << std::setprecision(2) << getTotalBalance() << std::endl;
    std::cout << "Discounted Balance: $" << std::fixed << std::setprecision(2) << getTotalBalance() * (1 - VIPdiscount()) << std::endl;
}