// Hero's Inventory
// Demonstrates arrays

#include <iostream>
#include <string>

int main()
{
    const int MAXITEMS = 10;
    std::string inventory[MAXITEMS];

    int numItems = 0;
    inventory[numItems++] = "Everspark Blade";
    inventory[numItems++] = "Broken Armor";
    inventory[numItems++] = "Everspark Shield";

    std::cout << "Your items:\n";
    for (int i = 0; i < numItems; i++)
    {
        std::cout << inventory[i] << std::endl;
    }
    std::cout << "\nYou trade your Everspark Blade with an Ecko Spear\n";
    inventory[0] = "Ecko Spear";
    std::cout << "\nYour items:\n";
    for (int i = 0; i < numItems; i++)
    {
        std::cout << inventory[i] << std::endl;
    }
    std::cout << "\nYou found an old-world tome." << std::endl;
    if (numItems < MAXITEMS)
    {
        inventory[numItems++] = "Old-world Tome";
    }
    else
    {
        std::cout << "Inventory at maximum capacity";
    }
    std::cout << "\nYour items:\n";
    for (int i = 0; i < numItems; i++)
    {
        std::cout << inventory[i] << std::endl;
    }

    return 0;
}
