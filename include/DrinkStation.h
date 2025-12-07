//
// Created by Catalin on 12/7/2025.
//

#ifndef OOP_DRINKSTATION_H
#define OOP_DRINKSTATION_H

#include <memory>
#include "WorkStation.h"
#include "Order.h"
#include "Player.h"
#include "ActionType.h"
#include "Ingredient.h"

class DrinkStation : public WorkStation {
public:
    DrinkStation();

    void processAction(ActionType action,
                       Ingredient* ingredient,
                       Order& order,
                       Player& player) override;

    [[nodiscard]] std::unique_ptr<WorkStation> clone() const override;

protected:
    void printImpl(std::ostream& os) const override;

private:
    bool hasPreparedDrink{false};
};

#endif //OOP_DRINKSTATION_H
