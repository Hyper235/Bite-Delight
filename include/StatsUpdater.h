#ifndef OOP_STATSUPDATER_H
#define OOP_STATSUPDATER_H

#include "GameStats.h"
#include "Observer.h"
#include "Order.h"

class StatsUpdater : public Observer {
public:
  ~StatsUpdater();
  void update(Order *order) override;
};

#endif // OOP_STATSUPDATER_H
