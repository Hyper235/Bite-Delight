//
// Created by Catalin on 12/3/2025.
//

#ifndef OOP_ORDERSTATION_H
#define OOP_ORDERSTATION_H
#include <memory>
#include "Order.h"
#include "Player.h"
#include "WorkStation.h"

class OrderStation: public WorkStation {
public:
    OrderStation();
    void processAction(ActionType action,
                           Ingredient* ingredient,
                           Order& order,
                           Player& player) override;
    [[nodiscard]]std::unique_ptr<WorkStation> clone() const override;
protected:
    [[maybe_unused]]void printImpl(std::ostream& os) const override;
};
#endif //OOP_ORDERSTATION_H