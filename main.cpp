#include <iostream>
#include <vector>
#include <thread> // pentru sleep
#include "FoodItem.h"
#include "Order.h"
#include "Player.h"
#include "Customer.h"

int main() {
    std::cout << "=== FoodItem Tests ===\n";

    // FoodItem-uri
    FoodItem pizza(1, "Pizza", 25.0f, FoodType::FOOD);
    FoodItem burger(2, "Burger", 15.0f, FoodType::FOOD);
    FoodItem cola(3, "Cola", 5.0f, FoodType::DRINK);

    FoodItem defaultItem;
    FoodItem pizzaCopy(pizza);

    std::cout << "Default item: " << defaultItem << "\n";
    std::cout << "Pizza: " << pizza << "\n";
    std::cout << "Pizza Copy: " << pizzaCopy << "\n";

    pizzaCopy.setName("Pizza Margherita");
    pizzaCopy.setPrice(27.5f);

    std::cout << "Updated Pizza Copy Name: " << pizzaCopy.getName() << "\n";
    std::cout << "Updated Pizza Copy Price: " << pizzaCopy.getPrice() << "\n";
    std::cout << "Pizza type: " << (pizza.getType() == FoodType::FOOD ? "FOOD" : "DRINK") << "\n";

    std::vector<FoodItem> menu = {pizza, burger, cola};

    // ===== Order Tests =====
    std::cout << "\n=== Order Tests ===\n";
    Order order1; // implicit
    order1.addItemToOrder(pizza);
    order1.addItemToOrder(cola);

    Order order2(2, Dif::MEDIUM, 90, {burger, cola});

    std::cout << "Order1:\n" << order1 << "\n";
    std::cout << "Order2:\n" << order2 << "\n";

    std::cout << "Order1 total: " << order1.calc() << " RON\n";
    std::cout << "Order2 total: " << order2.calc() << " RON\n";

    order1.setDifficulty(Dif::HARD);
    order1.setMaxDuration(120);
    std::cout << "Order1 after update:\n" << order1 << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(2LL));
    std::cout << "Order1 expired? " << (order1.hasExpired() ? "Yes" : "No") << "\n";

    // ===== Player Tests =====
    std::cout << "\n=== Player Tests ===\n";
    Player player("Catalin", 100.0f);

    player.setBalance(200.0f);
    player.addBalance(50.0f);
    std::cout << "Player balance: " << player.getBalance() << "\n";

    player.addOrder(order1);
    player.addOrder(order2);
    player.placeOrder(order1);
    player.finishOrder();

    std::cout << "Player info:\n" << player << "\n";

    // ===== Customer Tests =====
    std::cout << "\n=== Customer Tests ===\n";
    Customer customer(menu);
    std::cout<<customer.getName();
    std::cout << "Random Customer:\n" << customer << "\n";
    std::cout << "[Test] Se apeleaza constructorul de copiere (c2 = customer):\n";
    Customer customer2 = customer;
    customer2.getOrder().setDifficulty(Dif::EASY);
    std::cout << "Originalul (c1):\n" << customer << "\n";
    std::cout << "Copia (c2) (ar trebui sa aiba dificultate EASY):\n" << customer2 << "\n";

    std::cout << "[Test] Se apeleaza operatorul de atribuire (c3 = c1):\n";
    Customer customer3(menu);
    std::cout << "c3 INAINTE de atribuire:\n" << customer3 << "\n";
    customer3 = customer;
    std::cout << "c3 DUPA atribuire (arata ca originalul):\n" << customer3 << "\n";
    return 0;
}
