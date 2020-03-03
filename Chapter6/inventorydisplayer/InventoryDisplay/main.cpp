#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function Prototypes
void displayInventory(const vector<string> &playerInventory);

int main()
{
    vector<string> inventory;
    inventory.push_back("Everpulse Sword");
    inventory.push_back("Everpulse Shield");
    inventory.push_back("Broken Leather Armor");

    displayInventory(inventory);

    return 0;
}

/**
 * This function displays the contents of the playerInventory
 *
 * @param inventory - vector is a constant reference to vector of player inventory
 *
 * @return void
 */
void displayInventory(const vector<string> &inventory)
{
    cout << "Your items: " << endl;
    for (vector<string>::const_iterator iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        // Dereference iter
        cout << *iter << endl;
    }
}
