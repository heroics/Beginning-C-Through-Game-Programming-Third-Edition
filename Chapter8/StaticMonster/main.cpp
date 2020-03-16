#include <iostream>
using namespace std;
class Monster
{
public:
    static int totalMonsters;
    Monster(int healthPoint = 0);
    static int getTotal();

private:
    int healthPoints;
};

int Monster::totalMonsters = 0;

Monster::Monster(int healthPoints)
{
    this->healthPoints = healthPoints;
    cout << "A Monster appears!" << endl;
    this->totalMonsters++;
}

int Monster::getTotal()
{
    return totalMonsters;
}

int main()
{
    cout << "The total number of monsters is: ";
    cout << Monster::totalMonsters << endl;

    Monster goblin1, goblin2, goblin3;
    cout << "The total number of monsters is: ";
    cout << Monster::getTotal() << endl;
    cout << Monster::totalMonsters << endl;
}