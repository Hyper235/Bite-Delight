//
// Created by Catalin on 12/7/2025.
//

#include "../include/GameStats.h"
#include "../include/Order.h"



void GameStats::registerNewOrder(const Order& /*order*/) {
    ++totalOrders;
}

void GameStats::registerOrderServed(const Order& order) {
    float value = order.calc();
    ++servedOrders;

    totalRevenue += value;
    if (value > highestOrderValue) {
        highestOrderValue = value;
    }

    servedValues.push_back(value);
}

void GameStats::registerOrderExpired(const Order& /*order*/) {
    ++expiredOrders;
}
void GameStats::printStats() {
    std::cout << "\n================== GAME STATISTICS ==================\n";
    std::cout << "Total Orders:        " << totalOrders << "\n";
    std::cout << "Served Orders:       " << servedOrders << "\n";
    std::cout << "Expired Orders:      " << expiredOrders << "\n";
    std::cout << "Total Revenue:       " << totalRevenue << " RON\n";
    std::cout << "Highest Order Value: " << highestOrderValue << " RON\n";

    if (servedOrders > 0) {
        std::cout << "Average Revenue:     " << (totalRevenue / servedOrders)
                  << " RON\n";
    } else {
        std::cout << "Average Revenue:     0 RON (no served orders)\n";
    }

    std::cout << "Served Order Values: ";
    if (servedValues.empty()) {
        std::cout << "none";
    } else {
        for (float v : servedValues)
            std::cout << v << " ";
    }
    std::cout << "\n=====================================================\n";
}