#ifndef OOP_MENU_H
#define OOP_MENU_H

#include "FoodItem.h"
#include <vector>

class Menu {
public:
  static const std::vector<FoodItem> &getMenu();

private:
  static std::vector<FoodItem> menu;
};

#endif
