// Tic-Tac-Toe Version 2
// Plays the game of tic-tac-toe against computer opponent
// Uses pointers
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';
// Function Prototypes
bool isLegal(const vector<char> *const ptrBoard);
char askYesOrNo(string question);
char humanPiece();
char opponentPiece(char piece);
char winner(const vector<char> *const ptrBoard);
int askNumber(string question, int high, int low = 0);
int computerMove(vector<char> board, char computer);
int humanMove(const vector<char> *const ptrBoard, char human);
void announceWinner(char winner, char computer, char human);
void displayGameboard(const vector<char> *const ptrBoard);
void insturctions();
int main()
{
    char human = humanPiece();
    char computer = opponentPiece(human);
    char turn = X;
    const int NUM_SQUARES = 9;
    int move;
    vector<char> gameBoard(NUM_SQUARES, EMPTY);
    // Setup Game
    insturctions();
    displayGameboard(&gameBoard);
    // Game Loop
    while (winner(&gameBoard) == NO_ONE)
    {
        if (turn == human)
        {
            move = humanMove(&gameBoard, human);
            gameBoard[move] = human;
        }
        else
        {
            move = computerMove(gameBoard, computer);
            gameBoard[move] = computer;
        }
        displayGameboard(&gameBoard);
        turn = opponentPiece(turn);
    }
    announceWinner(winner(&gameBoard), computer, human);
    return 0;
}
/**
 * This function displays the game instructions
 *
 * @param NONE
 *
 * @return NONE
 */
void insturctions()
{
    cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe." << endl;
    cout << "The human will is pit against silicon skill." << endl;
    cout << "Select your move by entering a number 0-8." << endl;
    cout << "The number corresponds to the desired board position as shown below." << endl;
    cout << " 0 | 1 | 2 " << endl;
    cout << " ----------" << endl;
    cout << " 3 | 4 | 5 " << endl;
    cout << " ----------" << endl;
    cout << " 6 | 7 | 8 " << endl;
    cout << "\nThe fate of your species will be seal in this battle!" << endl;
}
/**
 * This functions asks a yes or no question. It keeps asking the question until the player enters 'y' or an 'n'. It recives a question and return a 'y' or an 'n'
 *
 * @param question - a string question to ask the player
 *
 * @return - answer - a char of 'y' or 'n' based on player reponse.
 */
char askYesOrNo(string question)
{
    char reponse;
    while (reponse != 'y' && reponse != 'n')
    {
        cout << question << "(y/n): ";
        cin >> reponse;
    }
    return reponse;
}
/**
 * This functions asks for a number within a range and keeps asking until the player enters a valid number. It keeps asking the question until the player a valid number within the range. It recives a question and returns some number input'
 *
 * @param question - a string question to ask the player
 * @param lowNumber - a lower bound (inclusive) for a number range
 * @param highNumber - a higher bound (inclusive) for a number range
 *
 * @return - answer - an int of based on player reponse.
 */
