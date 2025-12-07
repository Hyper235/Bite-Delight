#include "../include/Menu.h"

std::vector<FoodItem> Menu::menu = {

    // 1. Cheeseburger
    FoodItem{
        1,
        { Ingredient::BunBottom, Ingredient::Patty, Ingredient::Cheese, Ingredient::Sauce, Ingredient::BunTop },
        "Cheeseburger",
        18.0f,
        FoodType::FOOD
    },

    // 2. Bacon Burger
    FoodItem{
        2,
        { Ingredient::BunBottom, Ingredient::Patty, Ingredient::Cheese, Ingredient::Bacon,
          Ingredient::Lettuce, Ingredient::Tomato, Ingredient::Sauce, Ingredient::BunTop },
        "Bacon Burger",
        22.0f,
        FoodType::FOOD
    },

    // 3. Spicy Jalapeno Burger
    FoodItem{
        3,
        { Ingredient::BunBottom, Ingredient::Patty, Ingredient::Cheese, Ingredient::Jalapeno,
          Ingredient::Onion, Ingredient::Sauce, Ingredient::BunTop },
        "Spicy Jalapeno Burger",
        23.5f,
        FoodType::FOOD
    },

    // 4. Chicken Nugget Burger
    FoodItem{
        4,
        { Ingredient::BunBottom, Ingredient::ChickenPatty, Ingredient::Cheese,
          Ingredient::Lettuce, Ingredient::Sauce, Ingredient::BunTop },
        "Chicken Nugget Burger",
        20.0f,
        FoodType::FOOD
    },

    // 5. Deluxe Burger
    FoodItem{
        5,
        { Ingredient::BunBottom, Ingredient::Patty, Ingredient::Cheese, Ingredient::Bacon,
          Ingredient::Egg, Ingredient::Onion, Ingredient::Pickles, Ingredient::Sauce, Ingredient::BunTop },
        "Deluxe Burger",
        27.5f,
        FoodType::FOOD
    },
    FoodItem{
        6,
        {},
        "Cola",
        7.0f,
        FoodType::DRINK
    }

};

const std::vector<FoodItem>& Menu::getMenu() {
    return menu;
}
