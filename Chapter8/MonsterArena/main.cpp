// Monster Arena
// Simulates training a mini-boss
#include <iostream>
using namespace std;
class Monster
{
public:
    Monster(int healthPoints = 0, int powerLevel = 0);
    void talk();
    void train(int restoreHealthPoints = 4);
    void battle(int heroLevel = 4);

private:
    int healthPoints;
    int powerLevel;
    int getReadiness;
    int getReadiness() const;
    void passTime(int time = 1);
};

Monster::Monster(int healthPoints, int powerLevel)
{
    this->healthPoints = healthPoints;
    this->powerLevel = powerLevel;
}

/**
 * This function returns a value representing their readiness for battle. The higher the value the greater the readiness
 *
 * @param None
 *
 * @return - a value representing current 
 */
inline int Monster::getReadiness() const
{
    return (healthPoints + powerLevel);
}
/**
 * This function restores the healthpoints of a monster. If they restore more HP then their current max value increase their powerlevel
 *
 * @param None
 *
 * @return - a value representing current 
 */
void Monster::train(int restoreHP)
{
    cout << "I SHALL BECOME STRONGER";
    this->healthPoints += restoreHP;
    if (restoreHP >= healthPoints)
    {
        this->powerLevel++;
    }
    passTime();
}
void Monster::passTime(int time)
{
    this->healthPoints -= time;
}