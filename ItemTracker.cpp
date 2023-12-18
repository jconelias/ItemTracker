#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

#include "ItemTracker.h"

ItemTracker::ItemTracker()
{
}

void ItemTracker::readData()
{
    // Declare Files
    ifstream inpFile("input.txt");

    if (inpFile.is_open())
    {
        // Declare Variables
        string line;
        bool dup = false;
        int index = -1;

        // Read File
        while (getline(inpFile, line))
        {
            // Check if Item Exists
            for (int i = 0; i < itemList.size(); ++i)
            {
                // Item Exists
                if (itemList[i].getName().compare(line) == 0)
                {
                    dup = true;
                    index = i;
                }
            }

            // Add New Item
            if (!dup)
            {
                itemList.push_back(Item(line, 1));
            }

            // Increment Item Frequency
            else
            {
                itemList[index].setFreq(itemList[index].getFreq() + 1);
            }

            // Reset Variables
            index = -1;
            dup = false;
        }

        // Close Input File
        inpFile.close();
    }

    // Detect Error Reading File
    else
    {
        cout << "Error: File not Found" << endl;
    }
}

int ItemTracker::findItem(string name)
{
    for (int i = 0; i < itemList.size(); ++i)
    {
        if (itemList[i].getName() == name)
        {
            cout << itemList[i].getFreq() << endl;
            return itemList[i].getFreq();
        }
        else
        {
            cout << "No Item with the Specified Name Found. (Note: Case Sensitive!)" << endl;
            return 0;
        }
    }
    return 0;
}

void ItemTracker::displayMenu()
{
    cout << "\nCorner Grocer Item Tracker" << endl;
    cout << "======================================================================" << endl;
    cout << "1. Find Item (Returns Frequency)" << endl;
    cout << "2. Print Item List" << endl;
    cout << "3. Print Item List (Histogram)" << endl;
    cout << "4. Exit" << endl;
}

void ItemTracker::printList()
{
    for (int i = 0; i < itemList.size(); ++i)
    {
        cout << itemList[i].getName() << " " << itemList[i].getFreq() << endl;
    }
}

void ItemTracker::printHistogram()
{
    for (int i = 0; i < itemList.size(); ++i)
    {
        cout << itemList[i].getName() << " ";
        for (int j = 0; j < itemList[i].getFreq(); j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

void ItemTracker::saveData()
{
    ofstream outFile("frequency.dat", ios::binary);
    if (outFile.is_open())
    {
        // outFile.write(itemList, itemList.size() * 128);
        outFile.close();
    }
    else
    {
        cout << "Error Backing Up Data...";
    }
}