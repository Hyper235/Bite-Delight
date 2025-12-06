//
// Created by Catalin on 12/3/2025.
//
#include "GrillStation.h"
#include <iostream>
#include "../include/Order.h"
#include "../include/Player.h"
GrillStation::GrillStation() : WorkStation("GrillStation") {}
void GrillStation::printImpl(std::ostream& os) const {
    os << "Grillstation (prelucrare ingrediente)";
}
void GrillStation::processAction(ActionType action,
                           [[maybe_unused]]Ingredient* ingredient,
                           Order& order,
                           Player& player){
    switch (action) {
        case ActionType::PutBurgerOnGrill:
            std::cout<<"[GrillStation] Player "<<player.getName()<<" a pus carnea pe grill pt comanda #"<<order.getID()<<"\n";
            break;
        case ActionType::FlipBurger:
            std::cout<<"[GrillStation] Player "<<player.getName()<<" a intors carnea pe grill pt comanda #"<<order.getID()<<"\n";
            break;
        case ActionType::TakeFromGrill:
            std::cout<<"[GrillStation] Player "<<player.getName()<<" a luat carnea de pe grill pt comanda #"<<order.getID()<<"\n";
            break;
        default:
            break;
    }
}

std::unique_ptr<WorkStation> GrillStation::clone() const {
    return std::make_unique<GrillStation>(*this);
}