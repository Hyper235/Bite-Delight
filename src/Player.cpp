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
    os << "Player: " << p.getName() << "\n";
    os << "  Balance: " << p.getBalance() << " RON\n";
    os << "  Pending Orders (" << p.orders.size() << "):\n";

    std::queue<Order> q = p.orders;

    if (q.empty()) {
        os << "    [No pending orders]\n";
    } else {
        int count = 1;
        while (!q.empty()) {
            os << "    --- Order #" << count++ << " ---\n";
            os << q.front();
            q.pop();
        }
    }
    return os;
}
void Player::placeOrder(const Order& o){orders.push(o);}

void Player::finishOrder() {
    Order& currentOrder = orders.front();
    float basePrice= currentOrder.calc();
    auto now = std::chrono::system_clock::now();
    auto timestamp = currentOrder.getTimestamp();
    auto maxDuration = currentOrder.getMaxDuration();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - timestamp);
    float timeRatio = static_cast<float>(elapsed.count()) / static_cast<float>(maxDuration.count());
    float tipAmount = 0.0f;

    if (timeRatio < 0.3f) {
        tipAmount = basePrice * 0.20f;
    } else if (timeRatio < 0.8f) {
        tipAmount = basePrice * 0.05f;
    } else {
        tipAmount = 0.0f;
    }
    currentOrder.setTips(tipAmount);

    this->balance+=tipAmount +basePrice;
    std::cout << "Player " << getName() << " finished order ID " << currentOrder.getID()<< " in " << elapsed.count() << " seconds, with TIPS: " << tipAmount << "\n";
    orders.pop();
}

