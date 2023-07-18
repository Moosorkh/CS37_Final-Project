// DeliveryOrder.h
#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

#include <string>

class DeliveryOrder
{
private:
    std::string name;
    std::string date;
    std::string phone;
    float miles;

protected:
    float orderBalance;

private:
    static int orderCount;
    static constexpr float taxRate = 0.09f;
    static constexpr float deliveryRate = 1.5f;

public:
    DeliveryOrder(std::string name, std::string date, std::string phone, float miles);
    virtual ~DeliveryOrder();
    void receipt() const;
    float getTotalBalance() const;
    static int getOrderCount();
    virtual float VIPdiscount() const = 0; // pure virtual function
};

#endif