//
// Created by Catalin on 10/29/2025.
//
#include "../include/Player.h"
#include "../include/Order.h"
#include <queue>
//implicit
Player::Player():name("NULL"), balance(0.0f){}
//parametric
Player::Player(const std::string &n, float balance): name(n), balance(balance){}
// <<
std::ostream& operator<<(std::ostream& os, const Player& p) {
    std::queue<Order> q = p.orders;
    return os;
}

void Player::placeOrder(const Order& o){orders.push(o);}
void Player::finishOrder(){orders.pop();}

