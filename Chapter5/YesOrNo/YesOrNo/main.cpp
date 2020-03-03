#include <iostream>
#include <string>

char askYesNo1();
char askYesNo2(std::string question);

char askYesNo1()
{
    char reponse = ' ';
    while (reponse != 'y' && reponse != 'n')
    {
        std::cout << "Will you chronicle your efforts? (Y/N): ";
        std::cin >> reponse;
    }

    return reponse;
}

char askYesNo2(std::string question)
{
    char reponse = ' ';
    while (reponse != 'y' && reponse != 'n')
    {
        std::cout << question;
        std::cin >> reponse;
    }
    return reponse;
}
int main()
{
    char answer1 = askYesNo1();
    std::cout << "Thanks for answering: " << answer1 << std::endl;

    char answer2 = askYesNo2("Many have failed, will attempt to carry the ankh? (Y/N):");
    std::cout << "Thanks for answering: " << answer2 << std::endl;
}
