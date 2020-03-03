#include <iostream>

using namespace std;

int main()
{
    int myScore = 1000;
    int &otherScore = myScore; // Create a reference
    cout << "MyScore: is: " << myScore << endl;
    cout << "otherScore is: " << otherScore << "\n"
         << endl;
    cout << "Adding 500 to myScore" << endl;
    myScore += 500;
    cout << "myScore: " << myScore << endl;
    cout << "otherScore is: " << otherScore << "\n"
         << endl;
    cout << "Adding 500 to otherScore\n"
         << endl;
    otherScore += 500;
    cout << "myScore: " << myScore << endl;
    cout << "otherScore is: " << otherScore << "\n";
    

    return 0;
}
