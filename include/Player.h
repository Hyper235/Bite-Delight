//
// Created by Catalin on 10/29/2025.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <string>
#include <queue>
#include "Order.h"
class Player {
protected:
     std::string name;
     float balance;
     std::queue<Order> orders;
     std::size_t currentStation = 0;
     unsigned int days;

public:
     Player();//constructor implicit
     Player(const std::string& n, float balance); //parametric
     //getters
     const std::string& getName() const { return name; }
     float getBalance() const{return balance;}
     [[nodiscard]] size_t getOrderCount() const { return orders.size(); }
     const std::queue<Order>& getOrders() const {return orders;}
     std::queue<Order>& getOrders() {return orders;}
     std::size_t getCurrentStation() const {
          return currentStation;
     }
     //setter
     void setBalance(float b){balance=b;}
     void addOrder(const Order& o){orders.push(o);}
     void setName(const std::string& n){name=n;}
     void SetCurrentStation(std::size_t index) {
          currentStation = index;
     }
     void setDays(unsigned int d) {
          days=d;
     }
     //adder
     void addBalance(float b){balance+=b;}
     // <<
     friend std::ostream& operator<<(std::ostream& os, const Player& p);
     //altele
     void placeOrder(const Order& order);
     void finishOrder();

};
#endif //OOP_PLAYER_H