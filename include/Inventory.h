#ifndef OOP_INVENTORY_H
#define OOP_INVENTORY_H

#include <iostream>
#include <string>
#include <vector>

template <typename T> class Inventory {
private:
  std::vector<T> items;
  std::string name;

public:
  explicit Inventory(const std::string &inventoryName = "Generic Inventory")
      : name(inventoryName) {}

  const std::vector<T> &getItems() const { return items; }

  const std::string &getName() const { return name; }

  size_t getItemCount() const { return items.size(); }

  template <typename U>
  friend std::ostream &operator<<(std::ostream &os, const Inventory<U> &inv);
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Inventory<T> &inv) {
  os << "Inventory: " << inv.name << " (" << inv.getItemCount() << " items)\n";
  if (inv.items.empty()) {
    os << "  (Empty)\n";
  } else {
    for (const auto &item : inv.items) {
      os << "  - " << item << "\n";
    }
  }
  return os;
}

#endif // OOP_INVENTORY_H
