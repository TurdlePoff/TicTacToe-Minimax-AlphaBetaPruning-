//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 20 Media Design School
//
// File Name	: "CTicTacToe.h"
// Description	: Implementation file for CTicTacToe
// Author		: Vivian Ngo
// Mail			: vivian.ngo7572@mediadesign.school.nz
//

#include "TicTacToe.h"
#include <iostream>
#include <conio.h>

using namespace std;

CTicTacToe::CTicTacToe()
{
	p1Piece = 'x';
	p2Piece = 'o';
	endGame = false;
}

CTicTacToe::~CTicTacToe()
{

}

/*
*
* Function that prints the title of the game (while clearing the screen before hand)
*
* @return void
*
*/
void CTicTacToe::Title()
{
	ctrl.ClearScreen(0, 0);
	ctrl.SetColour(7);
	ctrl.GotoXY(0, 1);
	ctrl.Spc(' ', 15); cout << "_____ ___  ___ _____ ___   ___ _____  ___  ____ " << endl;
	ctrl.Spc(' ', 15); cout << "  |    |  |      |  |___| |      |   |   | [__ " << endl;
	ctrl.Spc(' ', 15); cout << "  |   _|_ |___   |  |   | |___   |   |___| [___ " << endl;
}

/***********************
* StartUp: Starts up the game by introducing the player to a main menu screen
* This main menu screen will allow the player to choose to either
*	- Play a one player game against a computer AI
*		- This has an easy and hard setting
*	- Play a two player game against another human next to them
*	- Customize their board pieces
************************/
void CTicTacToe::StartUp()
{
	while (!GetHasGameEnded())
	{
		//Print player start up screen
		Title();
		/*ctrl.GotoXY(10, 6); cout << "P1 piece: " << p1Piece;
		ctrl.GotoXY(45, 6); cout << "P2 piece: " << p2Piece;*/

		ctrl.GotoXY(0, 3);

		cout << endl << endl;
		//ctrl.Spc(' ', 23); cout << " ===============================" << endl;
		//ctrl.Spc(' ', 23); cout << " ||         Tic Tac Toe       ||" << endl;
		//ctrl.Spc(' ', 23); cout << " ===============================" << endl << endl;
		ctrl.GotoXY(3, 6); cout << "P1 piece: " << p1Piece;
		ctrl.GotoXY(65, 6); cout << "P2 piece: " << p2Piece << endl;

		ctrl.Spc(' ', 23); cout << "    1) Player vs Computer" << endl;
		ctrl.Spc(' ', 23); cout << "    2) Player vs Player" << endl;
		ctrl.Spc(' ', 23); cout << "    3) Customize" << endl;
		ctrl.Spc(' ', 23); cout << "    4) Exit" << endl << endl; 
		ctrl.Spc(' ', 23); cout << " Please select an option: ";

		
		//Select an option from the title screen
		switch (ChooseOption(" Pick a valid option (1, 2, 3, 4): ", 4)) 
		{
			case '1':
			{
				//Prompt user whether they want to play in Easy or Hard Mode
				//ctrl.ClearScreen(0, 6);
				cout << endl;
				ctrl.Spc(' ', 23); cout << " Player vs Computer Selected." << endl << endl << endl;
				ctrl.Spc(' ', 23); cout << " Would you like to play Easy or Hard Mode? " << endl << endl;
				ctrl.Spc(' ', 23); cout << "    1) Easy" << endl;
				ctrl.Spc(' ', 23); cout << "    2) Hard" << endl << endl;
				ctrl.Spc(' ', 23); cout << " Please select an option: ";

				char easyOrHard = ChooseOption(" Pick a valid option (1, 2): ", 2);
				//ctrl.ClearScreen(0, 18);

				//Prompt user whether they would like to be player 1 or player 2
				ctrl.Spc(' ', 23); cout << " Would you like to be player 1 or player 2?: ";
				char p1Or2 = ChooseOption(" Pick a valid option (1, 2): ", 2);

				if (easyOrHard == '1')
				{
					PvCEasy(p1Or2);	//If player picks option one, start easy mode
				}
				else
				{
					PvCHard(p1Or2); //If player picks option two, start hard mode
				}
				break;
			}
			case '2':
			{
				PlayerVsPlayer();	//Call 2 Player game
				break;
			}
			case '3':
			{
				Customize();		//Customize player pieces
				break;
			}
			case '4':
			{
				SetGameEnd();		//Set the endGame value to true
			}
		}
		if (GetHasGameEnded())		//If game has ended, break while loop and close application
		{
			break;
		}
	}
}

void CTicTacToe::PvCEasy(char p1Or2)
{
}

void CTicTacToe::PvCHard(char p1Or2)
{
}

/***********************
* PlayerVsPlayer: Function allowing 2 human players to play against each other
************************/
void CTicTacToe::PlayerVsPlayer()
{
}

