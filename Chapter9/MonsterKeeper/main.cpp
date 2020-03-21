// Monster Keep
// Displays object containment
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Monster
{
public:
    Monster(const string &name = "");
    string getName() const;

private:
    string name;
};
Monster::Monster(const string &name)
{
    this->name = name;
}
inline string Monster::getName() const
{
    return name;
}
class Keep
{
public:
    Keep(int spaces = 1);
    void addMonster(const Monster &newMonster);
    void roleCall() const;

private:
    vector<Monster> monsters;
};
Keep::Keep(int spaces)
{
    monsters.reserve(spaces);
}
void Keep::addMonster(const Monster &newMonster)
{
    monsters.push_back(newMonster);
}
void Keep::roleCall() const
{
    for (vector<Monster>::const_iterator iter = monsters.begin(); iter != monsters.end(); iter++)
    {
        cout << iter->getName() << " iz 'ere.\n";
    }
}
int main()
{
    Monster nun("None The Wiser");
    cout << "The keeper of the monster's is " << nun.getName() << endl;
    cout << "// Creating Dungeon Keep //" << endl;
    Keep myKeep(3);
    cout << "Adding new golbins to the keep" << endl;
    myKeep.addMonster(Monster("Rippa"));
    myKeep.addMonster(Monster("Burna"));
    myKeep.addMonster(Monster("Sneaka"));
    cout << "// Calling Roll //" << endl;
    myKeep.roleCall();
}
