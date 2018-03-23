//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: "CTicTacToe.h"
// Description	: Implementation file for CTicTacToe
// Author		: Vivian Ngo
// Mail			: vivian.ngo7572@mediadesign.school.nz
//

#include "TicTacToe.h"
#include <conio.h>
#include <iostream>

using namespace std;

/***********************
* TicTacToe Destructor
* @author: Vivian Ngo
* @date: 14/03/18
************************/
CTicTacToe::CTicTacToe()
{
	//Initialize global variables
	board = new CBoard();

	p1Piece = 'X';
	p2Piece = 'O';
	p1Points = 0;
	p2Points = 0;
	gameEnded = false;
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL)
	{				 //  position	 size
		MoveWindow(hwnd, 342, 50, 700, 525, TRUE);  //Set console position to center
	}
}

/***********************
* TicTacToe Destructor
* @author: Vivian Ngo
* @date: 07/03/18
************************/
CTicTacToe::~CTicTacToe()
{
	delete board;
	board = 0;
}

/***********************
* Title: Prints the Tic Tac Toe title text
* @author: Vivian Ngo
* @date: 14/03/18
************************/
void CTicTacToe::Title()
{
	cout << "  _____ ___  ___ _____ ___   ___ _____  ___  ____ " << endl;
	cout << "    |    |  |      |  |___| |      |   |   | [__ " << endl;
	cout << "    |   _|_ |___   |  |   | |___   |   |___| [___ " << endl;
}

/***********************
* StartUp: Starts up the game by introducing the player to a main menu screen
* This main menu screen will allow the player to choose to either:
*	- Play a one player game against a computer AI
*		- This has an easy and hard setting
*	- Play a two player game against another human next to them
*	- Customize their board pieces
*	- Exit the game
* @author: Vivian Ngo
* @date: 07/03/18
************************/
void CTicTacToe::StartUp()
{
	Title(); //Print title that will last for the entire duration of the game until exited
	while (!gameEnded)
	{
		CControl::ClearScreen(0, 4);
		cout << " =================================================" << endl;
		cout << " ||                  Tic Tac Toe                ||" << endl;
		cout << " =================================================" << endl;
		cout << " ||              Player 1 piece: " << p1Piece << "              ||" << endl;
		cout << " ||              Player 2 piece: " << p2Piece << "              ||" << endl;
		cout << " =================================================" << endl << endl;		
		cout << "     Main menu options: " << endl << endl;
		cout << "         1) Player vs Computer" << endl;
		cout << "         2) Player vs Player" << endl;
		cout << "         3) Customize" << endl;
		cout << "         4) Exit" << endl << endl; 
		cout << "     Please select an option: ";
		
		//Select an option from the title screen
		switch (ChooseOption("     Pick a valid option (1, 2, 3, 4): ", 4)) 
		{
			case '1':	//Player vs Computer
			{
				CControl::ClearScreen(0, 4);
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "             Player vs Computer Selected." << endl;
				cout << " =================================================" << endl << endl;
				CControl::SetColour(7);

				// Prompt player if they would like to play easy or hard mode
				cout << "     Would you like to play Easy or Hard Mode? " << endl << endl;
				cout << "         1) Easy" << endl;
				cout << "         2) Hard" << endl << endl;
				cout << "     Select an option: ";

				char easyOrHard = ChooseOption("     Pick a valid option (1, 2): ", 2);
				
				// Inform player of their difficulty choice
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "               " << ((easyOrHard == '1') ? "Easy mode" : "Hard mode") << " selected." << endl;
				cout << " =================================================" << endl << endl;
				CControl::SetColour(7);

				//Prompt user whether they would like to be player 1 or player 2
				cout << " Would you like to be player 1 (" << p1Piece 
									  << ") or player 2 (" << p2Piece << ")?: ";
				char p1Or2 = ChooseOption("     Pick a valid option (1, 2): ", 2);
				
				// Inform player of their turn choice
				CControl::SetColour(6);

				CControl::ClearScreen(0, 4);
				cout << " =================================================" << endl;
				cout << "    " << ((easyOrHard == '1') ? "[Easy]" : "[Hard]") << " You are player " << ((p1Or2 == '1') ? '1' : '2') << " with the '" << p1Piece << "' piece." << endl;
				cout << " =================================================" << endl << endl;

				CControl::SetColour(7);

				// Countdown sequence so player can see the options they selected for the match
				cout << "     Starting game in: ";
				Sleep(350); cout << "3"; Sleep(350); cout << "."; Sleep(350); cout << "."; Sleep(350); cout << "."; Sleep(350);
				cout << "2"; Sleep(350); cout << "."; Sleep(350); cout << "."; Sleep(350); cout << "."; Sleep(350);
				cout << "1"; Sleep(350); cout << "."; Sleep(350); cout << "."; Sleep(350); cout << ".";

				while (_kbhit()) //Prevents user input while program is sleeping
					_getch();

				if (easyOrHard == '1')
				{
					//Starts up a new game match in easy mode
					PlayGame(p1Or2, true, false);
				}
				else
				{
					//Starts up a new game match in hard mode
					PlayGame(p1Or2, false, false);
				}
				break;
			}
			case '2':				//Player vs Player
			{
				CControl::ClearScreen(0, 4);
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "           Player vs Player Selected." << endl;
				cout << " =================================================" << endl << endl;
				CControl::SetColour(7);

				PlayGame('1', false, true);	//Start up Player vs Player game
				break;
			}
			case '3':
			{
				CControl::ClearScreen(0, 4);
				Customize();		//Customize player pieces
				break;
			}
			case '4':
			{
				gameEnded = true;		//Set the endGame value to true
			}
		}
		if (gameEnded)		//If game has ended, break while loop and close application
		{
			break;
		}
	}
}

