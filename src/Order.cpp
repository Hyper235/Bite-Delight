//
// Created by Catalin on 10/29/2025.
//
#include "../include/Order.h"
//implicit
unsigned int Order::nextId = 1;
//parametric

Order::Order()
    : id(nextId++),
      tips(0.0f),
      difficulty(Dif::EASY),
      timestamp(std::chrono::system_clock::now()),
      maxDuration(static_cast<std::chrono::seconds::rep>(0))
{}
Order::Order(unsigned int i,
             float tipsAmount,
             Dif diff,
             unsigned int maxSec,
             const std::vector<FoodItem>& itemsList)
    : id(i),
      tips(tipsAmount),
      difficulty(diff),
      items(itemsList),
      timestamp(std::chrono::system_clock::now()),
      maxDuration(static_cast<std::chrono::seconds::rep>(maxSec))
{}

//
void Order::addItemToOrder(const FoodItem &it) {
    items.push_back(it);
}
float Order::calc() const {
    float total=0.0f;
    for(const FoodItem& it: items) {
        total+=it.getPrice();
    }
    if (this->difficulty == Dif::HARD)total*=1.5f;
    else if (this->difficulty == Dif::MEDIUM)total*=1.3f;
    return total;
}
bool Order::hasExpired() const {
    auto now = std::chrono::system_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - this->timestamp);

    return elapsed > this->maxDuration;
}
std::ostream& operator<<(std::ostream& os, const Order& o) {
    std::time_t t = std::chrono::system_clock::to_time_t(o.timestamp);
    std::tm tm = *std::localtime(&t);

    char buffer[9]; // HH:MM:SS
    std::strftime(buffer, sizeof(buffer), "%H:%M:%S", &tm);

    // Difficultate
    if (o.difficulty == Dif::EASY) os << "EASY\n";
    else if (o.difficulty == Dif::MEDIUM) os << "MEDIUM\n";
    else os << "HARD\n";

    // Info comanda
    os << "Order [" << o.id
       << " | (Timestamp: " << buffer
       << " Max Time: " << o.maxDuration.count() << "s)] "
       << o.calc() << " RON\n";

    os << "Contents:\n";
    for (const FoodItem& it : o.items)
        os << it << "\n";

    return os;
}
void Order::resetIDs() {
    Order::nextId = 1;
}

