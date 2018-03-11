#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

void printBoard(char board[3][3]);
bool checkWinner(char player, char board[3][3]);
bool checkPlayAgain();

int main()
{
	//While loop used to reset values if players want to play again
	while (true)
	{
		char currentPlayer = 'x';
		bool invalidMove = false;

		//Board with spaces as empty slot placeholders
		char board[3][3] = {
			{ ' ', ' ', ' ' },
			{ ' ', ' ', ' ' },
			{ ' ', ' ', ' ' }
		};

		//While game is in a session
		while (true)
		{
			bool turnEnd = false;
			printBoard(board);

			//If invalidMove value is true print message to screen
			if (invalidMove)
			{
				cout << endl << " ===============================" << endl;
				cout << " ||        INVALID MOVE       ||" << endl;
			}

			invalidMove = false;
			cout << " ===============================" << endl;
			cout << " ||      Player " << currentPlayer << "'s turn      ||" << endl;
			cout << " ===============================" << endl << endl;

			//Prompt user to input position of marker by row and column
			cout << "     Pick a row: ";
			char row = _getch();
			while (row < 49 || row > 51)
			{
				cout << endl << "     Pick a valid row (1, 2, 3): ";
				row = _getch();
			}
			cout << row << endl;

			cout << "     Pick a column: ";
			char col = _getch();
			while (col < 49 || col > 51)
			{
				cout << endl << "     Pick a valid column (1, 2, 3): ";
				col = _getch();
			}
			cout << col << endl << endl << endl;


			//Check if board space is empty
			if (board[row - 49][col - 49] == ' ')
			{
				//Set player marker in the position the player selected
				board[row - 49][col - 49] = currentPlayer;
				turnEnd = true;

				//Call checkWinner bool function to check if there is a winner
				//Break while loop and end round
				if (checkWinner(currentPlayer, board) == true)
					break;

				//Switch players after a turn is up
				if (currentPlayer == 'x')
				{
					currentPlayer = 'o';
				}
				else
				{
					currentPlayer = 'x';
				}
			}
			else
			{
				//Repeat turn if selected position of marker is invalid
				invalidMove = true;
				turnEnd = false;
			}
		}

		//Ask players if they want to play another round
		if (checkPlayAgain())
		{
			cout << " ===============================" << endl;
			cout << " ||     STARTING NEW GAME     ||" << endl;
			cout << " ===============================" << endl << endl;
		}
		else
		{
			return(0);
		}
	}

	_getch();
}

void printBoard(char board[3][3])
{
	cout << "      |         COLUMN" << endl;
	cout << "      |    1       2       3" << endl;
	cout << " -------------------------------" << endl;
	cout << "      |        |       |       " << endl;
	cout << "   1  |    " << board[0][0] << "   |   " << board[0][1] << "   |   " << board[0][2] << "    " << endl;
	cout << "      |        |       |   " << endl;
	cout << "      | -----------------------" << endl;
	cout << " R    |        |       |   " << endl;
	cout << " O 2  |    " << board[1][0] << "   |   " << board[1][1] << "   |   " << board[1][2] << "    " << endl;
	cout << " W    |        |       |   " << endl;
	cout << "      | -----------------------" << endl;
	cout << "      |        |       |   " << endl;
	cout << "   3  |    " << board[2][0] << "   |   " << board[2][1] << "   |   " << board[2][2] << "    " << endl;
	cout << "      |        |       |       " << endl << endl;
}

bool checkWinner(char player, char board[3][3])
{
	bool winner = false;

	if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == board[0][2] && board[0][0] == player || //Rows
		board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == board[1][1] && board[1][0] == player ||
		board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == board[2][2] && board[2][0] == player ||
		board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[1][0] == board[2][0] && board[0][0] == player || //Columns
		board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[1][1] == board[2][1] && board[0][1] == player ||
		board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[1][2] == board[2][2] && board[0][2] == player ||
		board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == board[2][2] && board[0][0] == player || //Diagonal
		board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] == board[0][2] && board[2][0] == player)
	{
		cout << endl;
		printBoard(board);
		cout << " ================================" << endl;
		cout << " ||                            ||" << endl;
		cout << " || PLAYER " << player << " HAS WON THE GAME! ||" << endl;
		cout << " ||                            ||" << endl;
		cout << " ================================" << endl << endl;
		winner = true;
	}
	else if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' &&
		board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' &&
		board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ')
	{
		cout << endl;
		printBoard(board);
		cout << " ================================" << endl;
		cout << " ||                            ||" << endl;
		cout << " ||         IT'S A DRAW!       ||" << endl;
		cout << " ||                            ||" << endl;
		cout << " ================================" << endl << endl;
		winner = true;
	}
	return winner;
}

bool checkPlayAgain()
{
	string exit = "temp";
	bool again = true;

	while (true) {
		cout << "      Play again? (y/n): ";

		//While true, ask if players want to play again
		exit = _getch();
		cout << exit << endl;
		if (exit == "y" || exit == "Y")
		{
			//If user inputs y or Y, return true(play again)
			cout << endl << endl;
			return true;
		}
		else if (exit == "n" || exit == "N")
		{
			//If user inputs n or N, return false (stop playing)
			cout << endl << endl;
			return false;
		}
		else if (exit.length() != 1)
		{
			//If user input is multi-charactered then ask for user input again
		}
	}
}