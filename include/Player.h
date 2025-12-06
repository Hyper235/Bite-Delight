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
     [[maybe_unused]]void setBalance(float b){balance=b;}
     [[maybe_unused]]void addOrder(const Order& o){orders.push(o);}
     [[maybe_unused]]void setName(const std::string& n){name=n;}
     [[maybe_unused]]void SetCurrentStation(std::size_t index) {
          currentStation = index;
     }
     [[maybe_unused]]void setDays(unsigned int d) {
          days=d;
     }
     //adder
     [[maybe_unused]]void addBalance(float b){balance+=b;}
     // <<
     friend std::ostream& operator<<(std::ostream& os, const Player& p);
     //altele
     [[maybe_unused]]void placeOrder(const Order& order);
     [[maybe_unused]]void finishOrder();

};
#endif //OOP_PLAYER_H