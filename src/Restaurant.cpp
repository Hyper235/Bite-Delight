// Restaurant.cpp
#include "../include/Restaurant.h"
#include "../include/OrderStation.h"
#include "../include/GrillStation.h"
#include "../include/BuildStation.h"
#include "../include/ServeStation.h"
#include "../include/Order.h"
#include "../include/Player.h"

Restaurant::Restaurant() {
    // orice Restaurant are implicit aceste stații:
    stations.push_back(std::make_unique<OrderStation>());
    stations.push_back(std::make_unique<GrillStation>());
    stations.push_back(std::make_unique<BuildStation>());
    stations.push_back(std::make_unique<ServeStation>());
}

