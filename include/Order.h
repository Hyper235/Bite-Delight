//
// Created by Catalin on 10/29/2025.
//

#ifndef OOP_ORDER_H
#define OOP_ORDER_H
#include <string>
#include <FoodItem.h>
#include <vector>
#include <chrono>
#include "FoodItem.h"
enum class Dif {EASY,MEDIUM,HARD};
class Order {
private:
    static unsigned int nextId;
    unsigned int id;

    Dif difficulty;
    std::vector<FoodItem> items;
    std::chrono::system_clock::time_point timestamp = std::chrono::system_clock::now();
    std::chrono::seconds maxDuration;
public:
    Order();
    Order(unsigned int id,unsigned int maxSeconds=60);
    void addItemToOrder(const FoodItem& it);
    float calc()const;
    void setDifficulty(Dif d){difficulty=d;}
    void setMaxDuration(unsigned int seconds){maxDuration=std::chrono::seconds(seconds);}
    const std::vector<FoodItem>& getItems() const;
    friend std::ostream& operator<<(std::ostream& os, const Order& o);
    bool hasExpired() const;
};
#endif //OOP_ORDER_H