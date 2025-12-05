//
// Created by Catalin on 12/3/2025.
//
#include "BuildStation.h"
#include <iostream>
#include "../include/Order.h"
#include "../include/Player.h"
BuildStation::BuildStation() : WorkStation("BuildStation") {}
void BuildStation::printImpl(std::ostream& os) const {
    os << "BuildStation (asamblare comenzi)";
}
void BuildStation::processAction([[maybe_unused]]ActionType action,
                           [[maybe_unused]]Ingredient* ingredient,
                           [[maybe_unused]]Order& order,
                           [[maybe_unused]]Player& player){
    if (action==ActionType::AddIngredient) {
        switch (*ingredient) {
            case Ingredient::BunBottom:
                std::cout << "[BuildStation] Adaug BunBottom\n";
                break;

            case Ingredient::Patty:
                std::cout << "[BuildStation] Adaug Patty\n";
                break;

            case Ingredient::Cheese:
                std::cout << "[BuildStation] Adaug Cheese\n";
                break;

            case Ingredient::Lettuce:
                std::cout << "[BuildStation] Adaug Lettuce\n";
                break;

            case Ingredient::Tomato:
                std::cout << "[BuildStation] Adaug Tomato\n";
                break;

            case Ingredient::Sauce:
                std::cout << "[BuildStation] Adaug Sauce\n";
                break;

            case Ingredient::BunTop:
                std::cout << "[BuildStation] Adaug BunTop\n";
                break;
        }
    }
}
std::unique_ptr<WorkStation> BuildStation::clone() const {
    return std::make_unique<BuildStation>(*this);
}