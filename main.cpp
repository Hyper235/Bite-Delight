#include <iostream>
#include <vector>
#include <thread> // Necesar pentru sleep_for
#include <chrono> // Necesar pentru seconds
#include <cstdlib> // Necesar pentru srand
#include <ctime>   // Necesar pentru time

// Include-urile tale
#include "FoodItem.h"
#include "Order.h"
#include "Player.h"
#include "Customer.h"

// Presupun că acestea sunt definite în headerele tale
// enum class FoodType { FOOD, DRINK };
// enum class Dif {EASY,MEDIUM,HARD};

int main() {
    // 1. SETUP
    std::srand(std::time(nullptr));
    std::cout << "=== Incepere Test Sistem Bacsis ===\n";

    // Meniu simplu: un item care costă 100 RON pentru calcul ușor
    FoodItem pizzaTest(1, "Pizza Scumpa", 100.0f, FoodType::FOOD);
    std::vector<FoodItem> menu = {pizzaTest};

    // Player (începe cu 0 RON ca să vedem clar câștigurile)
    Player player("TestPlayer", 0.0f);
    std::cout << "Player initial:\n" << player << "\n\n";

    // Durata maximă a comenzilor va fi 10 secunde
    const unsigned int MAX_SEC = 10;
    // Prag Rapid (20% tip): < 3 sec
    // Prag Normal (5% tip): 3-8 sec
    // Prag Lent (0 tip): > 8 sec

    // --- TEST 1: BACȘIȘ RAPID (20%) ---
    std::cout << "--- Test 1: Comanda Rapida (< 3 sec) ---\n";
    Order orderFast(1,0, Dif::EASY, MAX_SEC, menu);
    player.addOrder(orderFast);
    std::cout << "Comanda adaugata. Se asteapta 1 secunda...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1LL));

    player.finishOrder(); // Aici se calculează bacșișul

    std::cout << "Player dupa comanda 1:\n" << player << "\n";
    // Balanța așteptată: 100 RON (preț) + 20 RON (20% bacșiș) = 120 RON

    // --- TEST 2: BACȘIȘ NORMAL (5%) ---
    std::cout << "\n--- Test 2: Comanda Normala (intre 3-8 sec) ---\n";
    Order orderNormal(2,0, Dif::EASY, MAX_SEC, menu);
    player.addOrder(orderNormal);
    std::cout << "Comanda adaugata. Se asteapta 5 secunde...\n";
    std::this_thread::sleep_for(std::chrono::seconds(5LL));

    player.finishOrder();

    std::cout << "Player dupa comanda 2:\n" << player << "\n";
    // Balanța așteptată: 120 RON (veche) + 100 RON (preț) + 5 RON (5% bacșiș) = 225 RON

    // --- TEST 3: FĂRĂ BACȘIȘ (0%) ---
    std::cout << "\n--- Test 3: Comanda Lenta (> 8 sec) ---\n";
    Order orderSlow(3,0, Dif::EASY, MAX_SEC, menu);
    player.addOrder(orderSlow);
    std::cout << "Comanda adaugata. Se asteapta 9 secunde...\n";
    std::this_thread::sleep_for(std::chrono::seconds(9LL));

    player.finishOrder();

    std::cout << "Player dupa comanda 3:\n" << player << "\n";
    // Balanța așteptată: 225 RON (veche) + 100 RON (preț) + 0 RON (bacșiș) = 325 RON

    std::cout << "\n--- Test finalizat. ---\n";

    return 0;
}