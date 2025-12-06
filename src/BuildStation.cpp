//
// Created by Catalin on 12/3/2025.
//
#include "BuildStation.h"
#include <iostream>
#include "Exceptions.h"
#include "../include/Menu.h"
#include "../include/Order.h"
#include "../include/FoodItem.h"
#include "../include/Player.h"
BuildStation::BuildStation() : WorkStation("BuildStation") {}
void BuildStation::printImpl(std::ostream& os) const {
    os << "BuildStation (asamblare comenzi)";
}
const FoodItem* BuildStation::matchRecipe(const std::vector<Ingredient>& built) const {
    const auto& menu = Menu::getMenu();
    for (const auto& fi : menu) {
        if (fi.getRecipe() == built) {
            return &fi;
        }
    }
    return nullptr;
}
void BuildStation::processAction(ActionType action,
                                 Ingredient* ingredient,
                                 Order& order,
                                 Player& player)
{
    switch (action) {

        case ActionType::AddIngredient:
            if (!ingredient)
                throw ActionException("Ingredient null");

            currentRecipe.push_back(*ingredient);
            std::cout << "[BuildStation] Ingredient added.\n";
            break;


        case ActionType::FinishItem: {
            const FoodItem* built = matchRecipe(currentRecipe);

            if (!built) {
                currentRecipe.clear();
                throw ActionException("Recipe does not match any known burger!");
            }

            bool ok = order.registerPreparedItem(*built);

            if (!ok)
                throw ActionException("This burger does not belong to the current order!");

            std::cout << "[BuildStation] Prepared item registered: "
                      << built->getName() << "\n";

            currentRecipe.clear();
            break;
        }

        default:
            throw ActionException("Unknown action for BuildStation");
    }
}

std::unique_ptr<WorkStation> BuildStation::clone() const {
    return std::make_unique<BuildStation>(*this);
}