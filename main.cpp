#include <iostream>
#include <array>

//include extern
#include <bits/regex_constants.h>
#include <queue>
#include "include/FoodItem.h"
#include "include/Order.h"
#include "include/Player.h"
#include "include/Functions.h"
#include "include/Customer.h"

int main() {
//  define fooditems
    std::vector<FoodItem> menu = {
        FoodItem(1, "Pizza", 10.5f, FoodType::FOOD),
        FoodItem(2, "Burger", 8.0f, FoodType::FOOD),
        FoodItem(3, "Fries", 3.5f, FoodType::FOOD),
        FoodItem(4, "Soda", 2.0f,FoodType::DRINK)
    };
    Player player("Catalin", 100.0f);
    Customer customer(menu);
    std::cout<<customer;
    return 0;
}
