#include "Game.h"
#include "Player.h"
#include "Customer.h"
#include <fstream>
#include <iostream>
#include <random>
#include "Restaurant.h"
#include <exception>
#include "Exceptions.h"
#include "Menu.h"
#define SAVEGAME "saves/player.txt"
int main() {
    std::srand(std::time(nullptr));
    Player player;
    std::ifstream in("../saves/player.txt");

    if (in) {
        std::string playerName;
        std::getline(in, playerName);
        player.setName(playerName);
        float balance;
        in>>balance;
        player.setBalance(balance);
        unsigned int days;
        in>>days;
        player.setDays(days);
    } else {
        std::cerr << "Nu pot citi saves/player.txt – folosesc nume default.\n";
    }
    std::cout<<player;
    Restaurant r;

    auto menu = Menu::getMenu();
    Order ord;
    ord.setDifficulty(Dif::MEDIUM);
    ord.setMaxDuration(3 * 30);
    ord.addItemToOrder(menu[0]);
    ord.addItemToOrder(menu[1]);
    ord.addItemToOrder(menu[0]);
    Customer c{"Gigel", ord};
    std::cout << "=== Customer & Order (scenariu joc) ===\n";
    std::cout << c << "\n";

    const std::size_t BUILD_INDEX = 2;  // adapt la cum ai tu vectorul de statii
    const std::size_t SERVE_INDEX = 3;
    Restaurant restaurant;
      std::cout << "\n=== Player ajunge la BuildStation ===\n";
        restaurant.switchHUD(BUILD_INDEX);  // doar afiseaza HUD-ul pt build

        // Simulam ca player-ul construieste un Cheeseburger:
        Ingredient i1 = Ingredient::BunBottom;
        Ingredient i2 = Ingredient::Patty;
        Ingredient i3 = Ingredient::Cheese;
        Ingredient i4 = Ingredient::Sauce;
        Ingredient i5 = Ingredient::BunTop;

        // AddIngredient pentru fiecare componenta
        restaurant.handlePlayerAtStation(BUILD_INDEX, ActionType::AddIngredient, &i1, ord, player);
        restaurant.handlePlayerAtStation(BUILD_INDEX, ActionType::AddIngredient, &i2, ord, player);
        restaurant.handlePlayerAtStation(BUILD_INDEX, ActionType::AddIngredient, &i3, ord, player);
        restaurant.handlePlayerAtStation(BUILD_INDEX, ActionType::AddIngredient, &i4, ord, player);
        restaurant.handlePlayerAtStation(BUILD_INDEX, ActionType::AddIngredient, &i5, ord, player);

        // Semnalam ca burgerul e gata
        restaurant.handlePlayerAtStation(BUILD_INDEX, ActionType::FinishItem, nullptr, ord, player);

        std::cout << "\nDupa BuildStation, status order complete? "
                  << std::boolalpha << ord.isComplete() << "\n";

        // b) Mutam player-ul la ServeStation
        std::cout << "\n=== Player ajunge la ServeStation ===\n";
        // player.setCurrentStationIndex(SERVE_INDEX);
        restaurant.switchHUD(SERVE_INDEX);

        // Incerci sa servesti comanda
        restaurant.handlePlayerAtStation(SERVE_INDEX, ActionType::ServeOrder, nullptr, ord, player);

        std::cout << "\nDupa ServeStation, status order complete? "
                  << std::boolalpha << ord.isComplete() << "\n";

        std::cout << "\n=== Sfarsit scenariu de test ===\n";

    }