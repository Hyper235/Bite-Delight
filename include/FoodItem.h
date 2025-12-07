//
// Created by Catalin on 10/29/2025.
//
#ifndef OOP_FOODITEM_H
#define OOP_FOODITEM_H

#include <string>
#include <iostream>
#include <vector>
#include "Ingredient.h"
enum class FoodType {UNDEFINED,FOOD, DRINK};

class FoodItem {
protected:
    unsigned int id;
    std::vector<Ingredient> recipe;
    std::string name;
    float price;
    FoodType type;

public:
    FoodItem(): id(0), recipe{}, name("Undefined"), price(0.0f), type(FoodType::UNDEFINED) {}
    //parametric
    FoodItem(unsigned int id,const std::vector<Ingredient>& recipe, const std::string& name, float price, FoodType type);

    //copy constructor
    FoodItem(const FoodItem& item);

    //=
    FoodItem& operator=(const FoodItem& item) = default;

    //getteri
    const std::string& getName() const { return name; }
    float getPrice() const { return price; }
    unsigned int GetID() const{ return id;}
    const std::vector<Ingredient>& getRecipe() const{return recipe;}

    //setteri
    void setName(const std::string& n) { name = n; }
    //operator <<
    friend std::ostream& operator<<(std::ostream& os, const FoodItem& item);
};
#endif //OOP_FOODITEM_H