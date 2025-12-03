//
// Created by Catalin on 12/3/2025.
//

#ifndef OOP_RESTAURANT_H
#define OOP_RESTAURANT_H
#include "WorkStation.h"
class Restaurant {
private:
    std::vector<std::unique_ptr<WorkStation>> stations;

public:
    Restaurant();
    ~Restaurant() = default;
    Restaurant(const Restaurant&) = delete;
    Restaurant& operator=(const Restaurant&) = delete;
    void processOrderThroughStations(Order& order, Player& player);
};

#endif //OOP_RESTAURANT_H