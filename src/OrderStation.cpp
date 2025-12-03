//
// Created by Catalin on 12/3/2025.
//
#include "OrderStation.h"
#include <iostream>
#include "../include/Order.h"
#include "../include/Player.h"
void OrderStation::processAction([[maybe_unused]]ActionType action,
                           [[maybe_unused]]Ingredient* ingredient,
                           Order& order,
                           Player& player){
    std::cout<<"[OrderStation] Player "<<player.getName()<<" preia comanda #"<<order.getID()<<"\n";
}