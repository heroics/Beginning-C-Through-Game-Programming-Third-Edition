#include <iostream>
#include <string>
using namespace std;

class Monster
{
public:
    int healthPoints;
    void Stats();
    string name;
};

void Monster::Stats()
{
    cout << "HP: " << this->healthPoints << " / " << this->healthPoints << endl;
};
int main()
{
    Monster goblin;
    goblin.healthPoints = 10;
    goblin.Stats();

    Monster merc;
    merc.healthPoints = 11;
    merc.Stats();

    return 0;
}
