//
// Created by Catalin on 10/29/2025.
//

#ifndef OOP_ORDER_H
#define OOP_ORDER_H
#include <vector>
#include <chrono>
#include "FoodItem.h"
enum class Dif {EASY,MEDIUM,HARD};
class Order {
private:
    static unsigned int nextId;
    unsigned int id;
    float tips;
    Dif difficulty;
    std::vector<FoodItem> items;
    std::chrono::system_clock::time_point timestamp = std::chrono::system_clock::now();
    std::chrono::seconds maxDuration;
public:
    //implicit
    Order();

    //parametric
    Order(unsigned int i,float tipsAmount,Dif diff,unsigned int maxSec,const std::vector<FoodItem>& itemsList = {});


    //setters
    [[maybe_unused]]void setTips(unsigned int t){tips=t;}
    [[maybe_unused]]void setDifficulty(Dif d){difficulty=d;}
    [[maybe_unused]]void setMaxDuration(unsigned int seconds){maxDuration=std::chrono::seconds(seconds);}


    //getters
    [[maybe_unused]][[nodiscard]]float getTips() const{return tips;}
    [[maybe_unused]][[nodiscard]]unsigned int getID() const{return id;}
    [[maybe_unused]]std::chrono::system_clock::time_point getTimestamp() const { return timestamp; }
    [[maybe_unused]]std::chrono::seconds getMaxDuration() const { return maxDuration; }

    //adders
    [[maybe_unused]]void addItemToOrder(const FoodItem& it);
    [[maybe_unused]]void addTips(float t){tips+=t;}

    //<<
    friend std::ostream& operator<<(std::ostream& os, const Order& o);

    //others
    [[maybe_unused]][[nodiscard]] bool hasExpired() const;
    [[maybe_unused]][[nodiscard]] float calc()const;
    [[maybe_unused]]static void resetIDs();
};
#endif //OOP_ORDER_H