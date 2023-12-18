#ifndef Item_H
#define Item_H
#include <string>
using namespace std;

class Item
{
private:
    string itemName;
    int itemFreq;

public:
    Item();
    Item(string name, int freq);
    string getName();
    int getFreq();
    void setName(string name);
    void setFreq(int freq);
};
#endif