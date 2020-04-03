// Simple Boss
// Demonstrates inheritance
#include <iostream>
using namespace std;
class Monster
{
public:
    int damage;
    Monster();
    void attack() const;
};
class BossMonster : public Monster
{
public:
    int damageMultiplier;
    BossMonster();
    void specialAttack() const;
};
Monster::Monster()
{
    damage = 10;
}
void Monster::attack() const
{
    cout << "Attack inflicts " << damage << " damage point!" << endl;
}
BossMonster::BossMonster()
{
    damageMultiplier = 3;
}
void BossMonster::specialAttack() const
{
    cout << "Special Attack inflicts " << (damageMultiplier * damage);
    cout << " damage points!" << endl;
}
int main()
{
    cout << "Creating a monster." << endl;
    Monster goblin;
    goblin.attack();
    cout << "Creating a boss monster." << endl;
    BossMonster goblinPrince;
    goblinPrince.attack();
    goblinPrince.specialAttack();
    return 0;
}