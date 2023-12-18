#ifndef ItemTracker_H
#define ItemTracker_H
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class ItemTracker
{
private:
    // Item itemList[];
    vector<Item> itemList;

public:
    ItemTracker();
    void readData();
    void saveData();
    void displayMenu();
    int findItem(string name);
    void printList();
    void printHistogram();
};
#endif