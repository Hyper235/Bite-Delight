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
    //implicit
    Customer();

    //parametric cu meniu
    explicit Customer(const std::vector<FoodItem>& m);

    //parametric cu toti parametrii
    Customer(const std::string& n, const Order& o);

    //copiere
    Customer(const Customer& alt);

    //<<
    friend std::ostream& operator<<(std::ostream& os, const Customer& c);

    //=
    Customer& operator=(const Customer& other);

    //getters
    [[maybe_unused]]Order& getOrder() {
        return order;
    }
   [[maybe_unused]]const std::string& getName() const {return Name;}

    //destructor
    ~Customer(){std::cout<<"\nDestructor call: CUSTOMER "<<Name<<"\n";}
};
#endif //OOP_CUSTOMER_H