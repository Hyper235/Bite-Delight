#include "Game.h"
#include "Player.h"
#include "Customer.h"
#include <fstream>
#include <iostream>
#include <random>
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
    Customer c1(Menu::getMenu());
    std::cout<<c1;
    Customer c2(Menu::getMenu());
    std::cout<<c2;

}