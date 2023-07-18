#ifndef FOOD_ORDER_H
#define FOOD_ORDER_H

#include "delivery_order.h"

class FoodOrder : public DeliveryOrder
{
private:
    std::string restaurantName;
    int foodCount;

public:
    FoodOrder(const std::string &name, const std::string &date, const std::string &phone, float miles, const std::string &restaurant);
    virtual ~FoodOrder();

    const std::string &getRestaurantName() const;
    int getFoodCount() const;

    void addFood(const std::string &meal, int sides = 0, bool addSoup = false) override;
    float VIPdiscount() const override;
    void receipt() const override;
};

#endif