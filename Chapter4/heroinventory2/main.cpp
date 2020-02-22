// Hero's Inventory 2.0
// Demonstrates vectors
#include <iostream>
#include <string>
#include <vector>
int main()
{
   std::vector<std::string> inventory;
   inventory.push_back("Everspark Blade");
   inventory.push_back("broken metal armor");
   inventory.push_back("Everspark shield");
   std::cout << "You have " << inventory.size() << "items.\n";
   std::cout << "Your items:\n";
   for (int i = 0; i < inventory.size(); i++)
   {
      std::cout << inventory[i] << std::endl;
   }
   std::cout << "You trade your Everspark Blade for an Old-World Rifle";
   inventory.pop_back();
   inventory[0] = "Old-World Rifle";
   std::cout << "\n Your items:\n";
   for (int i = 0; i < inventory.size(); i++)
   {
      std::cout << inventory[i] << std::endl;
   }
   std::cout << "You have fallen into a dark cavern, you items have been ruined";
   inventory.clear();
   if (inventory.empty())
   {
      std::cout << "You have nothing.\n";
   }
}
