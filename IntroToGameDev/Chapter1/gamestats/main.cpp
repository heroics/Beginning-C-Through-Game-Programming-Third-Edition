#include <iostream>

using namespace std;

int main()
{
    int score;
    double distance;
    char playAgain;
    bool isShieldsUp;
    short lives, aliensKilled;

    score = 0;
    distance = 1200.76;
    playAgain = 'y';
    isShieldsUp = true;
    lives = 3;
    aliensKilled = 10;

    double engineTemp = 6725.89;

    cout << "\nscore: " << score << endl;
    cout << "\ndistance: " << distance << endl;
    cout << "\nShields online: " << isShieldsUp << endl;
    cout << "\nlives left: " << lives << endl;
    cout << "\nengineTemp: " << engineTemp << endl;

    int fuel;
    cout << "\nHow much fuel? ";
    cin >> fuel;
    cout << "\nfuel level: " << fuel << endl;

    typedef unsigned short int ushort;
    ushort bonus = 10;
    cout << "\nbonus: " << bonus << endl;

    return 0;
}
