#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "FoodItem.h"
#include "Order.h"
#include "Player.h"
#include "Customer.h"
void testFullScenario() {
    std::cout << "=== Full Game Scenario Test ===\n";

    FoodItem burger(1, "Classic Cheeseburger", 25.0f, FoodType::FOOD);
    FoodItem fries(2, "Large French Fries", 10.0f, FoodType::FOOD);
    FoodItem chickenNuggets(3, "9x Chicken Nuggets", 20.0f, FoodType::FOOD);
    FoodItem cola(10, "Soda Cola (Large)", 8.0f, FoodType::DRINK);
    FoodItem lemonade(11, "Iced Lemonade", 12.0f, FoodType::DRINK);
    FoodItem water(12, "Still Water", 5.0f, FoodType::DRINK);

    std::vector<FoodItem> fullMenu = {
        burger, fries, chickenNuggets,
        cola, lemonade, water
    };

    Player catalin("Catalin", 500.0f);
    std::cout << "Initial Player: " << catalin.getName() << " (" << catalin.getBalance() << " RON)\n";

    std::cout << "\n--- Customer Arrives ---\n";

    {
        Customer randomCustomer(fullMenu);
        std::cout << "Customer Generated:\n" << randomCustomer;

        std::cout << "Customer places the order.\n";
        catalin.addOrder(randomCustomer.getOrder());
    }
    std::cout << "\nCustomer Left (Destructor called).\n";

    std::cout << "\n--- Processing Order ---\n";

    const Order& firstOrder = catalin.getOrders().front();
    unsigned int maxTime = firstOrder.getMaxDuration().count();

    // We will wait 20% of the max time for a FAST TIP
    unsigned int waitTime = static_cast<unsigned int>(static_cast<float>(maxTime) * 0.20f) + 1;

    std::cout << "Order Max Duration: " << maxTime << "s. Waiting for " << waitTime << " seconds for a FAST TIP...\n";

    std::this_thread::sleep_for(std::chrono::seconds(waitTime));

    catalin.finishOrder();

    std::cout << "\n--- Final State ---\n";
    std::cout << "Player " << catalin.getName() << " after finishing the order:\n";
    std::cout << catalin << "\n";

    std::cout << "========================\n\n";
}