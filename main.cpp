#include <iostream>
using namespace std;

#include "ItemTracker.h"

int main()
{
    // Instantiate Item Tracker
    ItemTracker itemTracker;

    // Read Data From File
    itemTracker.readData();

    // Backup Data
    // itemTracker.saveData();

    while (true)
    {
        // Display Menu
        itemTracker.displayMenu();

        // Get Menu Input
        int inp;
        cin >> inp;
        cout << "\n";

        if (inp == 1)
        {
            cout << "Enter Item to Search: ";
            string item = "";
            cin >> item;
            itemTracker.findItem(item);
        }
        else if (inp == 2)
        {
            itemTracker.printList();
        }
        else if (inp == 3)
        {
            itemTracker.printHistogram();
        }
        else if (inp == 4)
        {
            cout << "\nGoodbye!\n";
            break;
        }
    }
    return 0;
}