// Heap Data Member
// Demonstrates an object with a dynamically allocated data member
#include <iostream>
#include <string>
using namespace std;
class Monster
{
public:
    Monster(const string &name = "", int level = 0);
    ~Monster();                                     // Deconstructor
    Monster(const Monster &copyMonster);            // copy constructor prototype
    Monster &operator=(const Monster &copyMonster); // overloaded assignment operator
    void greet() const;

private:
    string *ptrName;
    int level;
};
Monster::Monster(const string &name, int level)
{
    cout << "----- Constructor called -----" << endl;
    ptrName = new string(name);
    this->level = level;
}
// Destructor Definition
Monster::~Monster()
{
    cout << "----- Deconstructor called -----" << endl;
    delete ptrName;
}
// Copy Constructor Definition
Monster::Monster(const Monster &copyMonster)
{
    cout << "----- Deconstructor called -----" << endl;
    ptrName = new string(*(copyMonster.ptrName));
    level = copyMonster.level;
}
// Overloaded Assignment Operation
Monster &Monster::operator=(const Monster &copy)
{
    cout << "----- Overloaded Assignment Operator called -----" << endl;
    if (this != &copy)
    {
        delete ptrName;
        ptrName = new string(*(copy.ptrName));
        level = copy.level;
    }
    return *this;
}
void Monster::greet() const
{
    cout << "Iz " << *ptrName << " nd Iz level " << level << " so watch out!" << endl;
    cout << "&ptrName: " << &ptrName << endl;
}
void testDestructor();
void testCopyConstructor(Monster copyMonster);
void testAssignmentOp();
int main()
{
    testDestructor();
    cout << endl;
    Monster goblin("Slica", 5);
    goblin.greet();
    testCopyConstructor(goblin);
    goblin.greet();
    cout << endl;
    testAssignmentOp();
    return 0;
}
void testDestructor()
{
    Monster goblin("Skippa", 3);
    goblin.greet();
}
void testCopyConstructor(Monster copyMonster)
{
    copyMonster.greet();
}
void testAssignmentOp()
{
    Monster goblin1("Rippa", 7);
    Monster goblin2("Stabba", 9);
    goblin1 = goblin2;
    goblin1.greet();
    goblin2.greet();
    cout << endl;
    Monster goblin3("GuffTuff Da Murdera", 69);
    goblin3 = goblin3;
    goblin3.greet();
}
