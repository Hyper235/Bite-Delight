//
// Created by Catalin on 12/3/2025.
//

#ifndef OOP_INGREDIENT_H
#define OOP_INGREDIENT_H
#include <ostream>

enum class Ingredient {
  BunBottom,
  Patty,
  Cheese,
  Lettuce,
  Tomato,
  Sauce,
  BunTop,
  ChickenPatty,
  Egg,
  Bacon,
  Onion,
  Pickles,
  Jalapeno
};

// Overload operator<< for Ingredient enum class
inline std::ostream &operator<<(std::ostream &os,
                                const Ingredient &ingredient) {
  switch (ingredient) {
  case Ingredient::BunBottom:
    os << "BunBottom";
    break;
  case Ingredient::Patty:
    os << "Patty";
    break;
  case Ingredient::Cheese:
    os << "Cheese";
    break;
  case Ingredient::Lettuce:
    os << "Lettuce";
    break;
  case Ingredient::Tomato:
    os << "Tomato";
    break;
  case Ingredient::Sauce:
    os << "Sauce";
    break;
  case Ingredient::BunTop:
    os << "BunTop";
    break;
  case Ingredient::ChickenPatty:
    os << "ChickenPatty";
    break;
  case Ingredient::Egg:
    os << "Egg";
    break;
  case Ingredient::Bacon:
    os << "Bacon";
    break;
  case Ingredient::Onion:
    os << "Onion";
    break;
  case Ingredient::Pickles:
    os << "Pickles";
    break;
  case Ingredient::Jalapeno:
    os << "Jalapeno";
    break;
  default:
    os << "UnknownIngredient";
    break;
  }
  return os;
}

#endif // OOP_INGREDIENT_H