//
// Created by Catalin on 12/3/2025.
//
#include "BuildStation.h"
#include <iostream>
#include "../include/Order.h"
#include "../include/Player.h"
void BuildStation::processAction([[maybe_unused]]ActionType action,
                           [[maybe_unused]]Ingredient* ingredient,
                           Order& order,
                           Player& player){
    std::cout<<"[BuildStation] Player "<<player.getName()<<" asambleaza #"<<order.getID()<<"\n";
}