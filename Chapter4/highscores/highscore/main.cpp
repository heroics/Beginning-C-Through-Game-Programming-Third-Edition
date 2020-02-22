#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int>::const_iterator iter;
    std::cout << "Creating a list of scores" << std::endl;
    std::vector<int> scores;
    scores.push_back(1500);
    scores.push_back(3500);
    scores.push_back(7500);

    std::cout << "\nHigh scores:\n";
    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    std::cout << "\nFinding a score.";
    int score;
    std::cout << "\nEnter a score to find: ";
    std::cin >> score;
    iter = std::find(scores.begin(), scores.end(), score);
    if (iter != scores.end())
    {
        std::cout << "Score found.\n";
    }
    else
    {
        std::cout << "Score not found.\n";
    }

    std::cout << "\nRandomizing Scores.";
    srand(static_cast<unsigned int>(time(0)));
    std::random_shuffle(scores.begin(), scores.end());
    
    std::cout << "\nHigh scores:\n";
    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    return 0;
}
