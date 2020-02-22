// Hangman
// The classic of game of hangman

#include <algorithm>
#include <cctype>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
int main()
{
    // Setup
    const int MAXWRONG = 8; // maximum number of incorrect guess allowed

    std::vector<std::string> wordsToGuess; // collection of possible words to guess
    wordsToGuess.push_back("GUESS");
    wordsToGuess.push_back("HANGMAN");
    wordsToGuess.push_back("DIFFICULT");

    srand(static_cast<unsigned int>(time(0))); // Seed random generator
    std::random_shuffle(wordsToGuess.begin(), wordsToGuess.end());
    const std::string WORDTOGUESS = wordsToGuess[0]; // Word to guess
    int wrongGuesses = 0;                            // number of incorrect guesses
    std::string current(WORDTOGUESS.size(), '-');
    std::string lettersGuessed = "";

    std::cout << "Welcome to Hangman. Good luck!\n";

    // Game Loop
    while ((wrongGuesses < MAXWRONG) && (current != WORDTOGUESS))
    {
        std::cout << "\n\nYou have " << (MAXWRONG - wrongGuesses);
        std::cout << " incorrect guess left.\n";
        std::cout << "\nYou have used the following letters:\n"
                  << lettersGuessed << std::endl;

        // Get the player guess
        char playerGuess;
        std::cout << "\n\nEnter your guess: ";
        std::cin >> playerGuess;
        playerGuess = std::toupper(playerGuess);
        while (lettersGuessed.find(playerGuess) != std::string::npos)
        {
            std::cout << "\nYou've already guessed" << playerGuess << std::endl;
            std::cout << "Enter your guess: ";
            std::cin >> playerGuess;
            playerGuess = std::toupper(playerGuess);
        }
        lettersGuessed += playerGuess;

        if (WORDTOGUESS.find(playerGuess) != std::string::npos)
        {
            std::cout << "That's correct!" << playerGuess << " is in the word.\n";

            // Upadate current to include newly guessed letter
            for (int i = 0; i < WORDTOGUESS.length(); i++)
            {
                if (WORDTOGUESS[i] == playerGuess)
                {
                    current[i] = playerGuess;
                }
            }
        }
        else
        {
            std::cout << "Sorry, " << playerGuess << " is not in the word.\n";
            wrongGuesses++;
        }
    }
    // Shut down
    if (wrongGuesses == MAXWRONG)
    {
        std::cout << "\nYou've been hanged!";
    }
    else
    {
        std::cout << "\nThe word was " << WORDTOGUESS << std::endl;
    }

    return 0;
}
