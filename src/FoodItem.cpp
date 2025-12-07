#include "../include/FoodItem.h"


//parametrii
FoodItem::FoodItem(unsigned int i,const std::vector<Ingredient>& rec, const std::string& n, float p, FoodType t)
    : id(i),recipe(rec), name(n), price(p) , type(t){}

//copy
FoodItem::FoodItem(const FoodItem& item)
    : id(item.id),
      recipe(item.recipe),
      name(item.name),
      price(item.price),
      type(item.type)
{}

//operator <<
std::ostream& operator<<(std::ostream& os, const FoodItem& item) {
    os << "FoodItem [" << item.id << "] " << item.name << " - " << item.price << " RON\n";
    return os;
}

