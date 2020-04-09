#include "Food.h"

Food::Food(const std::string& name, int price, Category* category) : Item(name, price, category) {};
Food::~Food() {};