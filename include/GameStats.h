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
    GameStats() = delete; // nu vrem obiecte GameStats, doar metode statice

    // înregistrări de evenimente în joc:
    static void registerNewOrder(const Order& order);
    static void registerOrderServed(const Order& order);
    static void registerOrderExpired(const Order& order);

    // getters
    static unsigned int getTotalOrders()   { return totalOrders; }
    static unsigned int getServedOrders()  { return servedOrders; }
    static unsigned int getExpiredOrders() { return expiredOrders; }

    static float getTotalRevenue()         { return totalRevenue; }
    static float getHighestOrderValue()    { return highestOrderValue; }

    static float getAverageRevenue() {
        if (servedOrders == 0) return 0.0f;
        return totalRevenue / static_cast<float>(servedOrders);
    }
      static void printStats();
    static const std::vector<float>& getServedValues() {
        return servedValues;
    }
};

#endif //OOP_GAMESTATS_H
