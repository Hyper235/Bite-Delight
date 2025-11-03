#include "../include/FoodItem.h"


//implicit

FoodItem::FoodItem() : id(0), name("Unknown"), price(0.0f),type(FoodType::UNDEFINED) {}

//parametrii
FoodItem::FoodItem(unsigned int i, const std::string n, float p, FoodType t)
    : id(i), name(n), price(p) , type(t){}

//operator <<
std::ostream& operator<<(std::ostream& os, const FoodItem& item) {
    os << "FoodItem [" << item.id << "] " << item.name << " - " << item.price << " RON\n";
    return os;
}

