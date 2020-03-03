#include <iostream>

using namespace std;

void badSwap(int x, int y);
void goodSwap(int &x, int &y);

int main()
{
    int myScore = 150;
    int otherScore = 1000;

    cout << "Original values" << endl;
    cout << "myScore: " << myScore << endl;
    cout << "otherScore: " << otherScore << endl;

    cout << "------------------" << endl;
    cout << "Calling BadSwap()" << endl;
    cout << "------------------" << endl;
    badSwap(myScore, otherScore);
    cout << "myScore: " << myScore << endl;
    cout << "otherScore: " << otherScore << endl;

    cout << "------------------" << endl;
    cout << "Calling GoodSwap()" << endl;
    cout << "------------------" << endl;
    goodSwap(myScore, otherScore);
    cout << "myScore: " << myScore << endl;
    cout << "otherScore: " << otherScore << endl;

    return 0;
}

void badSwap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void goodSwap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}