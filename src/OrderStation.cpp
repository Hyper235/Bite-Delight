//
// Created by Catalin on 12/3/2025.
//
#include "OrderStation.h"
#include <iostream>
#include "../include/Order.h"
#include "../include/Player.h"
OrderStation::OrderStation() : WorkStation("OrderStation") {}
void OrderStation::printImpl(std::ostream& os) const {
    os << "OrderStation (preluare comenzi)";
}
void OrderStation::processAction([[maybe_unused]]ActionType action,
                           [[maybe_unused]]Ingredient* ingredient,
                           Order& order,
                           Player& player){
    std::cout<<"[OrderStation] Player "<<player.getName()<<" preia comanda #"<<order.getID()<<"\n";
}
std::unique_ptr<WorkStation> OrderStation::clone() const {
    return std::make_unique<OrderStation>(*this);
}