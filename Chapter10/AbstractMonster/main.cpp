// Abstract Creature
// Demonstrates abstract classes
#include <iostream>
using namespace std;

class Creature
{
public:
    Creature(int health = 100);
    virtual void Greet() const = 0;
    virtual void DisplayHealth() const;

protected:
    int health;
};
Creature::Creature(int health)
{
    this->health = health;
}
void Creature::DisplayHealth() const
{
    cout << "Health: " << health << "/" << health << endl;
}
class Orc : public Creature
{
public:
    Orc(int health = 120);
    virtual void Greet() const;
};
Orc::Orc(int health) : Creature(health) {}
void Orc::Greet() const
{

    cout << "The Orc pounds his chest in salute" << endl;
}
int main()
{
    Creature *ptrCreature = new Orc();
    ptrCreature->Greet();
    ptrCreature->DisplayHealth();
}