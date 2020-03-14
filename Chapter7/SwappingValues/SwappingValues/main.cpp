#include <iostream>

using namespace std;

void badSwap(int x, int y);
void goodSwap(int *const x, int *const y);

int main()
{
    int myScore = 1500;
    int otherScore = 1000;
    cout << "Original values" << endl;
    cout << "\n-------------" << endl;
    cout << "myScore: " << myScore << endl;
    cout << "otherScore: " << otherScore << endl;
    cout << "-------------" << endl;
    cout << "+ Calling badSwap() +" << endl;
    badSwap(myScore, otherScore);
    cout << "myScore: " << myScore << endl;
    cout << "otherScore: " << otherScore << endl;
    cout << "\n-------------" << endl;
    cout << "+ Calling goodSwap() +" << endl;
    goodSwap(&myScore, &otherScore);
    cout << "myScore: " << myScore << endl;
    cout << "otherScore: " << otherScore << endl;
    cout << "\n-------------" << endl;

    return 0;
}

void badSwap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void goodSwap(int *const x, int *const y)
{
    // Store the value pointed to by X into temp
    int temp = *x;
    // Store the value pointed by Y in the address pointed by X
    *x = *y;
    // Store the value pointed by X into address pointed by y
    *y = temp;
}