//
// Created by Catalin on 10/29/2025.
//
// cppcheck-suppress-file unusedFunction
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
    std::vector<bool> prepared;
    std::chrono::system_clock::time_point timestamp = std::chrono::system_clock::now();
    std::chrono::seconds maxDuration;
    static unsigned int finishedOrders;
public:
    //implicit
    Order();

    //parametric
    Order(unsigned int i,float tipsAmount,Dif diff,unsigned int maxSec,const std::vector<FoodItem>& itemsList = {});


    //setters
    void setTips(unsigned int t){tips=t;}
    void setDifficulty(Dif d){difficulty=d;}
    void setMaxDuration(unsigned int seconds){maxDuration=std::chrono::seconds(seconds);}
    //getters
    [[nodiscard]]float getTips() const{return tips;}
    [[nodiscard]]unsigned int getID() const{return id;}
    std::chrono::system_clock::time_point getTimestamp() const { return timestamp; }
    std::chrono::seconds getMaxDuration() const { return maxDuration; }
    const std::vector<FoodItem>& getItems() const {
        return items;
    }

    //adders
    void addItemToOrder(const FoodItem& it);
    void addTips(float t){tips+=t;}

    //<<
    friend std::ostream& operator<<(std::ostream& os, const Order& o);

    //others
    [[nodiscard]] bool hasExpired() const;
    [[nodiscard]] float calc()const;
    bool registerPreparedItem(const FoodItem& preparedItem);
    bool isComplete() const;
};
#endif //OOP_ORDER_H