/***********************
* ChooseOption: Allows player to choose an option and prompts a question if a wrong input is entered
* @author: Vivian Ngo
* @date: 14/03/18
* @parameter: question - string containing the question to ask player if a wrong input is entered
* @parameter: numOptions - the number of options to select from
* @return: valid option inputted by player
************************/
char CTicTacToe::ChooseOption(std::string question, int numOptions)
{
	//Receive player input
	char option = _getch();
	//Recieve numbers depending on how many options are given
	while (option < 49 || option >(49 + numOptions - 1))
	{
		cout << endl;
		cout << question;
		option = _getch();
	}
	cout << option << endl << endl;
	return option;
}

/***********************
* CheckGameOver: Check if game is over and print scores if so
* @author: Vivian Ngo
* @date: 14/03/18
* @parameter: player - The character of the current player's piece
* @parameter: isPlayerTurn - Checks if it is player 1's turn
* @parameter: isPvP - Checks if the game match is PvP or PvC
* @parameter: p1Or2 - Checks if the current player is player 1 or player 2
* @return: gameOver - If true, the game is over. Else, the game continues.
************************/
bool CTicTacToe::CheckGameOver(char player, bool isPlayerTurn, bool isPvP, char p1Or2)
{
	bool gameOver = false;

	if (board->CheckForDraw()) // If there is a draw, print scores
	{
		cout << endl;
		CControl::ClearScreen(0, 4);

		board->PrintBoard();
		CControl::SetColour(6);
		PrintScores(true, isPvP, isPlayerTurn, p1Or2);
		CControl::SetColour(7);

		gameOver = true;
	}
	else if (board->CheckForWinner(player)) // If there is a winner, print scores
	{
		cout << endl;
		CControl::ClearScreen(0, 4);

		board->PrintBoard();
		CControl::SetColour(6);
		PrintScores(false, isPvP, isPlayerTurn, p1Or2);
		CControl::SetColour(7);

		gameOver = true;
	}

	return gameOver;
}

