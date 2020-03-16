// Private Monster
// Demonstrates setting member access levels
#include <iostream>
using namespace std;

class Monster
{
public:
    Monster(int healthPoints = 0);
    int getHealthPoints() const;
    void setHealthPoints(int healthPoints);

private:
    int healthPoints;
};
Monster::Monster(int healthPoints)
{
    this->healthPoints = healthPoints;
}
int Monster::getHealthPoints() const
{
    return this->healthPoints;
}
void Monster::setHealthPoints(int healthPoints)
{
    if (healthPoints < 0)
    {
        cout << "[ERROR] - HEALTHPOINTS MUST BE NON-NEGATIVE NUMBER" << endl;
    }
    else
    {
        this->healthPoints = healthPoints;
    }
}
int main()
{
    Monster goblin(1);
    cout << "Calling getHealthPoints(): [" << goblin.getHealthPoints() << "]" << endl;
    cout << "Calling setHealthPoints() with -7" << endl;
    goblin.setHealthPoints(-7);
    cout << "Calling setHealthPoints with 7" << endl;
    goblin.setHealthPoints(7);
    cout << "Calling getHealthPoints(): [" << goblin.getHealthPoints() << "]" << endl;
    return 0;
}
