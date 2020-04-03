// Overriding Boss
// Demonstrates calling and overriding base member functions
#include <iostream>
using namespace std;
class Monster
{
public:
    Monster(int damage = 10);
    void virtual taunt() const; // made virtual to be overriden
    void virtual attack() const;

private:
    int damage;
};
 Monster::Monster(int damage){
damage = damage;
}
void Monster::taunt() const
{
    cout << "RAGHGH!!!" << endl;
}
void Monster::attack() const
{
    cout << "Attacks! Inflicts " << damage << " damage points." << endl;
}
class Boss : public Monster
{
public:
    Boss(int damage = 30);
    void virtual taunt() const;
    void virtual attack() const;
};
Boss::Boss(int damage) : Monster(damage)
{
}
void Boss::taunt() const
{
    cout << "Embrace the end!" << endl;
}
void Boss::attack() const
{
    Monster::attack();
    cout << " With magic!" << endl;
}
int main()
{
    cout << "|| Monster ||" << endl;
    Monster monster;
    monster.taunt();
    monster.attack();
    cout << "-- BOSS " << endl;
    Boss boss;
    boss.taunt();
    boss.attack();
}
