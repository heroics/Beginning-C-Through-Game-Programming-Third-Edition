// Lost Fortune
// A personalized adventure
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Constant Value for final reward
    const int GOLD_PIECES = 900;
    // Number of adventurers
    int adventurers;
    // Number of adventurers to be killed
    int killed;
    // Number of survivors
    int survivors;
    // player's class
    string playerClass;
    // player's name
    string playerName;
    // Get player information
    cout << "Welcome to Lost Fortune\n\n";
    cout << "Please enter the following for your personalized adventure\n";

    // Get player information
    cout << "Enter your last name: ";
    cin >> playerName;

    cout << "Enter your class: ";
    cin >> playerClass;

    // Get Data values
    cout << "Enter a number: ";
    cin >> adventurers;

    cout << "Enter a number, smaller than the first: ";
    cin >> killed;

    survivors = adventurers - killed;

    // Tell the story
    cout << "\nA brave group of " << adventurers << " set out on a quest ";
    cout << "-– in search of the lost treasure of the Ancient Dwarves. ";
    cout << "The group was led by that legendary , " << playerName << " " << playerName << ".\n";
    cout << "\nAlong the way, a band of marauding orgers ambushed the party.";
    cout << "All fought bravely under the command of " << playerName;
    cout << ", and the ogres were defeated but at a cost. ";
    cout << "Of the adventurers, " << killed << " were slain, ";
    cout << "leaving just " << survivors << "in the group.\n";

    cout << "\nThe party was about to give up all hope. ";
    cout << "But while laying the deceased to rest, ";
    cout << "they stumbled upon the buried fortune. ";
    cout << "So the adventurers split " << GOLD_PIECES << " gold pieces.";
    cout << playerName << " held on to the extra " << (GOLD_PIECES % survivors);
    cout << " pieces to keep things fair of course.\n";

    cout << "\n";
    return 0;
}
