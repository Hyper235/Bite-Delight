//
// Created by Catalin on 12/7/2025.
//

#ifndef OOP_GAMESTATS_H
#define OOP_GAMESTATS_H

#include <vector>
#include "Order.h"

class GameStats {
private:
    inline static unsigned int totalOrders   = 0;
    inline static unsigned int servedOrders  = 0;
    inline static unsigned int expiredOrders = 0;

    inline static float totalRevenue      = 0.0f;
    inline static float highestOrderValue = 0.0f;

    inline static std::vector<float> servedValues;

public:
    GameStats() = delete;
    static void registerNewOrder(const Order& order);
    static void registerOrderServed(const Order& order);
    static void registerOrderExpired(const Order& order);

    static void printStats();
};

#endif //OOP_GAMESTATS_H
