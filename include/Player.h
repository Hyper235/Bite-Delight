//
// Created by Catalin on 10/29/2025.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <string>
#include <queue>
#include "Order.h"
#include <string>
class Player {
protected:
     std::string name;
     float balance;
     std::queue<Order> orders;
public:
     Player();
     Player(const std::string& n, float balance);
     //getters
     std::string getName() const{return name;}
     float getBalance() const{return balance;}
     //setter
     void setBalance(float b){balance=b;}
     void addOrder(Order o){orders.push(o);}
     void setName(std::string n){name=n;}
     //adder
     void addBalance(float b){balance+=b;}
     // <<
     friend std::ostream& operator<<(std::ostream& os, const Player& p);
     //altele
     void placeOrder(const Order& order);
     void finishOrder();


};
#endif //OOP_PLAYER_H