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
    Order(); //implicit
    Order(unsigned int i,
                 float tipsAmount,
                 Dif diff,
                 unsigned int maxSec = 60,
                 const std::vector<FoodItem>& itemsList = {});
    void addItemToOrder(const FoodItem& it);
    [[nodiscard]] float calc()const;
    //setters
    void setTips(unsigned int t){tips=t;}
    void setDifficulty(Dif d){difficulty=d;}
    void setMaxDuration(unsigned int seconds){maxDuration=std::chrono::seconds(seconds);}
    //getters
    [[nodiscard]]float getTips() const{return tips;}
    [[nodiscard]]unsigned int getID() const{return id;}
    std::chrono::system_clock::time_point getTimestamp() const { return timestamp; }
    std::chrono::seconds getMaxDuration() const { return maxDuration; }
    //adders
    void addTips(float t){tips+=t;}
    friend std::ostream& operator<<(std::ostream& os, const Order& o);
    [[nodiscard]] bool hasExpired() const;
    //reset
    static void resetIDs();
};
#endif //OOP_ORDER_H