//
// Created by Catalin on 11/2/2025.
//
#include "../include/Customer.h"
#define TIME_UNIT 30
#include <random>
//implicit
Customer::Customer():Name(generateRandomName()){}

//parametric cu meniu
Customer::Customer(const std::vector<FoodItem>& m):
    Name(generateRandomName()),
    order(generateRandomOrder(m))

{}
//parametric
Customer::Customer(const std::string& n, const Order& o): Name(n), order(o) {}

//others
Order Customer::generateRandomOrder(const std::vector<FoodItem>& menu) {
    Order ord;
    int random = std::rand() % 100 + 1;

    if (random <= 30) {
        ord.setDifficulty(Dif::EASY);
        int count = std::rand() % 2 + 1;
        for (int i = 0; i < count; i++) {
            int rindex = std::rand() % menu.size();
            ord.addItemToOrder(menu[rindex]);
        }
        ord.setMaxDuration(count * TIME_UNIT);
    }
    else if (random <= 60) {
        ord.setDifficulty(Dif::MEDIUM);
        int count = std::rand() % 3 + 3;
        for (int i = 0; i < count; i++) {
            int rindex = std::rand() % menu.size();
            ord.addItemToOrder(menu[rindex]);
        }
        ord.setMaxDuration(count * TIME_UNIT);
    }
    else {
        ord.setDifficulty(Dif::HARD);
        int count = std::rand() % 4 + 5;
        for (int i = 0; i < count; i++) {
            int rindex = std::rand() % menu.size();
            ord.addItemToOrder(menu[rindex]);
        }
        ord.setMaxDuration(count * TIME_UNIT);
    }
    return ord;
}
std::string Customer::generateRandomName() {
    const std::vector<std::string> names = {
        "Andrei", "Maria", "Ion", "Elena", "Alexandru", "Ioana",
        "Gabriel", "Ana", "Mihai", "Larisa", "Florin", "Diana",
        "Cristian", "Raluca", "Stefan", "Adina", "Bogdan", "Camelia",
        "Vasile", "Roxana", "George", "Mihaela", "Dan", "Sorina",
        "Radu", "Laura", "Constantin", "Georgiana", "Petru", "Simona",
        "Adrian", "Monica", "Victor", "Oana", "David", "Bianca",
        "Matei", "Daniela", "Lucian", "Teodora", "Ciprian", "Nicoleta",
        "Vlad", "Gabriela", "Tudor", "Andreea", "Darius", "Paula"
    };
    int random = std::rand() % names.size();
    return names[random];
}
//copiere
Customer::Customer(const Customer& other)
    : Name(other.Name), order(other.order)
{}


//operator =
Customer& Customer::operator=(const Customer& other) {
    if (this == &other) {
        return *this;
    }
    this->Name = other.Name;
    this->order = other.order;
    return *this;

}
//<<
std::ostream& operator<<(std::ostream& os, const Customer& c) {
    os<<"\n Client:"<<c.Name<<"\n";
    os<<"\n Order:"<<c.order;
    return os;
}

