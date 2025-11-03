#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "FoodItem.h"
#include "Order.h"
#include "Player.h"
#include "Customer.h"

void testFoodItem() {
    std::cout << "=== FoodItem Tests ===\n";

    FoodItem defaultItem;
    std::cout << "Default Constructor Test:\n" << defaultItem << "\n";

    FoodItem steak(101, "Steak", 75.0f, FoodType::FOOD);
    std::cout << "Parametric Constructor Test:\n" << steak << "\n";

    FoodItem steakCopy(steak);
    std::cout << "Copy Constructor Test:\n" << steakCopy << "\n";

    steakCopy.setName("Filet Mignon");
    steakCopy.setPrice(90.0f);
    std::cout << "Setter Test (setName, setPrice):\n" << steakCopy << "\n";

    std::cout << "Original item (unchanged):\n" << steak << "\n";

    std::cout << "Getter Test (getName): " << steakCopy.getName() << "\n";
    std::cout << "Getter Test (getPrice): " << steakCopy.getPrice() << "\n";

    FoodType type = steak.getType();
    std::cout << "Getter Test (getType): "
              << (type == FoodType::FOOD ? "FOOD" : (type == FoodType::DRINK ? "DRINK" : "UNDEFINED"))
              << "\n";

    std::cout << "========================\n\n";
}

