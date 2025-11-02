//
// Created by Catalin on 10/29/2025.
//
#include "../include/Order.h"
//implicit
unsigned int Order::nextId = 1;
Order::Order() : id(nextId++){}
//parametric
Order::Order(unsigned int i,unsigned int maxSeconds)
    : id(i),
      timestamp(std::chrono::system_clock::now()),
      maxDuration(std::chrono::seconds(maxSeconds)) {}
//
void Order::addItemToOrder(const FoodItem &it) {
    items.push_back(it);
}
float Order::calc() const {
    float total=0.0f;
    for(const FoodItem& it: items) {
        total+=it.getPrice();
    }
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

    std::ostringstream oss;
    oss << std::put_time(&tm, "%H:%M:%S");
    if (o.difficulty == Dif::EASY)os<<"EASY\n";
    else if (o.difficulty == Dif::MEDIUM)os<<"MEDIUM\n";
    else os<<"\nHARD\n";
    os << "Order [" << o.id <<" | "<<" ( Timestamp: "<<oss.str()<<" Max Time: "<<o.maxDuration.count()<<" ) " << "] " << o.calc() << " RON\n";
    os << "Contents:\n";
    for (const FoodItem& it: o.items)
        os << it;
    return os;
}
