#include "Game.h"
#include "Player.h"
#include "Customer.h"
#include <fstream>
#include <iostream>
#define SAVEGAME "saves/player.txt"
int main() {
    std::vector<FoodItem> menu = {
        FoodItem(
            1,
            { Ingredient::BunBottom, Ingredient::Patty, Ingredient::Cheese, Ingredient::Lettuce, Ingredient::Tomato },
            "Classic Burger",
            19.99f,
            FoodType::FOOD
        ),

        FoodItem(
            2,
            { Ingredient::BunBottom, Ingredient::Patty, Ingredient::Cheese, Ingredient::Cheese, Ingredient::Tomato },
            "Double Cheese Burger",
            22.50f,
            FoodType::FOOD
        ),

        FoodItem(
            3,
            { },
            "Cola 500ml",
            7.50f,
            FoodType::DRINK
        ),

        FoodItem(
            4,
            { },
            "Apa plata 500ml",
            5.00f,
            FoodType::DRINK
        ),
    };


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
    Customer c1(menu);
    std::cout<<c1;
}