#include <iostream>
using namespace std;

bool gameContinue = true; // for while loop restriction
char winner;              // for winner character, value is set in function setWinner, 1 as O, 2 as X
int currentPlayer = 1;    // in the system, 1 is player O and 2 is player X

void Display(int input[][3])
{
    cout << "Press 0 to press row/column, Press 1 to set your choice.";
    if (currentPlayer == 1)
    {
        cout << "O turns!" << endl;
    }
    if (currentPlayer == 2)
    {
        cout << "X turns!" << endl;
    }

    for (int i = 0; i < 3; i++) // loop 3 rows of tic tac toe set,
    {
        char output[3];

        for (int j = 0; j < 3; j++)
        {
            if (input[i][j] == 1)
            {
                output[j] = 'O';
            }
            else if (input[i][j] == 2)
            {
                output[j] = 'X';
            }
            else
            {
                output[j] = '-';
            };
        }

        for (int j = 0; j < 3; j++)
        {
            cout << output[j] << " ";
        }
        cout << endl;
    };
};

void GetInput(int input[][3], int currentPlayer)
{
    int choice; // choice 0 is skip, choice 1 is set
    char playerSymbol = (currentPlayer == 1) ? 'O' : 'X';
    int row = 0; // choice row
    int col = 0; // choice column

    while (true)
    {
        if (input[row][col] == 0) // so if let's say 0,0 is taken, we will trigger the logic below which will increase the col++ and if it reaches 3 already, increase row
        {

            cout << "\n>> Current Cell: [" << row + 1 << ", " << col + 1 << "]: ";

            if (!(cin >> choice))
            {
                cout << "Invalid input! Please enter 0 or 1." << endl;
                cin.clear();
                continue;
            }

            if (choice == 1)
            {
                input[row][col] = currentPlayer;
                cout << "Move made at [" << row + 1 << ", " << col + 1 << "]." << endl;
                return;
            }

            else if (choice == 0)
            {
                cout << "Skipping cell [" << row + 1 << ", " << col + 1 << "]." << endl;
                Display(input);
            }

            else
            {
                cout << "Invalid choice. Enter 1 to select or 0 to skip." << endl;
                Display(input);
            }
        }

        col++;        // if skip, increase column
        if (col >= 3) // if column read 3, increase row by one
        {
            col = 0;
            row++;
            if (row >= 3)
            {
                row = 0; // if row reach 3 along with col reaching 3, reset back to 0, 0
            }
        }
    }
    return;
}

void RotatePlayer(int &currentPlayer) // easy swap with pointer memory address
{
    if (currentPlayer == 1)
    {
        currentPlayer = 2;
    }
    else
    {
        currentPlayer = 1;
    }
}

void setWinner(int input) // not much explain needed here, just a void function to set winner
{
    if (input == 1)
    {
        char winner = 'O';
        cout << winner << " has won the game. GG!" << endl;
    }
    if (input == 2)
    {
        char winner = 'X';
        cout << winner << " has won the game. GG!" << endl;
    }
}

void CheckWinner(int input[][3]) // this is the main logic house to determine the winner
{                                // note: I think the current solution is not too flexible and seem very bruteforce but I tried my best
    // for each horizontal, check
    for (int h = 0; h < 3; h++)
    {
        if (input[h][0] != 0 && input[h][0] == input[h][1] && input[h][1] == input[h][2])
        {
            setWinner(input[h][0]);
            gameContinue = false;
            return;
        };
    };

    // for each vertical, check
    for (int v = 0; v < 3; v++)
    {
        if (input[0][v] != 0 && input[0][v] == input[1][v] && input[1][v] == input[2][v])
        {
            setWinner(input[0][v]);
            gameContinue = false;
            return;
        };
    };

    // for diagonal idk how to spell
    // so matrix, if {0, 0}, {1, 1}, {2, 2} same value then win;
    if (input[0][0] != 0 && input[0][0] == input[1][1] && input[1][1] == input[2][2])
    {
        setWinner(input[0][0]);
        gameContinue = false;
        return;
    };

    // now for anti-diagonal
    // so matrix, {0, 2}, {1, 1}, {2, 0}, same value then winner is set;
    if (input[0][2] != 0 && input[0][2] == input[1][1] && input[1][1] == input[2][0])
    {
        setWinner(input[0][2]);
        gameContinue = false;
        return;
    };

    if (!winner) // this is when no winner is found yet.
    {
        bool boardFull = true; // a local variable here
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (input[i][j] == 0) // check if there's any 0 aka empty space left in the board
                {
                    boardFull = false; 
                }
            };
            if (!boardFull) // if false for our boardFull, then we go for another round
            {
                break;
            }
        }
        if (boardFull) // however somehow you got a full thing with no winner, you'll get a draw
        {
            gameContinue = false;
            cout << "Game is a draw. No winner!" << endl;
        }
        else // or else, we continue, best part
        {
            cout << "Game continue!" << endl;
            Display(input);
        }
    }
}

int main()
{
    int inputData[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
    };

    Display(inputData);

    while (gameContinue)
    {
        CheckWinner(inputData);
        if (!gameContinue)
        {
            break;
        };
        GetInput(inputData, currentPlayer);
        Display(inputData);
        RotatePlayer(currentPlayer);
    }

    return 0;
}