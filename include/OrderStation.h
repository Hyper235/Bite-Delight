//
// Created by Catalin on 12/3/2025.
//

#ifndef OOP_ORDERSTATION_H
#define OOP_ORDERSTATION_H
#include "Order.h"
#include "Player.h"
#include "WorkStation.h"

class OrderStation: public WorkStation {
public:
    void processAction(ActionType action,
                           Ingredient* ingredient,
                           Order& order,
                           Player& player) override;
};
#endif //OOP_ORDERSTATION_H