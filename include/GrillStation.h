//
// Created by Catalin on 12/3/2025.
//

#ifndef OOP_GRILLSTATION_H
#define OOP_GRILLSTATION_H
#include "Order.h"
#include "Player.h"
#include "WorkStation.h"
class GrillStation: public WorkStation {
public:
    void processAction(ActionType action,
                           Ingredient* ingredient,
                           Order& order,
                           Player& player) override;
};
#endif //OOP_GRILLSTATION_H