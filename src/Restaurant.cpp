// Restaurant.cpp
#include "../include/Restaurant.h"
#include "../include/OrderStation.h"
#include "../include/GrillStation.h"
#include "../include/BuildStation.h"
#include "../include/ServeStation.h"
#include "../include/Order.h"
#include "../include/Player.h"
#include <../include/Exceptions.h>
Restaurant::Restaurant() {
     stations.push_back(std::make_unique<OrderStation>());
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
                                       Player& player) const {
    if (index >= stations.size()) {
        throw StationException("Index invalid de statie: " + std::to_string(index));
    }
    stations[index]->processAction(action, ingredient, order, player);

    std::cout << "Statie curenta: ";
    stations[index]->print(std::cout);
    std::cout << "\n";
}
void Restaurant::switchHUD(std::size_t index) const {
    if (index >= stations.size()) {
        throw StationException("Index invalid de statie: " + std::to_string(index));
    }

    WorkStation* ws = stations[index].get();

    if (dynamic_cast<OrderStation*>(ws)) {
        std::cout << "[HUD] Te afli la ORDER STATION\n";
        std::cout << "Actiune: preia o comanda.\n";
        return;
    }

    if (dynamic_cast<GrillStation*>(ws)) {
        std::cout << "[HUD] Te afli la GRILL STATION\n";
        std::cout << "Actiuni: adauga ingredient, intoarce, verifica timp etc.\n";
        return;
    }

    if (dynamic_cast<BuildStation*>(ws)) {
        std::cout << "[HUD] Te afli la BUILD STATION\n";
        std::cout << "Actiune: asambleaza burgerul.\n";
        return;
    }

    if (dynamic_cast<ServeStation*>(ws)) {
        std::cout << "[HUD] Te afli la SERVE STATION\n";
        std::cout << "Actiune: serveste comanda clientului.\n";
        return;
    }
}