/***********************
* PrintScores: Prints the scores of the current game session
* @author: Vivian Ngo
* @date: 14/03/18
* @parameter: isDraw - Checks if game is a draw
* @parameter: isPvP - Checks if the game is a PvP (Player vs Player) or PvC (Player vs Computer) game
* @parameter: isPlayerTurn - Checks if the current player is player 1
* @parameter: p1Or2 - Checks if the player is player 1 or player 2 (PvC scores)
************************/
void CTicTacToe::PrintScores(bool isDraw, bool isPvP, bool isPlayerTurn, char p1Or2)
{
	if (isPvP) //Player vs Player game
	{
		if (isDraw) //If the game is a draw, print the current score
		{
			cout << " =================================================" << endl;
			cout << "                      DRAW!!" << endl;
			cout << endl << "     Player 1 Points: " << p1Points
				<< "      Player 2 Points: " << p2Points << endl;
			cout << " =================================================" << endl << endl;
		}
		else        //If the game is won, add points to the person who one and print the score
		{
			if (isPlayerTurn)
				++p1Points;
			else
				++p2Points;

			cout << " =================================================" << endl;
			cout << "          PLAYER " << ((isPlayerTurn) ? '1' : '2') << ": " << ((isPlayerTurn) ? p1Piece : p2Piece)
				<< " HAS WON THE GAME!   " << endl << endl;
			cout << "     Player 1 Points: " << p1Points
				<< "      Player 2 Points: " << p2Points << endl;
			cout << " =================================================" << endl << endl;
		}
	}
	else //Player vs Computer game
	{
		if (isDraw)  //If the game is a draw, print the current score
		{
			cout << " =================================================" << endl;
			cout << "                      DRAW!!" << endl;
			cout << endl << "     Player Points: " << ((p1Or2 == '1') ? p1Points : p2Points)
				<< "      Computer Points: " << ((p1Or2 == '1') ? p2Points : p1Points) << endl;
			cout << " =================================================" << endl << endl;
		}
		else         //If the game is won, add points to the person who one and print the score
		{
			if (isPlayerTurn) //Add to player points then print score
			{
				if (p1Or2 == '1')
					++p1Points;
				else
					++p2Points;

				cout << " =================================================" << endl;
				cout << "          PLAYER: " << ((p1Or2 == '1') ? p1Piece : p2Piece)
					<< " HAS WON THE GAME!   " << endl << endl;
				cout << "     Player Points: " << ((p1Or2 == '1') ? p1Points : p2Points)
					<< "      Computer Points: " << ((p1Or2 == '1') ? p2Points : p1Points) << endl;
				cout << " =================================================" << endl << endl;
			}
			else              //Add to computer points then print score
			{
				if (p1Or2 != '1')
					++p1Points;
				else
					++p2Points;

				cout << " =================================================" << endl;
				cout << "          COMPUTER: " << ((p1Or2 != '1') ? p1Piece : p2Piece)
					<< " HAS WON THE GAME!   " << endl << endl;
				cout << "     Player Points: " << ((p1Or2 == '1') ? p1Points : p2Points)
					<< "      Computer Points: " << ((p1Or2 == '1') ? p2Points : p1Points) << endl;
				cout << " =================================================" << endl << endl;
			}
		}
	}
}

/***********************
* PlayGame: Starts up and plays the game depending on the parameters given
*					(p1Or2 and easyMode parameters are used for player vs computer games
*					 these are defaulted to '1' [p1Or2] and true [easyMode] when calling pvp mode)
* @author: Vivian Ngo
* @date: 14/03/18
* @parameter: p1Or2 - (player vs computer) input from player for whether they want to play as player 1 or 2
* @parameter: easyMode - (player vs computer) input from player for whether they want to play easy or hard mode
* @parameter: isPvP - boolean variable that determines if the game is player vs player or player vs computer
************************/
void CTicTacToe::PlayGame(char p1Or2, bool easyMode, bool isPvP)
{
	p1Points = 0;
	p2Points = 0;
	while (true) //While loop used to reset values if players want to play again
	{
		bool isPlayerTurn = ((p1Or2 == '1') ? true : false);	//Set true if player chose to go first
		char currentPlayer = p1Piece;							//Set the current player's piece to p1Piece 

		board->ResetBoard();
		board->ResetWinBoard();

		while (true)			//While loop for a single game session
		{
			CControl::ClearScreen(0, 4);
			board->PrintBoard();		//Print current board status

			row = 0;			//row to be picked
			col = 0;			//column to be picked

			if (isPvP || isPlayerTurn)	//If it is a PvP game OR If it is the players turn, allow player to set their position
			{
				//If it is PvP, print out whether is is player 1 or player 2's turn to play
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "                 Player" << ((isPvP) ? ((isPlayerTurn) ? " 1: " : " 2: ") : ": ") << currentPlayer << "'s turn" << endl;
				cout << " =================================================" << endl << endl;
				CControl::SetColour(7);

				while (true)
				{
					//Allow player to pick a row and column
					cout << endl << "     Pick a row: ";
					row = ChooseOption("     Pick a valid row (1, 2, 3): ", 3);

					cout << "     Pick a column: ";
					col = ChooseOption("     Pick a valid column (1, 2, 3): ", 3);

					//If position is valid, end loop
					if (board->CheckPiece(row - 49, col - 49, ' '))
					{
						row -= 49;
						col -= 49;

						break;
					}
					//Otherwise, repeat while loop
					cout << "     Please pick a valid position: " << endl;
				}
			}	
			else	//If players turn, allow player to set their position
			{
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "                Computer: " << currentPlayer << "'s turn" << endl;
				cout << " =================================================" << endl << endl;
				CControl::SetColour(7);

				//Insert minimax here================================++++++++++++++++++++++++++++++++++++++++++++++++++++++
				if (true)	//easyMode) SET WHEN MINIMAX IMPLEMENTED
				{
					while (true)
					{
						//Easy random computer position generator
						int* depth = 0;
						MiniMax(currentPlayer, *depth);

							row -= 49;
							col -= 49;
						//Easy random computer position generator
						//int compRow = (rand() % 3 + 1);
						//row = '0' + compRow;

						//int compCol = (rand() % 3 + 1);
						//col = '0' + compCol;


						//if (board->CheckPiece(row-49, col-49, ' ')) //If the position is valid, proceed with sleep
						//{
							
						//	cout << "     Computer " << currentPlayer << " is making their move: ";




							/******************* TESTING MINIMAX *************/
							//Sleep(500);
							//cout << ". ";
							//Sleep(500);
							//cout << ". ";
							//Sleep(500);
							//cout << ". ";
							//Sleep(500);

							//while (_kbhit()) //Prevents user input while program is sleeping
							//	_getch();

							



							cout << endl << endl;

							break;
					}
				}
				else
				{
					//Generate better minimaxMinimax
				}
			}
			//Set player piece on board
			board->Insert(currentPlayer, row, col);

			//Check if there is a winner. If there is, break while loop and end round
			if (CheckGameOver(currentPlayer, isPlayerTurn, isPvP, p1Or2))
			{
				break;
			}

			//Switch players after a turn is up
			if (currentPlayer == p1Piece)
			{
				currentPlayer = p2Piece;
			}
			else
			{
				currentPlayer = p1Piece;
			}
			isPlayerTurn = !isPlayerTurn;
		}
		//Ask players if they want to play another round
		cout << "     Play again?" << endl << endl;
		cout << "         1) Yes" << endl;
		cout << "         2) No" << endl << endl;
		cout << "     Please select an option: ";

		//Allows player to choose whether to play again or not
		if (ChooseOption("     Pick a valid option (1, 2): ", 2) == '1')
		{
			CControl::ClearScreen(0, 4);
			CControl::SetColour(6);
			cout << " =================================================" << endl;
			cout << "                 STARTING NEW GAME " << endl;
			cout << " =================================================" << endl << endl;
			CControl::SetColour(7);
		}
		else
		{
			//Return to main menu by breaking the while loop
			break;
		}
	}
}

