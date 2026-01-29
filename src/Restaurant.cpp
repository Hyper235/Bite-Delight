// Restaurant.cpp
#include "../include/Restaurant.h"
#include "../include/BuildStation.h"
#include "../include/DrinkStation.h"
#include "../include/GrillStation.h"
#include "../include/Order.h"
#include "../include/OrderStation.h"
#include "../include/Player.h"
#include "../include/ServeStation.h"
#include <../include/Exceptions.h>
Restaurant::Restaurant() {
  stations.push_back(std::make_unique<OrderStation>());
  stations.push_back(std::make_unique<GrillStation>());
  stations.push_back(std::make_unique<BuildStation>());
  stations.push_back(std::make_unique<ServeStation>());
  stations.push_back(std::make_unique<DrinkStation>());
}

Restaurant::Restaurant(const Restaurant &other) {
  stations.reserve(other.stations.size());
  for (const auto &ws : other.stations) {
    stations.push_back(ws->clone()); // folosești virtual constructorul
  }
}

Restaurant &Restaurant::operator=(Restaurant other) {
  swap(*this, other);
  return *this;
}
