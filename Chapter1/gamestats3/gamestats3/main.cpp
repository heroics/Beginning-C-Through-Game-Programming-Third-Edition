// Game Stats 3.0
// Demonstrates constants

#include <iostream>
using namespace std;

int main()
{
    const int ALIEN_KILL_VALUE = 150;
    int aliensKilled = 10;
    int score = aliensKilled * ALIEN_KILL_VALUE;
    cout << "Score: " << score << endl;

    enum difficulty
    {
        NOVICE,
        EASY,
        NORMAL,
        HARD,
        UNBEATABLE,
    };

    difficulty gameDifficulty = EASY;

    enum shipCost
    {
        FIGHTER_COST = 25,
        BOMBER_COST,
        CRUISER_COST = 50,
        CRUSADER_COST = 75
    };

    shipCost gameShipCost = BOMBER_COST;
    cout << "\nTo upgrade my ship to a Cruiser it will cost " << (CRUISER_COST - gameShipCost) << " Resource points.";
}