/***********************
* Customize: Allows player to customize the TicTacTie game pieces
* Player can change either:
*	- Player1's game piece
*	- Player2's game piece 
*	- Swap Player 1 and Player 2's pieces with each other
* @author: Vivian Ngo
* @date: 07/03/18
************************/
void CTicTacToe::Customize()
{
	bool custExit = false;
	while (true)
	{
		//Print customization menu
		cout << " =================================================" << endl;
		cout << " ||                 CUSTOMIZATION               ||" << endl;
		cout << " =================================================" << endl;
		cout << " ||              Player 1 piece: " << p1Piece << "              ||" << endl;
		cout << " ||              Player 2 piece: " << p2Piece << "              ||" << endl;
		cout << " =================================================" << endl << endl;
		cout << "     Customization options:" << endl << endl;
		cout << "         1) Change Player 1 piece" << endl;
		cout << "         2) Change Player 2 piece" << endl;
		cout << "         3) Switch pieces" << endl;
		cout << "         4) Return to main menu" << endl << endl;
		cout << "     Please select an option: ";

		switch (ChooseOption("     Pick a valid option (1, 2, 3, 4): ", 4))
		{
			case '1': //Allow player to change p1 piece
			{
				cout << "     Choose a new Player 1 piece: ";
				p1Piece = ChangePiece(p1Piece);
				CControl::ClearScreen(0, 4);
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "               Player 1 piece changed." << endl;
				cout << " =================================================" << endl;
				CControl::SetColour(7);
				break;
			}
			case '2': //Allow player to change p2 piece
			{
				cout << "     Choose a new Player 2 piece: ";
				p2Piece = ChangePiece(p2Piece);
				CControl::ClearScreen(0, 4);
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "               Player 2 piece changed." << endl;
				cout << " =================================================" << endl;
				CControl::SetColour(7);
				break;
			}
			case '3': //Allow player to swap p1 and p2 pieces
			{
				CControl::ClearScreen(0, 4);
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "               P1 & P2 pieces Switched." << endl;
				cout << " =================================================" << endl;
				CControl::SetColour(7);

				char tempPiece = p1Piece;
				p1Piece = p2Piece;
				p2Piece = tempPiece;

				break;
			}
			case '4':
			{
				//Return to main menu
				custExit = true;
				break;
			}
		}

		if (custExit) //Exit customization menu if custExit is true
		{
			break;
		}
	}
}

