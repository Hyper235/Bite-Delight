#include "ActionType.h"
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

void runWorkstationTest() {
  std::cout << "\n--- EXECUTARE TEST WORKSTATION ---\n\n";

  Restaurant restaurant;
  Player player;
  Customer customer = Customer::create(CustomerType::REGULAR, Menu::getMenu());
  Order &order = customer.getOrder();

  std::cout << "--- Apelare switchHUD pentru statia 2 (BuildStation) ---\n";
  restaurant.switchHUD(2);

  std::cout << "\n--- Apelare handlePlayerAtStation cu AddIngredient ---\n";
  try {
    Ingredient ingredient = Ingredient::Patty;
    restaurant.handlePlayerAtStation(2, ActionType::AddIngredient, &ingredient,
                                     order, player);
  } catch (const std::exception &e) {
    std::cerr << "A aparut o eroare: " << e.what() << '\n';
  }

  std::cout << "\n--- TEST WORKSTATION FINALIZAT ---\n";
}

void runOrderPlayerTest() {
  std::cout << "\n--- EXECUTARE TEST ORDER & PLAYER FUNCS ---\n\n";

  FoodItem testFood(10, {}, "Pizza", 25.0f, FoodType::FOOD);
  std::vector<FoodItem> orderItems = {testFood};
  Order testOrder(100, 5.0f, Dif::EASY, 120, orderItems);

  std::cout << "Initial Order ID: " << testOrder.getID() << "\n";
  std::cout << "Initial Tips: " << testOrder.getTips() << "\n";
  std::cout << "Order Items (via getItems): \n";
  for (const auto &item : testOrder.getItems()) {
    std::cout << " - " << item.getName() << "\n";
  }

  testOrder.setTips(7.5f);
  std::cout << "Updated Tips: " << testOrder.getTips() << "\n";
  testOrder.addTips(2.5f);
  std::cout << "Added Tips: " << testOrder.getTips() << "\n";

  Player testPlayer("Test Player", 1000.0f);
  testPlayer.SetCurrentStation(1);
  std::cout << "Player current station: " << testPlayer.getCurrentStation()
            << "\n";

  testPlayer.placeOrder(testOrder);
  std::cout << "Player placed an order. Order queue size: "
            << testPlayer.getOrderCount() << "\n";

  std::cout << "\n--- TEST ORDER & PLAYER FUNCS FINALIZAT ---\n";
}

int main() {
  srand(time(nullptr));

  runObserverTest();
   runStrategyTest();
   runWorkstationTest();
   runOrderPlayerTest();

  Game game;
  game.run();

  return 0;
}