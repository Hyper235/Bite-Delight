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
    static Order generateRandomOrder(const std::vector<FoodItem>& menu);
    static std::string generateRandomName();
public:
    explicit Customer(const std::vector<FoodItem>& m);
    Customer(const std::string& n, const Order& o);
    friend std::ostream& operator<<(std::ostream& os, const Customer& c);
    ~Customer(){}; //destructor
    Customer(const Customer& alt);//copiere
    Customer& operator=(const Customer& other); // =
    //getters
    Order& getOrder() {
        return order;
    }
    const std::string& getName() const {return Name;}

};
#endif //OOP_CUSTOMER_H