/***********************
* ChooseCharacter: Takes the user's input and checks if it is a valid board game piece
* @return: newPiece - The valid new piece the user inputed
* @author: Vivian Ngo
* @date: 14/03/18
************************/
char CTicTacToe::ChangePiece(char checkWithPlayer)
{
	char newPiece = 'n';
	while (true)
	{
		newPiece = _getch();
		cout << newPiece << endl;
		//If the new piece is not equals to player two's piece or a space character, return.
		if (newPiece != checkWithPlayer && newPiece != ' ')
		{
			break;
		}
		//prompt statement if input is invalid
		else
		{
			cout << "     Please choose a different character: ";
		}
	}
	return newPiece;
}

/***********************
* Minimax: Minimax function used to determine the AI for the computer
* @parameter: currentPlayer - The currentplayer
* @author: Vivian Ngo
* @date: 14/03/18
************************/
int CTicTacToe::MiniMax(char currentPlayer, int& depth)
{
	/*if (MiniMaxScore(currentPlayer, depth) == 10 || MiniMaxScore(currentPlayer, depth) == 0)
	{
		return;
	}*/
	/*bool boardAvailability[3][3];

	for (unsigned int i = 0; i < 9; ++i)
	{
		for (unsigned int j = 0; j < 9; ++j)
		{
			boardAvailability[i][j] = (board->CheckPiece(i, j, ' ') ? true : false);
		}
	}*/

	for (unsigned int i = 0; i < 9; ++i)
	{
		for (unsigned int j = 0; j < 9; ++j)
		{
			/*if()
			move.moveArray[moveCounter] = (board->CheckPiece(i, j, ' ') ? true : false);*/
		}
	}


	//Check entire board and number it.

		
}

//int CTicTacToe::MaxSearch(char currentPlayer)
//{
//	if (board->CheckForWinner(currentPlayer)) //not sure yet
//	{
//		//cout << "Returning minimax with depth: " << depth << " with val: " << bestValue << endl;
//		return -10;
//	}
//
//	int maxBest = -1000;
//
//	for (unsigned int i = 0; i < 3; ++i)
//	{
//		for (unsigned int j = 0; j < 3; ++j)
//		{
//			if (board->CheckPiece(i, j, ' ') && maxBest != 10)
//			{
//				board->Insert(currentPlayer, i, j);
//				//If the current player is p1 then switch to player 2 else vice versa
//				int bestMinVal = MiniSearch((currentPlayer == p1Piece) ? p2Piece : p1Piece);
//				if (maxBest <= bestMinVal)
//				{
//					maxBest = bestMinVal;
//					row = '0' + i;
//					col = '0' + j;
//				}
//				board->Remove(i, j);
//			}
//		}
//	}
//	return maxBest;
//}
//
//
//
//int CTicTacToe::MiniSearch(char currentPlayer)
//{
//	if (board->CheckForWinner(currentPlayer)) //not sure yet
//	{
//		//cout << "Returning minimax with depth: " << depth << " with val: " << bestValue << endl;
//		return 10;
//	}
//
//	int minBest = 1000;
//
//	for (unsigned int i = 0; i < 3; ++i)
//	{
//		for (unsigned int j = 0; j < 3; ++j)
//		{
//			if (board->CheckPiece(i, j, ' ') && minBest != -10)
//			{
//				board->Insert(currentPlayer, i, j);
//
//				//If the current player is p1 then switch to player 2 else vice versa
//				int bestMinVal = MaxSearch((currentPlayer == p1Piece) ? p2Piece : p1Piece);
//				if (minBest >= bestMinVal)
//				{
//					minBest = bestMinVal;
//					row = '0' + i;
//					col = '0' + j;
//				}
//				board->Remove(i, j);
//			}
//		}
//	}
//
//	return minBest;
//}

/***********************
* MiniMaxScore: Determines the minimax score for the AI algorithm
* @parameter: currentPlayer - The current player
*https://www.neverstopbuilding.com/blog/2013/12/13/tic-tac-toe-understanding-the-minimax-algorithm13   adskjflkjhfljfhkl
* @author: Vivian Ngo
* @date: 14/03/18
************************/
int CTicTacToe::MiniMaxScore(char currentPlayer, int& depth)
{
	if (board->CheckForWinner(currentPlayer))
	{
		return 10 - depth;
	}
	else if (board->CheckForWinner((currentPlayer == p1Piece) ? p2Piece : p1Piece))
	{
		return depth -10;
	}
	else if (board->CheckForDraw())
	{
		return 0;
	}
	else // more possible moves are valid
	{
		return 1;
	}
}
