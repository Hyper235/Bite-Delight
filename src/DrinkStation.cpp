//
// Created by Catalin on 12/7/2025.
//

#include "../include/DrinkStation.h"
#include "../include/WorkStation.h"
#include "../include/Exceptions.h"
#include "../include/Menu.h"
#include <iostream>

DrinkStation::DrinkStation()
    : WorkStation("DrinkStation")
{}

void DrinkStation::printImpl(std::ostream& os) const {
    os << "DrinkStation (preparare si servire bauturi)";
}

void DrinkStation::processAction(ActionType action,
                                 [[maybe_unused]] Ingredient* ingredient,
                                 Order& order,
                                 Player& player) {
    switch (action) {
        case ActionType::PrepareDrink:
            if (hasPreparedDrink) {
                throw ActionException("DrinkStation: exista deja o bautura pregatita");
            }

            std::cout << "[DrinkStation] Player " << player.getName()
                      << " pregateste o bautura pentru comanda #"
                      << order.getID() << "\n";

            hasPreparedDrink = true;
            break;

        case ActionType::ServeDrink:
            if (!hasPreparedDrink) {
                throw ActionException("DrinkStation: nu exista nicio bautura pregatita pentru a fi servita");
            }

            std::cout << "[DrinkStation] Player " << player.getName()
                      << " serveste bautura pentru comanda #"
                      << order.getID() << "\n";
            order.registerPreparedItem(Menu::getMenu()[5]);
            hasPreparedDrink = false;
            break;

        default:
            throw ActionException("Actiune necunoscuta pentru DrinkStation");
    }
}

std::unique_ptr<WorkStation> DrinkStation::clone() const {
    return std::make_unique<DrinkStation>(*this);
}
