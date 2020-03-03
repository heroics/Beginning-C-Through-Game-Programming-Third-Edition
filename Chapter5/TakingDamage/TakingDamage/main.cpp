#include <iostream>
using namespace std;
int shadowCurse(int health);
int main()
{
    int health = 80;
    cout << "Your health is " << health << endl;
    health = shadowCurse(health);
    cout << "Your health is " << health << endl;
    health = shadowCurse(health);
    cout << "Your health is " << health << endl;
    health = shadowCurse(health);
    return 0;
}
int shadowCurse(int health)
{
    return (health / 2);
}