// --- Test Function for Order ---
void testOrder() {
    std::cout << "=== Order Tests ===\n";

    FoodItem testPizza(1, "Test Pizza", 25.0f, FoodType::FOOD);
    FoodItem testCola(2, "Test Cola", 5.0f, FoodType::DRINK);
    std::vector<FoodItem> testOrderItems = {testPizza, testCola};

    Order::resetIDs();

    Order order1;
    std::cout << "Default Constructor Test:\n" << order1 << "\n";

    order1.addItemToOrder(testPizza);
    std::cout << "addItemToOrder Test:\n" << order1 << "\n";

    Order order2(1, 10.0f, Dif::MEDIUM, 60, testOrderItems);
    std::cout << "Parametric Constructor Test:\n" << order2 << "\n";

    std::cout << "Getter Test (getID): " << order2.getID() << "\n";
    std::cout << "Getter Test (calc): " << order2.calc() << " RON\n";

    order1.setTips(5);
    std::cout << "setTips Test (5):\n" << order1 << "\n";
    std::cout << "Getter Test (getTips): " << order1.getTips() << "\n";

    order1.addTips(2.5f);
    std::cout << "addTips Test (2.5f):\n" << order1 << "\n";

    order1.setDifficulty(Dif::HARD);
    order1.setMaxDuration(1);
    std::cout << "setDifficulty & setMaxDuration Test:\n" << order1 << "\n";
    std::cout << "Getter Test (getMaxDuration): " << order1.getMaxDuration().count() << "s\n";
    std::cout << "Getter Test (getTimestamp): "
              << std::chrono::system_clock::to_time_t(order1.getTimestamp()) << "\n";

    std::cout << "Testing hasExpired (waiting 2 seconds)...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2LL));
    std::cout << "hasExpired Test: " << (order1.hasExpired() ? "Yes" : "No") << "\n";

    Order::resetIDs();
    Order order3(1, 0.0f, Dif::EASY, 60, {});
    std::cout << "resetIDs Test (ID should be 1): " << order3.getID() << "\n";

    std::cout << "========================\n\n";
}
void testPlayer() {
    std::cout << "=== Player Tests ===\n";

    FoodItem testPizza(1, "Test Pizza", 50.0f, FoodType::FOOD);
    std::vector<FoodItem> singleItemMenu = {testPizza};

    // Duration is 5 seconds for clear test cases
    const unsigned int MAX_SEC = 5;
    Order orderFast(1, 0.0f, Dif::EASY, MAX_SEC, singleItemMenu);
    Order orderSlow(2, 0.0f, Dif::EASY, MAX_SEC, singleItemMenu);

    // Test Constructors
    Player defaultPlayer;
    std::cout << "Default Constructor Test:\n" << defaultPlayer << "\n";

    Player player1("Alice", 100.0f);
    std::cout << "Parametric Constructor Test:\n" << player1 << "\n";

    // Test Getters and Setters
    std::cout << "Getter Test (getName): " << player1.getName() << "\n";
    player1.setBalance(50.0f);
    player1.addBalance(25.0f);
    player1.setName("Alice Cooper");
    std::cout << "Setter/Adder Test (Final Balance): " << player1.getBalance() << " RON\n";
    std::cout << "Updated Name: " << player1.getName() << "\n";

    // Test addOrder and placeOrder
    player1.addOrder(orderFast);
    player1.placeOrder(orderSlow);
    std::cout << "addOrder/placeOrder Test (Queue Size): " << player1.getOrderCount() << "\n";
    std::cout << "Player State with Orders:\n" << player1 << "\n";

    // --- Test finishOrder (Fast Tip 20%) ---
    std::cout << "Testing finishOrder (Fast Tip 20%): Waiting 1 second...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1LL));
    // Max 5s. 1s is 20% -> should be fast tip (0.20f)

    float initialBalance = player1.getBalance();
    player1.finishOrder();

    std::cout << "Balance Change: " << player1.getBalance() - initialBalance << " RON\n";
    std::cout << "Player State After Fast Order:\n" << player1 << "\n";

    // --- Test finishOrder (Slow Tip 0%) ---
    std::cout << "Testing finishOrder (Slow Tip 0%): Waiting 4 seconds...\n";
    std::this_thread::sleep_for(std::chrono::seconds(4LL));
    // Max 5s. 4s is 80% -> should be slow/no tip (0.0f)

    initialBalance = player1.getBalance();
    player1.finishOrder();

    std::cout << "Balance Change: " << player1.getBalance() - initialBalance << " RON\n";
    std::cout << "Player State After Slow Order:\n" << player1 << "\n";

    std::cout << "========================\n\n";
}
void testCustomer() {
    std::cout << "=== Customer Tests ===\n";

    // Setup: Menu and a specific order for testing
    FoodItem testPizza(1, "Test Pizza", 50.0f, FoodType::FOOD);
    FoodItem testCola(2, "Test Cola", 5.0f, FoodType::DRINK);
    std::vector<FoodItem> testMenu = {testPizza, testCola};
    Order specificOrder(100, 0.0f, Dif::EASY, 60, {testPizza});

    // Test 1: Implicit Constructor (Name is random, Order is empty)
    Customer customer1;
    std::cout << "Implicit Constructor Test:\n" << customer1 << "\n";

    // Test 2: Parametric Constructor with Menu (Name and Order are random)
    Customer customer2(testMenu);
    std::cout << "Parametric Menu Constructor Test:\n" << customer2 << "\n";

    // Test 3: Parametric Constructor with all parameters
    Customer customer3("John Doe", specificOrder);
    std::cout << "Full Parametric Constructor Test:\n" << customer3 << "\n";

    // Test 4: Copy Constructor
    Customer customer4 = customer3;
    std::cout << "Copy Constructor Test (c4 = c3):\n" << customer4 << "\n";

    // Test 5: Assignment Operator (=)
    Customer customer5(testMenu);
    std::cout << "Customer 5 before assignment:\n" << customer5 << "\n";
    customer5 = customer3;
    std::cout << "Assignment Operator Test (c5 = c3):\n" << customer5 << "\n";

    // Test 6: Getters and Mutability (getOrder)
    std::cout << "Getter Test (Name): " << customer3.getName() << "\n";
    std::cout << "Getter Test (Order ID before modification): " << customer3.getOrder().getID() << "\n";

    // Use non-const getOrder to modify the internal order
    customer3.getOrder().setMaxDuration(10);
    std::cout << "Mutability Test: Order Max Duration set to 10s.\n";
    std::cout << customer3.getOrder().getMaxDuration().count() << " seconds\n";

    std::cout << "========================\n\n";
}
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

    // 4. Finish Order
    catalin.finishOrder();

    // 5. Final State Check
    std::cout << "\n--- Final State ---\n";
    std::cout << "Player " << catalin.getName() << " after finishing the order:\n";
    std::cout << catalin << "\n";

    std::cout << "========================\n\n";
}
int main() {
    testFoodItem();
    testPlayer();
    testOrder();
    testCustomer();
    testFullScenario();
}