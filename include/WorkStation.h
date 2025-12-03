#ifndef OOP_WORKSTATION_H
#define OOP_WORKSTATION_H
#include "Order.h"
#include "Player.h"
#include "ActionType.h"
#include "Ingredient.h"
class WorkStation {
public:
    virtual ~WorkStation() = default;
    // virtual pur
    virtual void processAction(ActionType action,
                               Ingredient* ingredient,
                               Order& order,
                               Player& player) = 0;
};
#endif //OOP_WORKSTATION_H