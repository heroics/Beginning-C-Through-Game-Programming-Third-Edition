#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Returns a reference to a string
string &referenceToElement(vector<string> &inventory, int i);
int main()
{
    vector<string> inventory;
    inventory.push_back("Everpulse Blade");
    inventory.push_back("Everpulse Shield");
    inventory.push_back("Everpulse Armor");
    // Displays string that the returned refers to
    cout << "Sending the returned reference to cout:" << endl;
    cout << referenceToElement(inventory, 0) << endl;
    cout << "----------------" << endl;
    // Assign one reference to another -- inexpensive assignment
    cout << "Assigning the returned reference to another reference" << endl;
    string &rInventoryString = referenceToElement(inventory, 1);
    cout << "Sending the new reference to cout: " << endl;
    cout << rInventoryString << endl;
    cout << "----------------" << endl;
    // Copies a string object -- expensive assignment
    cout << "Assigning the returned refernce to a string object." << endl;
    string rInventoryString = referenceToElement(inventory, 2);
    cout << "Sending the new string object to cout:" << endl;
    cout << rInventoryString << endl;
    cout << "----------------" << endl;
    // Altering the string object through a returned reference
    cout << "Altering an object through a returned reference." rInventoryString = "Medical Serum";
    cout << "Sending the altered object to cout:" << endl;
    cout << inventory[1] << endl;
}
// Returns a reference to a string
string &referenceToElement(vector<string> &inventory, int i)
{
    return inventory[i];
}
