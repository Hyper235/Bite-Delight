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
    void handlePlayerAtStation(std::size_t index,
                                           ActionType action,
                                           Ingredient* ingredient,
                                           Order& order,
                                           Player& player) const;
    void switchHUD(std::size_t index) const;

    Restaurant(const Restaurant& other);
    Restaurant& operator=(Restaurant other);
    Restaurant(Restaurant&&) noexcept = default;
    Restaurant& operator=(Restaurant&&) noexcept = default;
    friend void swap(Restaurant& a, Restaurant& b) noexcept {
        using std::swap;
        swap(a.stations, b.stations);
    }
};

#endif //OOP_RESTAURANT_H

