#include <iostream>
#include <vector>
#include <memory>

#include "include/Order.h"
#include "include/Player.h"
#include "include/WorkStation.h"
#include "include/OrderStation.h"
#include "include/GrillStation.h"
#include "include/BuildStation.h"
#include "include/ServeStation.h"

int main() {
    // jucătorul
    Player player("Catalin", 0.0f);

    // o comandă (poți folosi alt constructor dacă ai, de ex. cu FoodItem)
    Order order;   // folosește ctor implicit: id, tips=0, etc.

    // vector de pointeri la baza WorkStation
    std::vector<std::unique_ptr<WorkStation>> stations;

    // adăugăm stațiile concrete (derivate)
    stations.push_back(std::make_unique<OrderStation>());
    stations.push_back(std::make_unique<GrillStation>());
    stations.push_back(std::make_unique<BuildStation>());
    stations.push_back(std::make_unique<ServeStation>());

    std::cout << "\n=== Procesare comanda prin statii ===\n";

    // trimitem comanda prin toate stațiile
    for (auto &st : stations) {
        st->processAction(ActionType::None,nullptr,order, player);
    }

    std::cout << "\n=== Info player dupa comanda ===\n";
    std::cout << player << "\n";

    return 0;
}
