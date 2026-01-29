#include "StatsUpdater.h"
#include <iostream>

StatsUpdater::~StatsUpdater() = default;

void StatsUpdater::update(Order *order) {
  if (!order)
    return;

  if (order->isComplete()) {
    GameStats::registerOrderServed(*order);
    GameStats::increaseRating();
    std::cout << "[OBSERVER] GameStats: Comanda servita. Rating-ul a crescut.\n";
  } else if (order->hasExpired()) {
    GameStats::registerOrderExpired(*order);
    GameStats::decreaseRating();
    std::cout << "[OBSERVER] GameStats: Comanda expirata. Rating-ul a scazut.\n";
  }
}
