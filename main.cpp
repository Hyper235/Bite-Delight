#include "Customer.h"
#include "Exceptions.h"
#include "Game.h"
#include "GameStats.h"
#include "Ingredient.h"
#include "Inventory.h"
#include "Menu.h"
#include "Player.h"
#include "Restaurant.h"
#include "SaveManager.h"
#include "StatsUpdater.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <thread>

void runObserverTest() {
  std::cout << "\n--- EXECUTARE TEST OBSERVER ---\n\n";

  StatsUpdater statsUpdater;

  {
    std::cout << "--- TEST 1: CLIENT FERICIT ---\n";
    Customer customer = Customer::create(CustomerType::REGULAR, Menu::getMenu());
    customer.getOrder().addObserver(&statsUpdater);

    std::cout << "--- STARE INITIALA ---\n";
    GameStats::printStats();
    std::cout << customer << "\n\n";

    std::cout << "--- SIMULARE: Finalizare comanda... ---\n";
    customer.getOrder().forceComplete();

    std::cout << "\n--- STARE FINALA (TEST 1) ---\n";
    GameStats::printStats();
    std::cout << customer << "\n\n";
  }

  {
    std::cout << "--- TEST 2: CLIENT SUPARAT ---\n";
    Customer customer2 =
        Customer::create(CustomerType::REGULAR, Menu::getMenu());
    customer2.getOrder().addObserver(&statsUpdater);

    std::cout << "--- STARE INITIALA ---\n";
    GameStats::printStats();
    std::cout << customer2 << "\n\n";

    std::cout << "--- SIMULARE: Expirare comanda... ---\n";
    customer2.getOrder().forceExpire();

    std::cout << "\n--- STARE FINALA (TEST 2) ---\n";
    GameStats::printStats();
    std::cout << customer2 << "\n\n";
  }

  std::cout << "--- TEST OBSERVER FINALIZAT ---\n";
}

void runStrategyTest() {
  std::cout << "\n--- EXECUTARE TEST STRATEGY ---\n\n";

  FoodItem item(1, {}, "Test Item", 10.0f, FoodType::FOOD);
  std::vector<FoodItem> items = {item};

  Order easyOrder(1, 0, Dif::EASY, 100, items);
  Order mediumOrder(2, 0, Dif::MEDIUM, 100, items);
  Order hardOrder(3, 0, Dif::HARD, 100, items);

  std::cout << "Pret de baza: " << item.getPrice() << " RON\n";
  std::cout << "Pret final comanda EASY: " << easyOrder.calc() << " RON\n";
  std::cout << "Pret final comanda MEDIUM: " << mediumOrder.calc() << " RON\n";
  std::cout << "Pret final comanda HARD: " << hardOrder.calc() << " RON\n";

  std::cout << "\n--- TEST STRATEGY FINALIZAT ---\n";
}

int main() {
  srand(time(nullptr));

  runObserverTest();
  runStrategyTest();

  Game game;
  game.run();

  return 0;
}