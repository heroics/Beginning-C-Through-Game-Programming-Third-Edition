#include <iostream>
#include <string>

int main()
{
    std::string username;
    std::string password;
    bool success = true;

    std::cout << "\tGame Designer's Network\n";

    while (success)
    {
        std::cout << "\nUsername: ";
        std::cin >> username;
        std::cout << "\nPassword: ";
        std::cin >> password;

        if (username == "S.Meier" && password == "civilization")
        {
            std::cout << "\nHey, Sid";
        }
        else if (username == "S.Miyamoto" && password == "Mariobros")
        {
            std::cout << "\nWhat's up Shigeru?";
        }
        else if (username == "W.Wright" && password == "thesims")
        {
            std::cout << "\nHow goes it Will?";
        }
        else if (username == "J.Hunt" && password == "blackdungeon")
        {
            std::cout << "\nWhat's good Jordan?";
        }
        else if (username == "guest" || password == "guest")
        {
            std::cout << "Welcome, guest";
        }
        else
        {
            std::cout << "Login failed.";
            success = false;
        }
    }
    return 0;
}
