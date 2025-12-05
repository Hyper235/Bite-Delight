// Restaurant.cpp
#include "../include/Restaurant.h"
#include "../include/OrderStation.h"
#include "../include/GrillStation.h"
#include "../include/BuildStation.h"
#include "../include/ServeStation.h"
#include "../include/Order.h"
#include "../include/Player.h"

Restaurant::Restaurant() {
    // stations.push_back(std::make_unique<OrderStation>());
    stations.push_back(std::make_unique<GrillStation>());
    stations.push_back(std::make_unique<BuildStation>());
    stations.push_back(std::make_unique<ServeStation>());
}
#include <iostream>
#include <stdexcept>

void Restaurant::handlePlayerAtStation(std::size_t index,
                                       ActionType action,
                                       Ingredient* ingredient,
                                       Order& order,
                                       Player& player) {
    if (index >= stations.size()) {
        throw std::out_of_range("Index invalid de statie");
    }

    stations[index]->processAction(action, ingredient, order, player);

    std::cout << "Statie curenta: ";
    stations[index]->print(std::cout);
    std::cout << "\n";

    if (auto grill = dynamic_cast<GrillStation*>(stations[index].get())) {
        std::cout << "[Restaurant] Jucatorul este la GrillStation (downcast reusit).\n";
    }
}
