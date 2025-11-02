//
// Created by Catalin on 11/2/2025.
//

#ifndef OOP_CUSTOMER_H
#define OOP_CUSTOMER_H
#include <vector>
#include <string>
#include "Order.h"
#include "FoodItem.h"

class Customer {
private:
    std::string Name;
    Order order;
    Order generateRandomOrder(const std::vector<FoodItem>& menu);
    std::string generateRandomName();
public:
    Customer(const std::vector<FoodItem>& m);
    friend std::ostream& operator<<(std::ostream& os, const Customer& c);
    ~Customer(){};
    Customer(const Customer& alt);
    Customer& operator=(const Customer& other);

};
#endif //OOP_CUSTOMER_H