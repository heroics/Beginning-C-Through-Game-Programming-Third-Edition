#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
    // Get a random number between 1 and 20
    int d20 = (randomNumber % 20) + 1;
    if (d20 == 20)
    {
        std::cout << "CRITCAL HIT" << std::endl;
    }
    else
    {
        std::cout << "You rolled a " << d20 << std::endl;
    }
    return 0;
}
