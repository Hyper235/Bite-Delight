//
// Created by Catalin on 12/3/2025.
//

#ifndef OOP_INGREDIENT_H
#define OOP_INGREDIENT_H
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
inline const char* toString(Ingredient ing) {
    switch (ing) {
        case Ingredient::BunBottom:    return "BunBottom";
        case Ingredient::Patty:        return "Patty";
        case Ingredient::Cheese:       return "Cheese";
        case Ingredient::Lettuce:      return "Lettuce";
        case Ingredient::Tomato:       return "Tomato";
        case Ingredient::Sauce:        return "Sauce";
        case Ingredient::BunTop:       return "BunTop";
        case Ingredient::Bacon:        return "Bacon";
        case Ingredient::Onion:        return "Onion";
        case Ingredient::Pickles:      return "Pickles";
        case Ingredient::Jalapeno:     return "Jalapeno";
        case Ingredient::ChickenPatty: return "ChickenPatty";
        case Ingredient::Egg:          return "Egg";
        default:                       return "Unknown";
    }
}
#endif //OOP_INGREDIENT_H