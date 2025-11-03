//
// Created by Catalin on 10/29/2025.
//
#ifndef OOP_FOODITEM_H
#define OOP_FOODITEM_H

#include <string>
#include <iostream>
enum class FoodType {UNDEFINED,FOOD, DRINK};

class FoodItem {
protected:
    unsigned int id;
    std::string name;
    float price;
    FoodType type;
public:
    //implicit
    FoodItem();

    //parametric
    FoodItem(unsigned int id, const std::string& name, float price, FoodType type);

    //copy constructor
    FoodItem(const FoodItem& item);

    //getteri
    const std::string& getName() const { return name; }
    float getPrice() const { return price; }
    FoodType getType() const { return type;}

    //setteri
    void setName(const std::string& n) { name = n; }
    void setPrice(float p) { price = p; }

    //operator <<
    friend std::ostream& operator<<(std::ostream& os, const FoodItem& item);
};
#endif //OOP_FOODITEM_H