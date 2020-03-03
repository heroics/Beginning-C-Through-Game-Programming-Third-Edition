#include <iostream>

using namespace std;

// function prototype
void function();

int main()
{
    int var = 5;
    cout << "In main() var is: " << var << "\n\n";
    function();
    cout << "Back in main() var is: " << var << "\n\n";
    {
        cout << "in main() in a new scope: " << var << "\n\n";
        cout << "Creating a new var in the scope.\n";
        int var = 10; // variable in the new scope hides other variable named var
        cout << "In main() in a new scope var is: " << var << "\n\n";
    }
    cout << "At end of main() var created in new scope no longer exists.\n";
    cout << "At end of main() var is: " << var << "\n";
    return 0;
}
void function()
{
    int var = -5; // local variable in func()
    cout << "In func() var is: " << var << "\n\n";
}
