#include <iostream>
#include <conio.h>
#include <string>
#include <time.h>
#include <windows.h>

using namespace std;

void printBoard(char board[3][3]);
bool checkWinner(char player, char board[3][3]);
bool checkPlayAgain();
void onePlayerGame(char p1Or2);
void twoPlayerGame();
void customizePieces();
int posSelection(char rowOrCol, char input);

char p1Piece;
char p2Piece;


int main()
{
	srand((unsigned)time(NULL));

	p1Piece = 'x';
	p2Piece = 'o';

	while (true)
	{
		cout << " ===============================" << endl;
		cout << " ||           MISERE          ||" << endl;
		cout << " ===============================" << endl << endl;

		cout << "    1) 1 player game" << endl << "    2) 2 Player game" << endl << "    3) Customize" << endl << "    4) Exit" << endl;
		cout << endl << " Please select an option: ";

		char mainOpt = _getch();
		while (mainOpt < 49 || mainOpt > 52)
		{
			cout << endl << " Pick a valid option (1, 2, 3): ";
			mainOpt = _getch();
		}
		cout << mainOpt << endl;

		switch (mainOpt)
		{
		case '1':
		{
			//Call 1p game
			cout << endl << " Would you like to be player 1 or player 2?: ";
			char p1Or2 = _getch();
			while (p1Or2 < 49 || p1Or2 > 50)
			{
				cout << endl << " Pick a valid option (1, 2, 3): ";
				p1Or2 = _getch();
			}
			cout << p1Or2 << endl << endl;
			onePlayerGame(p1Or2);
			break;
		}
		case '2':
		{
			//Call 2p game
			twoPlayerGame();
			break;
		}
		case '3':
		{
			//Customize player pieces
			customizePieces();
			break;
		}
		case '4':
		{
			return(0);
		}
		}
	}
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
			//If user input is multicharacted then ask for user input again
		}
	}
}

void onePlayerGame(char player)
{
	//While loop used to reset values if players want to play again
	while (true)
	{
		char currentPlayer = p1Piece;

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

			char row, col;

			if (player == '1' && currentPlayer == p1Piece)
			{
				//Prompt user to input position of marker by row and column
				cout << "     Pick a row: ";
				row = posSelection('r', row);

				cout << "     Pick a column: ";
				col = posSelection('c', col);
				cout << endl << " ===============================" << endl << endl;

			}
			else if(player == '2' && currentPlayer == p2Piece)
			{
				//Prompt user to input position of marker by row and column
				cout << "     Pick a row: ";
				row = posSelection('r', row);

				cout << "     Pick a column: ";
				col = posSelection('c', col);
				cout << endl << " ===============================" << endl << endl;
			}
			else
			{
				cout << "   Player " << currentPlayer << " is making their move: ";
				int compRow = (rand() % 3 + 1);
				row = '0' + compRow;

				int compCol = (rand() % 3 + 1);
				col = '0' + compCol;
			}


			//Check if board space is empty
			if (board[row - 49][col - 49] == ' ')
			{
				if (player == '1' && currentPlayer != p1Piece || player == '2' && currentPlayer != p2Piece)
				{
					Sleep(500);
					cout << ". ";
					Sleep(500);
					cout << ". ";
					Sleep(500);
					cout << ". ";
					Sleep(500);
					cout << endl << endl;
				}

				//Set player marker in the position the player selected
				board[row - 49][col - 49] = currentPlayer;
				turnEnd = true;

				//Call checkWinner bool function to check if there is a winner
				//Break while loop and end round
				if (checkWinner(currentPlayer, board) == true)
					break;

				//Switch players after a turn is up
				if (currentPlayer == p1Piece)
				{
					currentPlayer = p2Piece;
				}
				else
				{
					currentPlayer = p1Piece;
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
			break;
		}
	}
}

void twoPlayerGame()
{
	//While loop used to reset values if players want to play again
	while (true)
	{
		char currentPlayer = p1Piece;
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
			char row = 0;
			char col = 0;
			cout << "     Pick a row: ";
			row = posSelection('r', row);

			cout << "     Pick a column: ";
			col = posSelection('c', col);
			cout << endl << " ===============================" << endl << endl;

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
				if (currentPlayer == p1Piece)
				{
					currentPlayer = p2Piece;
				}
				else
				{
					currentPlayer = p1Piece;
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
			break;
		}
	}
}

int posSelection(char rowCol, char input)
{
	input = _getch();
	while (input < 49 || input > 51)
	{
		if (rowCol == 'r')
		{
			cout << endl << "     Pick a valid row (1, 2, 3): ";
		}
		else if((rowCol == 'c'))
		{
			cout << endl << "     Pick a valid column (1, 2, 3): ";
		}
		input = _getch();
	}
	cout << input << endl;
	return input;
}

void customizePieces()
{
	bool custExit = false;
	while (true)
	{
		cout << endl << " ===============================" << endl;
		cout << " ||        CUSTOMIZATION      ||" << endl;
		cout << " ===============================" << endl;
		cout << " || Current player pieces:    ||" << endl;
		cout << " || Player 1 piece: " << p1Piece << "         ||" << endl;
		cout << " || Player 2 piece: " << p2Piece << "         ||" << endl;
		cout << " ===============================" << endl << endl;
		cout << "    Customization options:" << endl << "    1) Player 1" << endl << "    2) Player 2" << endl << "    3) Return to main menu" << endl;
		cout << endl << " Select an player piece to change: ";

		char mainOpt = _getch();
		while (mainOpt < 49 || mainOpt > 51)
		{
			cout << endl << "     Pick a valid option (1, 2, 3): ";
			mainOpt = _getch();
		}
		cout << mainOpt << endl;
		switch (mainOpt)
		{
		case '1':
		{
			cout << "New Player 1 piece: ";
			char p1PieceNew = _getch();
			cout << p1PieceNew << endl;
			p1Piece = p1PieceNew;
			break;
		}
		case '2':
		{
			//Call 2p game
			cout << "New Player 2 piece: ";
			char p2PieceNew = _getch();
			cout << p2PieceNew << endl;
			p2Piece = p2PieceNew;
			break;
		}
		case '3':
		{
			//Return to main menu
			custExit = true;
			break;
		}
		}
		if (custExit)
		{
			break;
		}
	}
}