#include "Inventory.hpp"

Inventory::Inventory()
{
    lst = new RandomObj *[3];
    stored = 0;
}

void Inventory::append(RandomObj *obj)
{
    lst[stored] = obj;
    stored++;
}

RandomObj *Inventory::remove()
{
    return lst[stored];
    stored--;
}

Inventory::~Inventory() {}