int askNumber(string question, int high, int low)
{
    int number;
    do
    {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while (number > high || number < low);
    return number;
}
/**
 * This function asks the player if they want to go first and returns the human's piece based on that choice. X goes first
 *
 * @param NONE
 *
 * @return - answer - an char of based on player reponse.
 */
char humanPiece()
{
    char goFirst = askYesOrNo("Do you require the first move?");
    if (goFirst == 'y')
    {
        cout << "\nTake take the first move. Humanity rests in your hands." << endl;
        return X;
    }
    else
    {
        cout << "\nYou made a poor choice. The machine will take first move.";
        return O;
    }
}
char opponentPiece(char piece)
{
    if (piece == X)
    {
        return O;
    }
    else
    {
        return X;
    }
}

void displayGameboard(const vector<char> *const pBoard)
{
    cout << "\n\t" << (*pBoard)[0] << " | " << (*pBoard)[1] << " | " << (*pBoard)[2];
    cout << "\n\t"
         << "---------";
    cout << "\n\t" << (*pBoard)[3] << " | " << (*pBoard)[4] << " | " << (*pBoard)[5];
    cout << "\n\t"
         << "---------";
    cout << "\n\t" << (*pBoard)[6] << " | " << (*pBoard)[7] << " | " << (*pBoard)[8];
    cout << "\n\n";
}

char winner(const vector<char> *const pBoard)
{
    // all possible winning rows
    const int WINNING_ROWS[8][3] = {{0, 1, 2},
                                    {3, 4, 5},
                                    {6, 7, 8},
                                    {0, 3, 6},
                                    {1, 4, 7},
                                    {2, 5, 8},
                                    {0, 4, 8},
                                    {2, 4, 6}};
    const int TOTAL_ROWS = 8;

    // if any winning row has three values that are the same (and not EMPTY),
    // then we have a winner
    for (int row = 0; row < TOTAL_ROWS; ++row)
    {
        if (((*pBoard)[WINNING_ROWS[row][0]] != EMPTY) &&
            ((*pBoard)[WINNING_ROWS[row][0]] == (*pBoard)[WINNING_ROWS[row][1]]) &&
            ((*pBoard)[WINNING_ROWS[row][1]] == (*pBoard)[WINNING_ROWS[row][2]]))
        {
            return (*pBoard)[WINNING_ROWS[row][0]];
        }
    }

    // since nobody has won, check for a tie (no empty squares left)
    if (count(pBoard->begin(), pBoard->end(), EMPTY) == 0)
        return TIE;

    // since nobody has won and it isn't a tie, the game ain't over
    return NO_ONE;
}

inline bool isLegal(int move, const vector<char> *pBoard)
{
    return ((*pBoard)[move] == EMPTY);
}

int humanMove(const vector<char> *const pBoard, char human)
{
    int move = askNumber("Where will you move?", (pBoard->size() - 1));
    while (!isLegal(move, pBoard))
    {
        cout << "\nThat square is already occupied, foolish human.\n";
        move = askNumber("Where will you move?", (pBoard->size() - 1));
    }
    cout << "Fine...\n";
    return move;
}

int computerMove(vector<char> board, char computer)
{
    unsigned int move = 0;
    bool found = false;

    //if computer can win on next move, that�s the move to make
    while (!found && move < board.size())
    {
        if (isLegal(move, &board))
        {
            //try move
            board[move] = computer;
            //test for winner
            found = winner(&board) == computer;
            //undo move
            board[move] = EMPTY;
        }

        if (!found)
        {
            ++move;
        }
    }

    //otherwise, if opponent can win on next move, that's the move to make
    if (!found)
    {
        move = 0;
        char human = opponentPiece(computer);

        while (!found && move < board.size())
        {
            if (isLegal(move, &board))
            {
                //try move
                board[move] = human;
                //test for winner
                found = winner(&board) == human;
                //undo move
                board[move] = EMPTY;
            }

            if (!found)
            {
                ++move;
            }
        }
    }

    //otherwise, moving to the best open square is the move to make
    if (!found)
    {
        move = 0;
        unsigned int i = 0;

        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        //pick best open square
        while (!found && i < board.size())
        {
            move = BEST_MOVES[i];
            if (isLegal(move, &board))
            {
                found = true;
            }

            ++i;
        }
    }

    cout << "I shall take square number " << move << endl;
    return move;
}

void announceWinner(char winner, char computer, char human)
{
    if (winner == computer)
    {
        cout << winner << "'s won!\n";
        cout << "As I predicted, human, I am triumphant once more -- proof\n";
        cout << "that computers are superior to humans in all regards.\n";
    }

    else if (winner == human)
    {
        cout << winner << "'s won!\n";
        cout << "No, no!  It cannot be!  Somehow you tricked me, human.\n";
        cout << "But never again!  I, the computer, so swear it!\n";
    }

    else
    {
        cout << "It's a tie.\n";
        cout << "You were most lucky, human, and somehow managed to tie me.\n";
        cout << "Celebrate... for this is the best you will ever achieve.\n";
    }
}
