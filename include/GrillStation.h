//
// Created by Catalin on 12/3/2025.
//

#ifndef OOP_GRILLSTATION_H
#define OOP_GRILLSTATION_H
#include <memory>
#include "Order.h"
#include "Player.h"
#include "WorkStation.h"
class GrillStation: public WorkStation {
public:
    GrillStation();
    void processAction(ActionType action,
                           Ingredient* ingredient,
                           Order& order,
                           Player& player) override;
    [[nodiscard]]std::unique_ptr<WorkStation> clone() const override;
protected:
    void printImpl(std::ostream& os) const override;
};
#endif //OOP_GRILLSTATION_H