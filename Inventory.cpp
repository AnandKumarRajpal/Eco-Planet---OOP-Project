#include "Inventory.hpp"

Inventory::Inventory()
{
    lst = new GameObject *[3];
    stored = 0;
}

void Inventory::append(GameObject *obj)
{
    lst[stored] = obj;
    stored++;
}

GameObject *Inventory::remove()
{
    return lst[stored];
    stored--;
}

Inventory::~Inventory() {}
