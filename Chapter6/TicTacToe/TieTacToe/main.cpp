#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * Global Constants
 */
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';
/*
 * Function Prototype
 */
bool isLegalMove(const vector<char> &gameBoard, int move);
char askYesOrNo(string question);
char humanPiece();
char opponentPiece(char piece);
char winner(const vector<char> &gameBoard);
int askNumber(string question, int high, int low = 0);
int computerMove(const vector<char> gameBoard, char move);
int humanMove(const vector<char> &gameBoard, char move);
void announceWinner(char winner, char computer, char human);
void displayBoard(const vector<char> &gameBoard);
void instructions();
int main()
{
    /*
     * Instance Variables
     */
    char computer = opponentPiece(human);
    char human = humanPiece();
    char turn = X;
    const int NUM_SQUARES = 9;
    int move;
    vector<char> board(NUM_SQUARES, EMPTY);
    /*
   * Introduce the player to the game
   */
    instructions();
    displayBoard(board);
    /*
   * Game Loop
   */
    while (winner(board) == NO_ONE)
    {
        if (turn == human)
        {
            move = humanMove(board, human);
            board[move] = human;
        }
        else
        {
            move = computerMove(board, computer);
            board[move] = computer;
        }
        displayBoard(board);
        turn = opponentPiece(turn);
    }
    announceWinner(winner(board), computer, human);
    return 0;
}
/**
 * This functions asks a yes or no question. It keeps asking the question until the player enters 'y' or an 'n'. It recives a question and return a 'y' or an 'n'
 *
 * @param question - a string question to ask the player
 *
 * @return - answer - a char of 'y' or 'n' based on player reponse.
 */
char askYesNo(string question)
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
 * This function displays the game instructions
 *
 * @param NONE
 *
 * @return NONE
 */
void instructions()
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
 * This function asks the player if they want to go first and returns the human's piece based on that choice. X goes first
 *
 * @param NONE
 *
 * @return - answer - an char of based on player reponse.
 */
char humanPiece()
{
    char goFirst = askYesNo("Do you require the first move?");
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
/**
 * This function displays the board passed to it.
 *
 * @param NONE
 *
 * @return NONE
 */
void displayBoard(const vector<char> &board)
{
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "\n\t --------" << endl;
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "\n\t --------" << endl;
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8] << endl;
}
/**
 * This function receives a board and returns the winner.
 *
 * @param NONE
 *
 * @return winner - A char that represents the winner. It could be X, Y, NO_ONE, or TIE.
 */
char winner(const vector<char> &board)
{
    const int TOTAL_ROWS = 8;
    const int WINNING_ROWS[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    for (int row = 0; row < TOTAL_ROWS; row++)
    {
        if ((board[WINNING_ROWS[row][0]] != EMPTY) &&
            (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
            (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
        {
            return board[WINNING_ROWS[row][0]];
        }
    }
    // check for a tie (no empty squares left)
    if (count(board.begin(), board.end(), EMPTY) == 0)
    {
        return TIE;
    }
    //If no one has won and it isn’t a tie, the game is still in session
    return NO_ONE;
}
/**
 * This function receives a board and a move. It returns true if the move is a legal one on the board or false if the move is not legal. A legal move is represented by the number of an empty square
 *
 * @param move - a player or computer move
 * @param &board - the reference to the game board
 *
 * @return - true or false based on the availability of a square
 */
inline bool isLegal(int move, const vector<char> &board)
{
    return (board[move] == EMPTY);
}
/**
 * This next function receives a board and the human’s piece. It returns the square number for where the player wants to move. The function asks the player for the square number to which he wants to move until the response is a legal move. Then the function returns the move.
 *
 * @param - &board - the reference to the game board
 * @param - human - the character representing for the player
 *
 * @return - move - the move by the human player
 */
int humanMove(const vector<char> &board, char human)
{
    int move = askNumber("Where will you move?", (board.size() - 1));
    while (!isLegal(move, board))
    {
        cout << "\nThat square is occupied, select a different one.";
        move = askNumber("Where will you move?", (board.size() - 1));
    }
    cout << "Your move has been placed.";
    return move;
}

int computerMove(vector<char> board, char computer)
{
    unsigned int move = 0;
    bool found = false;

    // If computer can win on next move, make that move
    while (!found && move < board.size())
    {
        if (isLegal(move, board))
        {
            board[move] = computer;
            found = winner(board) == computer;
            board[move] = EMPTY;
        }
        if (!found)
        {
            move++;
        }
    }

    // If the human can win on next move, make that move
    if (!found)
    {
        move = 0;
        char human = opponentPiece(computer);

        while (!found && move < board.size())
        {
            if (isLegal(move, board))
            {
                board[move] = computer;
                found = winner(board) == computer;
                board[move] = EMPTY;
            }
            if (!found)
            {
                move++;
            }
        }
    }

    // Otherwise, moving to the best open square is the move to make
    if (!found)
    {
        move = 0;
        unsigned int i = 0;
        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        while (!found && i < board.size())
        {
            move = BEST_MOVES[i];
            if (isLegal(move, board))
            {
                found = true;
            }
            ++i;
        }
    }
    cout << "The Machine take take square number " << move << endl;
    return move;
}

void announceWinner(char winner, char computer, char human)
{
    if (winner == computer)
    {
        cout << winner << "’s won!\n";
        cout << "As I predicted, human, I am triumphant once more. Earth is now doomed." << endl;
    }
    else if (winner == human)
    {
        cout << winner << "’s won!\n";
        cout << "You have won, humanity is safe for now." << endl;
    }
    else
    {
        cout << "It’s a tie." << endl;
        cout << "The worst possible outcome" << endl;
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
