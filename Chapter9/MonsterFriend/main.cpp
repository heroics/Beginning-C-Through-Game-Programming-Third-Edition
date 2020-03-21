// Friendly Monster
// Demonstrates friend function and operator overloading
#include <iostream>
#include <string>
using namespace std;
class Monster
{
    // Global function friends of Monster Class
    friend void peek(const Monster &monster);
    friend ostream &operator<<(ostream &os, const Monster &monster);

public:
    Monster(const string &name = "");

private:
    string name;
};

Monster::Monster(const string &name) : name(name)
{
}

void peek(const Monster &monster);
ostream &operator<<(ostream &os, const Monster &monster);

int main()
{
    Monster goblin("Onun The Yzer");
    cout << "Calling peek() to access goblin's private data member, this->name: " << endl;
    peek(goblin);
    cout << "+++ Sending goblin object cout with the << operator: " << endl;
    cout << goblin;
}

// Global friend function which can access all of a Monster object's member
void peek(const Monster &monster)
{
    cout << monster.name << endl;
}

ostream &operator<<(ostream &os, const Monster &monster)
{
    os << "Monster Object - " << endl;
    os << "name: " << monster.name;
}