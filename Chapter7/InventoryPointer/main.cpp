#include <iostream>
#include <string>
#include <vector>

using namespace std;

// returns a pointer to a string element
string *ptrToElement(vector<string> *const ptrString, int i);

int main()
{
    vector<string> inventory;
    inventory.push_back("Everpulse Blade");
    inventory.push_back("Everpulse armor");
    inventory.push_back("Everpulse Shield");

    // display string object that the returned pointer points to
    cout << "Sending the object pointed to by returned point pointer: " << endl;
    cout << *(ptrToElement(&inventory, 0)) << endl
         << endl;

    // Assigns one pointer to another -- inexpensive assignment
    cout << "Assigning the returned pointer to another pointer." << endl;
    string *ptrString = ptrToElement(&inventory, 1);
    cout << "Sending object pointed to by new pointer to cout:" << *ptrString << endl
         << endl;

    // copies a string object -- expensive assignment
    cout << "Assigning object pointed by pointer to a string." << endl;
    string myStr = *(ptrToElement(&inventory, 2));
    cout << "Sending the new string object to cout: " << endl;
    cout << myStr << endl
         << endl;

    // altering the string object through a returned pointer
    cout << "Altering an object through a returned pointer." << endl;
    *ptrString = "Water Song";
    cout << "Sending the altered object to cout: " << endl;
    cout << inventory[1] << endl;
}

string *ptrToElement(vector<string> *const ptrString, int i)
{
    // returns address of the string in position i of vector that ptrString points to
    return &((*ptrString)[i]);
}
