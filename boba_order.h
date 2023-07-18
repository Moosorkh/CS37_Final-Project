// BobaOrder.h
#ifndef BOBAORDER_H
#define BOBAORDER_H

#include "DeliveryOrder.h"
#include <string>

class BobaOrder : public DeliveryOrder
{
private:
    std::string shopName;
    int drinksCount;

public:
    BobaOrder(std::string name, std::string date, std::string phone, float miles, std::string shopName);
    ~BobaOrder();
    void receipt() const override;
    float VIPdiscount() const override;
    void addDrink(std::string drinkName, bool addBoba = true, int count = 1);
};

#endif
