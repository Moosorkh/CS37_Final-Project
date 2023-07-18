#include <iostream>
#include <iomanip>
#include "account.h"
#include "delivery_order.h"
#include "boba_order.h"
#include "food_order.h"
#include "invalid_input.h"

void applyDiscount(DeliveryOrder *order, const Account &account)
{
    std::string accountType = account.getType();
    float discount = accountType == "VIP" ? order->VIPdiscount() : 0.0f;
    std::cout << "Applied " << discount * 100 << "% discount for " << account.getName() << "\n";
    order->setOrderBalance(order->getOrderBalance() * (1 - discount));
}

int main()
{
    Account owner("Stuart", "Owner");
    Account vip("Kevin", "VIP");
    Account regular("Bob");

    DeliveryOrder *order = nullptr;
    DeliveryOrder *orderCopy = nullptr; // To store copy of Stuart's order for Bob

    std::cout << "Kevin placing order.\n";

    try
    {
        order = new BobaOrder("Kevin", "11/20/2022", "123-456-0000", 10.4, "M Tea");
        order->addDrink("Green Tea Latte");
        order->addDrink("Brown Sugar Pearl Milk", false);
        order->addDrink("Brown Sugar Boba Milk", false);
        order->addDrink("Iron Goddess");
    }
    catch (const InvalidInput &e)
    {
        std::cout << "Invalid input \"" << e.what() << "\".\n";
        std::cout << "Not serving requested drinks. Drink order ignored.\n\n";
    }

    if (order)
    {
        order->receipt();
        float totalBalance = order->getTotalBalance();
        std::cout << "Balance: $" << std::fixed << std::setprecision(2) << totalBalance << std::endl;
        applyDiscount(order, vip);
        delete order;
        order = nullptr;
    }

    std::cout << "\nStuart placing order.\n";

    try
    {
        order = new FoodOrder("Stuart", "11/20/2022", "123-456-1111", 25.5, "Tavern Green");
        order->addFood("Thick Cauliflower Steaks", 1, true);
        order->addFood("Organic Scottish Salmon");
        order->addFood("Rack of Lamb", 0, false);

        // Copy Stuart's order for Bob
        orderCopy = new FoodOrder(*dynamic_cast<FoodOrder *>(order));
    }
    catch (const InvalidInput &e)
    {
        std::cout << "Not serving requested food. Food order ignored.\n\n";
        e.print_reason();
    }

    if (order)
    {
        order->receipt();
        float totalBalance = order->getTotalBalance();
        std::cout << "Balance: $" << std::fixed << std::setprecision(2) << totalBalance << std::endl;
        applyDiscount(order, regular);
        delete order;
        order = nullptr;
    }

    std::cout << "\nBob decided to log in to his account and see whether he can afford ordering the same order as Stuart.\n";

    if (orderCopy)
    {
        orderCopy->receipt();
        float totalBalance = orderCopy->getTotalBalance();
        std::cout << "Balance: $" << std::fixed << std::setprecision(2) << totalBalance << std::endl;
        applyDiscount(orderCopy, regular);
        std::cout << "Bob upset, cancelling order :(\n\n";
        delete orderCopy;
    }

    std::cout << "Total order placed: " << DeliveryOrder::getOrderCount() << ".\n\n";

    return 0;
}
