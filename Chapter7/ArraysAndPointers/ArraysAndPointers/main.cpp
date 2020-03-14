#include <iostream>

using namespace std;

void increase(int *const array, const int NUM_ELEMENTS);
void display(const int *const array, const int NUM_ELEMENTS);

int main()
{
    cout << "Create an array of high scores." << endl;
    cout << "-------------------------------" << endl;
    const int NUM_SCORES = 3;
    int highScores[NUM_SCORES] = {42069, 5000, 1337};

    cout << "Displaying score using array name as a constant pointer." << endl;
    // Displays highscores[0]
    cout << *highScores << endl;
    cout << *(highScores + 1) << endl;
    cout << *(highScores + 2) << endl;
    cout << "-------------------------------" << endl;
    cout << "Increasing your scores by passing array as a constant pointer." << endl;
    increase(highScores, NUM_SCORES);
    cout << "-------------------------------" << endl;
    cout << "Displaying scores by passing array as a constant pointer to a constant." << endl;
    display(highScores, NUM_SCORES);

    return 0;
}

void increase(int *const array, const int NUM_ELEMENTS)
{
    for (int i = 0; i < NUM_ELEMENTS; i++)
    {
        array[i] += 500;
    }
}

void display(const int *const array, const int NUM_ELEMENTS)
{
    for (int i = 0; i < NUM_ELEMENTS; i++)
    {
        cout << array[i] << endl;
    }
}