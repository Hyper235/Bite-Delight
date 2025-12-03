//
// Created by Catalin on 12/3/2025.
//

#ifndef OOP_BUILDSTATION_H
#define OOP_BUILDSTATION_H
#include "Order.h"
#include "Player.h"
#include "WorkStation.h"

class BuildStation: public WorkStation {
public:
    void processAction(ActionType action,
                           Ingredient* ingredient,
                           Order& order,
                           Player& player) override;
};
#endif //OOP_BUILDSTATION_H