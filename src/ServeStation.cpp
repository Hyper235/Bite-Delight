//
// Created by Catalin on 12/3/2025.
//
#include "ServeStation.h"
#include <iostream>
#include "../include/Order.h"
#include "../include/Player.h"
ServeStation::ServeStation() : WorkStation("ServeStation") {}
void ServeStation::printImpl(std::ostream& os) const {
    os << "ServeStation (servire comenzi)";
}
void ServeStation::processAction([[maybe_unused]]ActionType action,
                           [[maybe_unused]]Ingredient* ingredient,
                           Order& order,
                           Player& player){
    std::cout<<"[ServeStation] Player "<<player.getName()<<" serveste comanda #"<<order.getID()<<"\n";
}

std::unique_ptr<WorkStation> ServeStation::clone() const {
    return std::make_unique<ServeStation>(*this);
}