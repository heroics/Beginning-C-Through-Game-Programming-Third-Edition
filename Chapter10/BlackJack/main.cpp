// Blackjack
// Plays a simple version of the card game for 1 - 7 players
#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Card
{
public:
    enum Rank
    {
        ACE = 1,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING
    };
    enum Suit
    {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };
    // Overloading "<<" operator can send Card object to standard output
    friend ostream &operator<<(ostream &os, const Card &aCard);
    Card(Rank r = ACE, Suit s = SPADES, bool isFacingUp = true);
    // Returns the value of card
    int GetCardValue() const;
    // Flips a card, becomes face down or face up
    void Flip();

private:
    Rank rank;
    Suit suit;
    bool isFaceUp;
};
Card::Card(Rank r, Suit s, bool faceUp)
{
    rank = r;
    suit = s;
    isFaceUp = faceUp;
}
int Card::GetCardValue() const
{
    // If card is face down it's current value is 0
    int value = 0;
    if (isFaceUp)
    {
        // Card value is visible
        value = rank;
        // Value is greater than 10 it is a face card
        if (value > 10)
        {
            value = 10;
        }
    }
    return value;
}
void Card::Flip()
{
    isFaceUp != isFaceUp;
}
class Hand
{
public:
    Hand();
    virtual ~Hand();
    // Adds a card to hand
    void Add(Card *ptrCard);
    // Clears hand of all cards
    void Clear();
    // Get hand total value, intelligently treat aces as 1 or 11
    int GetTotal() const;

protected:
    vector<Card *> Cards;
};
Hand::Hand()
{
    Cards.reserve(7);
}
Hand::~Hand()
{
    Clear();
}

