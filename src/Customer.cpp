#include "../include/Customer.h"
#include <random>

#define TIME_UNIT 30

Customer::Customer() : Name(generateRandomName()), mood(CustomerMood::WAITING) {
  order.addObserver(this);
}

Customer::Customer(const std::vector<FoodItem> &m)
    : Name(generateRandomName()), order(generateRandomOrder(m)),
      mood(CustomerMood::WAITING) {
  order.addObserver(this);
}

Customer::Customer(const std::string &n, const Order &o)
    : Name(n), order(o), mood(CustomerMood::WAITING) {
  order.addObserver(this);
}

Customer::Customer(const Customer &other)
    : Name(other.Name), order(other.order), mood(other.mood) {
  order.addObserver(this);
}

Customer::~Customer() = default;

Customer Customer::create(CustomerType type,
                            const std::vector<FoodItem> &menu) {
  (void)type;
  std::string name = generateRandomName();
  Order order = generateRandomOrder(menu);
  return Customer(name, order);
}

void Customer::update(Order *updatedOrder) {
  if (&order != updatedOrder)
    return;

  if (order.isComplete()) {
    mood = CustomerMood::HAPPY;
    std::cout << "[OBSERVER] Clientul " << Name << " este fericit!\n";
  } else if (order.hasExpired()) {
    mood = CustomerMood::ANGRY;
    std::cout << "[OBSERVER] Clientul " << Name << " este suparat!\n";
  }
}

Order Customer::generateRandomOrder(const std::vector<FoodItem> &menu) {
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
  } else if (random <= 60) {
    ord.setDifficulty(Dif::MEDIUM);
    int count = std::rand() % 3 + 3;
    for (int i = 0; i < count; i++) {
      int rindex = std::rand() % menu.size();
      ord.addItemToOrder(menu[rindex]);
    }
    ord.setMaxDuration(count * TIME_UNIT);
  } else {
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
      "Andrei",  "Maria",      "Ion",       "Elena",    "Alexandru",
      "Ioana",   "Gabriel",    "Ana",       "Mihai",    "Larisa",
      "Florin",  "Diana",      "Cristian",  "Raluca",   "Stefan",
      "Adina",   "Bogdan",     "Camelia",   "Vasile",   "Roxana",
      "George",  "Mihaela",    "Dan",       "Sorina",   "Radu",
      "Laura",   "Constantin", "Georgiana", "Petru",    "Simona",
      "Adrian",  "Monica",     "Victor",    "Oana",     "David",
      "Bianca",  "Matei",      "Daniela",   "Lucian",   "Teodora",
      "Ciprian", "Nicoleta",   "Vlad",      "Gabriela", "Tudor",
      "Andreea", "Darius",     "Paula"};
  int random = std::rand() % names.size();
  return names[random];
}

Customer &Customer::operator=(const Customer &other) {
  if (this == &other) {
    return *this;
  }
  order.removeObserver(this);
  this->Name = other.Name;
  this->order = other.order;
  this->mood = other.mood;
  order.addObserver(this);
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Customer &c) {
  os << "\nClient: " << c.Name;
  switch (c.mood) {
  case CustomerMood::WAITING:
    os << " (Asteapta)";
    break;
  case CustomerMood::HAPPY:
    os << " (Fericit)";
    break;
  case CustomerMood::ANGRY:
    os << " (Suparat)";
    break;
  }
  os << "\nOrder: " << c.order;
  return os;
}
