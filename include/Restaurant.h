//
// Created by Catalin on 12/3/2025.
//

#ifndef OOP_RESTAURANT_H
#define OOP_RESTAURANT_H
#include "WorkStation.h"
#include <memory>
class Restaurant {
private:
    std::vector<std::unique_ptr<WorkStation>> stations;

public:
    Restaurant();
    ~Restaurant() = default;
    Restaurant(const Restaurant&) = delete;
    Restaurant& operator=(const Restaurant&) = delete;
    void handlePlayerAtStation(std::size_t index,
                                           ActionType action,
                                           Ingredient* ingredient,
                                           Order& order,
                                           Player& player);
};

#endif //OOP_RESTAURANT_H