void Hand::Clear()
{
    //iterate through vector, freeing all memory on the heap
    vector<Card *>::iterator iter = Cards.begin();
    for (iter = Cards.begin(); iter != Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    //clear vector of pointers
    Cards.clear();
}
void Hand::Add(Card *ptrCard)
{
    Cards.push_back(ptrCard);
}
int Hand::GetTotal() const
{
    // if no cards in hard, return 0
    if (Cards.empty())
    {
        return 0;
    }
    // if a first card has value of 0, then card is face down, return 0
    if (Cards[0]->GetCardValue() == 0)
    {
        return 0;
    }
    // Add up values, treat each ace as 1
    int total = 0;
    vector<Card *>::const_iterator iter;
    for (iter = Cards.begin(); iter != Cards.end(); iter++)
    {
        total += (*iter)->GetCardValue();
    }
    // Determine if hand contains an ace
    bool containsAce = false;
    for (iter = Cards.begin(); iter != Cards.end(); iter++)
    {
        if ((*iter)->GetCardValue() == Card::ACE)
        {
            containsAce = true;
        }
    }
    // If the hand contains an ace and total is low enough treat, ace as 11
    if (containsAce && total <= 11)
    {
        // Add only 10 since were already add 1 for the ace
        total += 10;
    }
    return total;
}

class GenericPlayer : public Hand
{
    friend ostream &operator<<(ostream &os, const GenericPlayer &genericPlayer);

public:
    GenericPlayer(const string &name = "");
    virtual ~GenericPlayer();
    // Indicates if player wants to keep hitting
    virtual bool IsHitting() const = 0;
    // returns if generic player has busted (has 21 or greater)
    bool IsBusted() const;
    // Announces that the player generic player busted
    void Bust() const;

protected:
    string name;
};

GenericPlayer::GenericPlayer(const string &name)
{
    this->name = name;
}

GenericPlayer::~GenericPlayer() {}

bool GenericPlayer::IsBusted() const
{
    return (GetTotal() > 21);
}

void GenericPlayer::Bust() const
{
    cout << name << " busts." << endl;
}

class Player : public GenericPlayer
{
public:
    Player(const string &name = "");
    virtual ~Player();
    // returns whether or not the player wants another hit
    virtual bool IsHitting() const;
    // announces that the player wins
    void Win() const;
    // announces that the player loses
    void Lose() const;
    // announces that the player pushes
    void Push() const;
};
Player::Player(const string &name) : GenericPlayer(name) {}
Player::~Player()
{
}
bool Player::IsHitting() const
{

    cout << name << " do you want a hit (Y/N)";
    char reponse;
    cin >> reponse;
    return (reponse == 'y' || reponse == 'y');
}
void Player::Win() const
{
    cout << name << " wins." << endl;
}
void Player::Lose() const
{
    cout << name << " loses." << endl;
}
void Player::Push() const
{
    cout << name << " pushes" << endl;
}

class House : public GenericPlayer
{
public:
    House(const string &name = "House");
    virtual ~House();
    //indicates whether house is hitting - will always hit on 16 or less
    virtual bool IsHitting() const;
    //flips over first card
    void FlipFirstCard();
};
House::House(const string &name) : GenericPlayer(name)
{
}
House::~House()
{
}
bool House::IsHitting() const
{
    return (GetTotal() <= 16);
}
void House::FlipFirstCard()
{
    if (!(Cards.empty()))
    {
        Cards[0]->Flip();
    }
    else
    {
        cout << "No card to flip!" << endl;
    }
}
class Deck : public Hand
{
public:
    Deck();
    virtual ~Deck();
    //create a standard deck of 52 cards
    void Populate();
    //shuffle cards
    void Shuffle();
    //deal one card to a hand
    void Deal(Hand &aHand);
    //give additional cards to a generic player
    void AdditionalCards(GenericPlayer &genericPlayer);
};
Deck::Deck()
{
    Cards.reserve(52);
    Populate();
}
Deck::~Deck()
{
}
void Deck::Populate()
{
    Clear();
    //create standard deck
    for (int s = Card::CLUBS; s <= Card::SPADES; s++)
    {
        for (int r = Card::ACE; r <= Card::KING; r++)
        {
            Add(new Card(static_cast<Card::Rank>(r), static_cast<Card::Suit>(s)));
        }
    }
}
void Deck::Shuffle()
{
    random_shuffle(Cards.begin(), Cards.end());
}
void Deck::Deal(Hand &hand)
{
    if (!Cards.empty())
    {
        hand.Add(Cards.back());
        Cards.pop_back();
    }
    else
    {
        cout << "Out of cards. Unable to deal." << endl;
    }
}
void Deck::AdditionalCards(GenericPlayer &genericPlayer)
{
    cout << endl;
    // continue to deal a card as long as generic player isn’t busted and
    // wants another hit
    while (!(genericPlayer.IsBusted()) && genericPlayer.IsHitting())
    {
        Deal(genericPlayer);
        cout << genericPlayer << endl;
        if (genericPlayer.IsBusted())
        {
            genericPlayer.Bust();
        }
    }
}
class Game
{
public:
    Game(const vector<string> &names);
    ~Game();
    void Play();

private:
    Deck deck;
    House house;
    vector<Player> players;
};
Game::Game(const vector<string> &names)
{
    // Create a vector of players from vectors of names
    vector<string>::const_iterator ptrName;
    for (ptrName = names.begin(); ptrName != names.end(); ptrName++)
    {
        players.push_back(Player(*ptrName));
    }
}
Game::~Game()
{
}

void Game::Play()
{
    // deals two cards 2 all players
    vector<Player>::iterator ptrPlayer;
    for (int i = 0; i < 2; i++)
    {
        for (ptrPlayer = players.begin(); ptrPlayer != players.end(); ptrPlayer++)
        {
            deck.Deal(*ptrPlayer);
        }
        deck.Deal(house);
    }
    //hide the house's first card
    house.FlipFirstCard();

    // Display hand
    for (ptrPlayer = players.begin(); ptrPlayer != players.end(); ptrPlayer++)
    {
        cout << *ptrPlayer << endl;
    }
    cout << house << endl;

    // Deal Additional cards to players
    for (ptrPlayer = players.begin(); ptrPlayer != players.end(); ptrPlayer++)
    {
        deck.AdditionalCards(*ptrPlayer);
    }
    //reveal house’s first card
    house.FlipFirstCard();
    cout << endl
         << house;
    //deal additional cards to house
    deck.AdditionalCards(house);
    if (house.IsBusted())
    {
        //everyone still playing wins
        for (ptrPlayer = players.begin(); ptrPlayer != players.end();
             ++ptrPlayer)
        {
            if (!(ptrPlayer->IsBusted()))
            {
                ptrPlayer->Win();
            }
        }
    }
    else
    { //compare each player still playing to house
        for (ptrPlayer = players.begin(); ptrPlayer != players.end();
             ptrPlayer++)
        {
            if (!(ptrPlayer->IsBusted()))
            {
                if (ptrPlayer->GetTotal() > house.GetTotal())
                {
                    ptrPlayer->Win();
                }
                else if (ptrPlayer->GetTotal() < house.GetTotal())
                {
                    ptrPlayer->Lose();
                }
                else
                {
                    ptrPlayer->Push();
                }
            }
        }
    }
    for (ptrPlayer = players.begin(); ptrPlayer != players.end(); ptrPlayer++)
    {
        ptrPlayer->Clear();
    }
    house.Clear();
}

// function prototypes
ostream &operator<<(ostream &os, const Card &card);
ostream &operator<<(ostream &os, const GenericPlayer &genericPlayer);
int main()
{
    cout << "\t\tWelcome to Blackjack!\n"
         << endl;

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }
    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;
    //the game loop
    Game game(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        game.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }
    return 0;
}

//overloads << operator so Card object can be sent to cout
ostream &operator<<(ostream &os, const Card &card)
{
    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
                            "10", "J", "Q", "K"};
    const string SUITS[] = {"c", "d", "h", "s"};
    if (card.isFaceUp)
    {
        os << RANKS[card.rank] << SUITS[card.suit];
    }
    else
    {
        os << "XX";
    }
    return os;
}
//overloads << operator so a GenericPlayer object can be sent to cout
ostream &operator<<(ostream &os, const GenericPlayer &genericPlayer)
{
    os << genericPlayer.name << ":\t";
    vector<Card *>::const_iterator ptrCard;
    if (!genericPlayer.Cards.empty())
    {
        for (ptrCard = genericPlayer.Cards.begin(); ptrCard != genericPlayer.Cards.end(); ptrCard++)
        {
            os << *(*ptrCard) << "\t";
        }
        if (genericPlayer.GetTotal() != 0)
        {
            cout << "(" << genericPlayer.GetTotal() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }
    return os;
}