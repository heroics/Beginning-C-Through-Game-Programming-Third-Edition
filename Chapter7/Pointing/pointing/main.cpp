#include <iostream>
#include <string>

using namespace std;

int main()
{
    int *somePtr;
    int *scorePtr;
    int score = 1000;

    scorePtr = &score; // assign pointer scorePtr address of score;

    cout << "Assigning &score to scorePtr" << endl;
    cout << "&score is: " << &score << endl;
    cout << "scorePtr is: " << scorePtr << endl;
    cout << "*scorePtr is: " << *scorePtr << endl
         << endl;

    cout << "Adding 250 to the score";
    score += 500;
    cout << "score is " << score << endl;
    cout << "*scorePtr is: " << *scorePtr << endl;
    cout << "===============" << endl
         << endl;

    cout << "===============" << endl;
    cout << "Adding 500 to *pScore" << endl;
    *scorePtr += 500;
    cout << "score is: " << score << endl;
    cout << "*scorePtr: " << *scorePtr << endl;
    cout << "===============" << endl
         << endl;

    cout << "===============" << endl;
    int newScore = 5000;
    scorePtr = &newScore;

    cout << "Assigning &str to pStr\n";
    string str = "score";
    string *pStr = &str;
    //pointer to string object
    cout << "str is: " << str << endl;
    cout << "*pStr is: " << *pStr << endl;
    cout << "(*pStr).size() is: " << (*pStr).size() << endl;
    cout << "pStr->size() is: " << pStr->size() << endl;

    return 0;
}
