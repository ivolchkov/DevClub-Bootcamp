#include "Furniture.h"

Furniture::Furniture(const std::string& name, int price, Category* category) : Item(name, price, category) {};
Furniture::~Furniture() {};