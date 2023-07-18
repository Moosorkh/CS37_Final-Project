// DeliveryOrder.cpp
#include "DeliveryOrder.h"
#include <iostream>
#include <iomanip>

int DeliveryOrder::orderCount = 0;

DeliveryOrder::DeliveryOrder(std::string name, std::string date, std::string phone, float miles)
    : name(name), date(date), phone(phone), miles(miles), orderBalance(0.0f)
{
    orderCount++;
}

DeliveryOrder::~DeliveryOrder()
{
    std::cout << "DeliveryOrder destroyed.\n";
}

void DeliveryOrder::receipt() const
{
    std::cout << "Order Detail:\n";
    std::cout << "\tName: " << name << "\n";
    std::cout << "\tDate: " << date << "\n";
    std::cout << "\tPhone: " << phone << "\n";
    std::cout << "\tOrder Balance: $" << std::fixed << std::setprecision(2) << orderBalance << std::endl;
}

float DeliveryOrder::getTotalBalance() const
{
    return orderBalance * (1 + taxRate) + miles * deliveryRate;
}

int DeliveryOrder::getOrderCount()
{
    return orderCount;
}
