// Hero's Inventory 3.0
// Demonstrates iterators
#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::vector<std::string> inventory;
    inventory.push_back("Everspark Blade");
    inventory.push_back("Broken metal armor");
    inventory.push_back("Æther shield");
    std::vector<std::string>::iterator myIterator;
    std::vector<std::string>::const_iterator iter;
    std::cout << "Your items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }
    std::cout << "\nYou trade your blade for battle axe";
    myIterator = inventory.begin();
    *myIterator = "Everspark Axe";
    std::cout << "Your items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }
    std::cout << "\n The item name [" << *myIterator << "] has " << (*myIterator).size() << " letter in it.\n";
    std::cout << "\n The item name [" << *myIterator << "] has " << myIterator->size() << " letter in it.\n";
    std::cout << "\n You recover a crossbow from a slain enemy.";
    inventory.insert(inventory.begin(), "Old-world Shotgun");
    std::cout << "\n Your items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }
    std::cout << "\nYour armor is destoryed in a fierce battle.";
    inventory.erase((inventory.begin() + 2));
    std::cout << "\n Your items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }
    return 0;
}
