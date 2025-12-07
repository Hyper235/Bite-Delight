//
// Created by Catalin on 12/3/2025.
//
#include "ServeStation.h"
#include <iostream>
#include "../include/Order.h"
#include "../include/Player.h"
#include "../include/Exceptions.h"
ServeStation::ServeStation() : WorkStation("ServeStation") {}
void ServeStation::printImpl(std::ostream& os) const {
    os << "ServeStation (servire comenzi)";
}
void ServeStation::processAction([[maybe_unused]]ActionType action,
                           [[maybe_unused]]Ingredient* ingredient,
                           Order& order,
                           Player& player){
    if (action != ActionType::ServeOrder) {
        throw ActionException("ServeStation accepta doar actiunea ServeOrder");
    }

    // Verificam daca comanda este completa
    if (!order.isComplete()) {
        throw ActionException("Comanda nu este completa, nu poate fi servita!");

    }
    std::cout<<"[ServeStation] Player "<<player.getName()<<" serveste comanda #"<<order.getID()<<"\n";

    std::cout << "[ServeStation] Comanda a fost servita cu succes!\n";
    player.finishOrder();


}

std::unique_ptr<WorkStation> ServeStation::clone() const {
    return std::make_unique<ServeStation>(*this);
}