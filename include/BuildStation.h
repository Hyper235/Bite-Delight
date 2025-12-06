//
// Created by Catalin on 12/3/2025.
//

#ifndef OOP_BUILDSTATION_H
#define OOP_BUILDSTATION_H
#include <memory>
#include "Order.h"
#include "Player.h"
#include "WorkStation.h"

class BuildStation: public WorkStation {
public:
    std::vector<Ingredient> currentRecipe;
    BuildStation();
    void processAction(ActionType action,
                           Ingredient* ingredient,
                           Order& order,
                           Player& player) override;
    [[nodiscard]]std::unique_ptr<WorkStation> clone() const override;
protected:
    void printImpl(std::ostream& os) const override;
    const FoodItem* matchRecipe(const std::vector<Ingredient>& built) const;

};
#endif //OOP_BUILDSTATION_H