#include <cstdlib>
#include <ctime>
#include <iostream>
int main()
{
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Select a random number
    int numberToGuess = rand() % 100 + 1;
    int numPlayerGuesses = 0;
    int playerGuess = 0;

    std::cout << "\tWelcome To Guess My Number\n\n";

    while (playerGuess != numberToGuess)
    {
        std::cout << "Enter a guess: ";
        std::cin >> playerGuess;
        numPlayerGuesses++;
        if (playerGuess > numberToGuess)
        {
            std::cout << "Too high!\n\n";
        }
        else if (playerGuess < numberToGuess)
        {
            std::cout << "Too low\n\n";
        }
        else
        {
            std::cout << "That's it! You guessed it in " << numPlayerGuesses << " guesses!\n";
            if (numberToGuess == 69)
            {
                std::cout << "NICE!" << std::endl;
            }
        }
    }
    return 0;
}
