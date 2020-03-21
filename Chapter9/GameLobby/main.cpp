// Monster Raid
// Simulates a group of Monsters preparing for a raid.
#include <iostream>
#include <string>
using namespace std;
class Monster
{
public:
    Monster(const string &name = "");
    string getName() const;
    Monster *getNext() const;
    void setNext(Monster *next);

private:
    string name;
    Monster *ptrNext; // Pointer to the next monster in list;
};
Monster::Monster(const string &name)
{
    this->name = name;
    this->ptrNext = 0;
}
string Monster::getName() const
{
    return name;
}
Monster *Monster::getNext() const
{
    return ptrNext;
}
void Monster::setNext(Monster *next)
{
    ptrNext = next;
}
class RaidGroup
{
    friend ostream &operator<<(ostream &os, const RaidGroup &raidGroup);

public:
    RaidGroup();
    ~RaidGroup();
    void addMonster();
    void removeMonster();
    void clear();
    int getRaiderCount() const;

private:
    Monster *ptrHead;
    int raiderCount = 0;
};
RaidGroup::RaidGroup()
{
    ptrHead = 0;
}
RaidGroup::~RaidGroup()
{
    clear();
}
void RaidGroup::addMonster()
{
    // Create a new monster node
    cout << "Please enter the name of the new monster: ";
    string monsterName;
    cin >> monsterName;
    Monster *ptrNewMonster = new Monster(monsterName);
    // If list is empty, make make of list the new player
    if (ptrHead == 0)
    {
        ptrHead = ptrNewMonster;
    }
    // otherwise find the end of the end list and add the player there
    else
    {

        Monster *ptrIter = ptrHead;
        while (ptrIter->getNext() != 0)
        {
            ptrIter = ptrIter->getNext();
        }
        ptrIter->setNext(ptrNewMonster);
    }
    raiderCount++;
}
void RaidGroup::removeMonster()
{
    if (ptrHead == 0)
    {
        raiderCount = 0;
        cout << "BOSS! WEZ AIN'T GOTZ NO RAIDAZ!";
    }
    else
    {
        Monster *ptrTemp = ptrHead;
        ptrHead = ptrHead->getNext();
        delete ptrTemp;
        raiderCount--;
    }
}
void RaidGroup::clear()
{
    while (ptrHead != 0)
    {
        removeMonster();
    }
}
int RaidGroup::getRaiderCount() const
{
    return raiderCount;
}
ostream &
operator<<(ostream &os, const RaidGroup &raidGroup)
{
    Monster *ptrIter = raidGroup.ptrHead;
    os << "BOSS! 'ERES OH WE GOT: " << endl;
    if (ptrIter == 0)
    {
        os << "BOSS! WEZ AIN'T GOTZ NO RAIDAZ" << endl;
    }
    else
    {
        while (ptrIter != 0)
        {
            os << ptrIter->getName() << " IZ 'ERE!" << endl;
            ptrIter = ptrIter->getNext();
        }
    }
    return os;
}

int main()
{
    RaidGroup myRaidGroup;
    int choice = -1;
    while (choice != 0)
    {
        cout << myRaidGroup;
        cout << endl
             << "+++ Raid Group +++ " << endl;
        cout << "0 - Exit the program." << endl;
        cout << "1 - Add a monster to the group." << endl;
        cout << "2 - Remove a monster from the group." << endl;
        cout << "3 - Clear the group." << endl;
        cout << endl
             << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            if (myRaidGroup.getRaiderCount() > 0)
            {
                cout << "WE ARE OFF TA RAID FOR YA BOSS!" << endl;
            }
            else
            {
                break;
            }
            break;
        case 1:
            myRaidGroup.addMonster();
            break;
        case 2:
            myRaidGroup.removeMonster();
            break;
        case 3:
            myRaidGroup.clear();
            break;

        default:
            cout << "BOSS! I DUN KNOW WHATZ YOU WANTZ ME TO DO!?! DON'T HIT ME!" << endl;
            break;
        }
    }
    return 0;
}