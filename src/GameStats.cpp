#include <iostream>
#include <iomanip>
#include "../include/GameStats.h"

void GameStats::registerNewOrder(const Order &order) {
  (void)order;
  totalOrders++;
}

void GameStats::registerOrderServed(const Order &order) {
  servedOrders++;
  totalRevenue += order.calc();
  if (order.calc() > highestOrderValue)
    highestOrderValue = order.calc();

  servedValues.push_back(order.calc());
}
void GameStats::registerOrderExpired(const Order &order) {
  (void)order;
  expiredOrders++;
}

void GameStats::increaseRating() {
    rating += 0.1f;
    if (rating > 5.0f) {
        rating = 5.0f;
    }
}

void GameStats::decreaseRating() {
    rating -= 0.2f;
    if (rating < 1.0f) {
        rating = 1.0f;
    }
}

void GameStats::printStats() {
    std::cout << "--- Game Statistics ---\n";
    std::cout << "Total Orders: " << totalOrders << "\n";
    std::cout << "Served Orders: " << servedOrders << "\n";
    std::cout << "Expired Orders: " << expiredOrders << "\n";
    std::cout << "Total Revenue: " << std::fixed << std::setprecision(2) << totalRevenue << " RON\n";
    std::cout << "Highest Order Value: " << highestOrderValue << " RON\n";
    std::cout << "Restaurant Rating: " << rating << "/5.0\n";
    std::cout << "-----------------------\n";
}