/***********************
* Customize: Allows player to customize the TicTacTie game pieces
* Player can change either Player1's piece, Player2's piece or swap them with each other
************************/
void CTicTacToe::Customize()
{
	bool custExit = false;
	while (true)
	{
		cout << endl;
		ctrl.ClearScreen(0, 6);
		ctrl.Spc(' ', 23); cout << " ===============================" << endl;
		ctrl.Spc(' ', 23); cout << " ||        CUSTOMIZATION      ||" << endl;
		ctrl.Spc(' ', 23); cout << " ===============================" << endl;
		ctrl.Spc(' ', 23); cout << " || Current player pieces:    ||" << endl;
		ctrl.Spc(' ', 23); cout << " ||      Player 1 piece: " << p1Piece << "    ||" << endl;
		ctrl.Spc(' ', 23); cout << " ||      Player 2 piece: " << p2Piece << "    ||" << endl;
		ctrl.Spc(' ', 23); cout << " ===============================" << endl << endl;
		ctrl.Spc(' ', 23); cout << " Customization options:" << endl;
		ctrl.Spc(' ', 23); cout << "    1) Change Player 1 piece" << endl;
		ctrl.Spc(' ', 23); cout << "    2) Change Player 2 piece" << endl;
		ctrl.Spc(' ', 23); cout << "    3) Switch pieces" << endl;
		ctrl.Spc(' ', 23); cout << "    4) Return to main menu" << endl << endl;
		ctrl.Spc(' ', 23); cout << " Please select an option: ";

		switch (ChooseOption(" Pick a valid option (1, 2, 3, 4): ", 4))
		{
		case '1': //Allow player to change p1 piece
		{
			ctrl.Spc(' ', 23); cout << " Choose a Player 1 piece: ";
			char p1PieceNew = 'n';
			while (true)
			{
				p1PieceNew = _getch();
				cout << p1PieceNew << endl;

				if (p1PieceNew != p2Piece && p1PieceNew != ' ')
				{
					break;
				}
				else
				{
					ctrl.Spc(' ', 23); cout << " Please choose a different piece:";
				}
			}
			p1Piece = p1PieceNew;
			break;
		}
		case '2': //Allow player to change p2 piece
		{
			ctrl.Spc(' ', 23); cout << " New Player 2 piece: ";
			char p2PieceNew = 'n';
			while (true)
			{
				p2PieceNew = _getch();
				cout << p2PieceNew << endl;
				if (p2PieceNew != p1Piece && p2PieceNew != ' ')
				{
					break;
				}
				else
				{
					ctrl.Spc(' ', 23); cout << " Please choose a different piece: ";
				}
			}
			p2Piece = p2PieceNew;
			break;
		}
		case '3': //Allow player to swap p1 and p2 pieces
		{
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
		if (custExit)
		{
			break;
		}
	}
}

/***********************
* ChooseOption: Allows player to choose an option and prompts a question if a wrong input is entered
* @parameter: question - string containing the question to ask player if a wrong input is entered
* @parameter: numOptions - the number of options to select from
************************/
char CTicTacToe::ChooseOption(std::string question, int numOptions)
{
	char option = _getch();
	while (option < 49 || option >(49 + numOptions - 1))
	{
		cout << endl;
		ctrl.Spc(' ', 23); cout << question;
		option = _getch();
	}
	cout << option << endl << endl;
	return option;
}


/***********************
* PrintBoard: Prints the CTicTacToe board
* @parameter: board[3][3] - the tic tac toe board and it's current values
************************/
void CTicTacToe::PrintBoard(char board[3][3])
{
	cout << endl << endl;
	ctrl.Spc(' ', 23); cout << "                 COLUMN" << endl;
	ctrl.Spc(' ', 23); cout << "       " << endl;
	ctrl.Spc(' ', 23); cout << "            1       2       3" << endl;
	ctrl.Spc(' ', 23); cout << "        ________________________" << endl;
	ctrl.Spc(' ', 23); cout << "       |        |       |       |" << endl;
	ctrl.Spc(' ', 23); cout << "    1  |    " << board[0][0] << "   |   " << board[0][1] << "   |   " << board[0][2] << "   |" << endl;
	ctrl.Spc(' ', 23); cout << "       |        |       |       |" << endl;
	ctrl.Spc(' ', 23); cout << "       |------------------------|" << endl;
	ctrl.Spc(' ', 23); cout << " R     |        |       |       |" << endl;
	ctrl.Spc(' ', 23); cout << " O  2  |    " << board[1][0] << "   |   " << board[1][1] << "   |   " << board[1][2] << "   |" << endl;
	ctrl.Spc(' ', 23); cout << " W     |        |       |       |" << endl;
	ctrl.Spc(' ', 23); cout << "       |------------------------|" << endl;
	ctrl.Spc(' ', 23); cout << "       |        |       |       |" << endl;
	ctrl.Spc(' ', 23); cout << "    3  |    " << board[2][0] << "   |   " << board[2][1] << "   |   " << board[2][2] << "   |" << endl;
	ctrl.Spc(' ', 23); cout << "       |________|_______|_______|" << endl << endl;
}


//Getters and Setters

/***********************
* SetP1Piece: Set the char of p1's piece
* @parameter: p1 - char value that the player wants to change to
************************/
void CTicTacToe::SetP1Piece(char p1)
{
	p1Piece = p1;
}

/***********************
* SetP2Piece: Set the char of p2's piece
* @parameter: p1 - char value that the player wants to change to
************************/
void CTicTacToe::SetP2Piece(char p2)
{
	p2Piece = p2;
}

/***********************
* GetP1Piece: Get the char of p1's piece
************************/
char CTicTacToe::GetP1Piece()
{
	return p1Piece;
}

/***********************
* GetP1Piece: Get the char of p2's piece
************************/
char CTicTacToe::GetP2Piece()
{
	return p2Piece;
}

/***********************
* SetGameEnd: Set the endGame value to true
************************/
void CTicTacToe::SetGameEnd()
{
	endGame = true;
}

/***********************
* GetHasGameEnded: return the endGame value
************************/
bool CTicTacToe::GetHasGameEnded()
{
	return endGame;
}

