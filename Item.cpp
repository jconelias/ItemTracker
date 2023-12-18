#include <iostream>
using namespace std;

#include "Item.h"

Item::Item()
{
    itemName = "";
    itemFreq = 0;
}
Item::Item(string name, int freq)
{
    itemName = name;
    itemFreq = freq;
}

string Item::getName()
{
    return itemName;
}

int Item::getFreq()
{
    return itemFreq;
}

void Item::setName(string name)
{
    itemName = name;
}

void Item::setFreq(int freq)
{
    itemFreq = freq;
}