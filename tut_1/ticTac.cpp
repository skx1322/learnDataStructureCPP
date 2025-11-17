#include <iostream>
using namespace std;

bool gameContinue = true;
char winner;
int currentPlayer = 1;

void Display(int input[][3])
{
    if (currentPlayer == 1)
    {
        cout << "O turns!" << endl;
    }
    if (currentPlayer == 2)
    {
        cout << "X turns!" << endl;
    }
    for (int i = 0; i < 3; i++)
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

bool GetInput(int input[][3], int currentPlayer)
{
    int choice;
    char playerSymbol = (currentPlayer == 1) ? 'O' : 'X';
    int row = 0;
    int col = 0;

    while (true)
    {
        if (input[row][col] == 0)
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
                return true;
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

        col++;
        if (col >= 3) // if 2, 2 then return back to 0, 0
        {
            col = 0;
            row++;
            if (row >= 3)
            {
                row = 0;
            }
        }
    }
    return false;
}

void RotatePlayer(int &currentPlayer)
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

void setWinner(int input)
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

void CheckWinner(int input[][3])
{
    // check row winner, horizontal >>
    for (int h = 0; h < 3; h++)
    {
        if (input[h][0] != 0 && input[h][0] == input[h][1] && input[h][1] == input[h][2])
        {
            setWinner(input[h][0]);
            gameContinue = false;
            return;
        };
    };

    for (int v = 0; v < 3; v++)
    {
        if (input[0][v] != 0 && input[0][v] == input[1][v] && input[1][v] == input[2][v])
        {
            setWinner(input[0][v]);
            gameContinue = false;
            return;
        };
    };

    if (input[0][0] != 0 && input[0][0] == input[1][1] && input[1][1] == input[2][2])
    {
        setWinner(input[0][0]);
        gameContinue = false;
        return;
    };

    if (input[0][2] != 0 && input[0][2] == input[1][1] && input[1][1] == input[2][0])
    {
        setWinner(input[0][2]);
        gameContinue = false;
        return;
    };

    if (!winner)
    {
        bool boardFull = true;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (input[i][j] == 0)
                {
                    boardFull = false;
                }
            };
            if (!boardFull)
            {
                break;
            }
        }
        if (boardFull)
        {
            gameContinue = false;
            cout << "Game is a draw. No winner!" << endl;
        }
        else
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