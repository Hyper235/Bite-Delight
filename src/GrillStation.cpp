//
// Created by Catalin on 12/3/2025.
//
#include "GrillStation.h"
#include <iostream>
#include "../include/Order.h"
#include "../include/Player.h"
void GrillStation::processAction([[maybe_unused]]ActionType action,
                           [[maybe_unused]]Ingredient* ingredient,
                           Order& order,
                           Player& player){
    std::cout<<"[GrillStation] Player "<<player.getName()<<" gateste #"<<order.getID()<<"\n";
}