#pragma once

// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	: "Board.cpp"
// Description	: Implementation file for Board class that 
//				  provides the game board for TicTacToe
//
// Author		: Vivian Ngo
// Mail			: vivian.ngo7572@mediadesign.school.nz
//

#include "Board.h"
#include <iostream>

using namespace std;

/***********************
* CBoard Constructor
* @author: Vivian Ngo
* @date: 14/03/18
************************/
CBoard::CBoard()
{
	//Initialise new tictactoe board
	ResetBoard();
	ResetWinBoard();
}

/***********************
* CBoard Destructor
* @author: Vivian Ngo
* @date: 14/03/18
************************/
CBoard::~CBoard()
{
	/*delete ctrl;
	ctrl = 0;*/
}

/***********************
* PrintBoard: Prints the TicTacToe board
*			  PrintWinningPiece() function is used to check if the piece
*								  is a winning piece and if so, print in colour
* @author: Vivian Ngo
* @date: 14/03/18
************************/
void CBoard::PrintBoard()
{
	cout << endl;
	CControl::Spc(' ', 5); cout << "                 COLUMN" << endl;
	CControl::Spc(' ', 5); cout << "       " << endl;
	CControl::Spc(' ', 5); cout << "            1       2       3" << endl;
	CControl::Spc(' ', 5); cout << "        ________________________" << endl;
	CControl::Spc(' ', 5); cout << "       |        |       |       |" << endl;
	CControl::Spc(' ', 5); cout << "    1  |    "; PrintWinningPiece(0, 0);
					   cout << "   |   "; PrintWinningPiece(0, 1);
					   cout << "   |   "; PrintWinningPiece(0, 2); cout << "   |" << endl;
	CControl::Spc(' ', 5); cout << "       |        |       |       |" << endl;
	CControl::Spc(' ', 5); cout << "       |--------+-------+-------|" << endl;
	CControl::Spc(' ', 5); cout << " R     |        |       |       |" << endl;
	CControl::Spc(' ', 5); cout << " O  2  |    "; 
	PrintWinningPiece(1, 0);
					   cout << "   |   "; PrintWinningPiece(1, 1);
					   cout << "   |   "; PrintWinningPiece(1, 2); cout << "   |" << endl;
	CControl::Spc(' ', 5); cout << " W     |        |       |       |" << endl;
	CControl::Spc(' ', 5); cout << "       |--------+-------+-------|" << endl;
	CControl::Spc(' ', 5); cout << "       |        |       |       |" << endl;
	CControl::Spc(' ', 5); cout << "    3  |    "; PrintWinningPiece(2, 0);
					   cout << "   |   "; PrintWinningPiece(2, 1);
					   cout << "   |   "; PrintWinningPiece(2, 2); cout << "   |" << endl;
	CControl::Spc(' ', 5); cout << "       |________|_______|_______|" << endl << endl;
}

/***********************
* PrintWinningPiece: Used to check if the piece is a winning piece and if so, print in colour
* @author: Vivian Ngo
* @date: 14/03/18
* @parameter: x - the x position of the board to be checked
* @parameter: y - the y position of the board to be checked
************************/
void CBoard::PrintWinningPiece(int x, int y)
{
	if (winnerBoard[x][y])
	{
		CControl::PrintCharInColour(board[x][y], 14); //Print character piece in a light yellow colour
	}
	else
	{
		std::cout << board[x][y]; //Print character piece without colouring
	}
}

/***********************
* Insert: Insert an inputted piece into the game board
* @author: Vivian Ngo
* @date: 14/03/18
* @parameter: player - the player piece to be inserted onto the board
* @parameter: xPos - the x position of the board the player piece will be inserted
* @parameter: yPos - the y position of the board the player piece will be inserted
************************/
void CBoard::Insert(char player, int xPos, int yPos)
{
	board[xPos][yPos] = player;
}

/***********************
* Remove: Remove a piece from the game board
* @author: Vivian Ngo
* @date: 14/03/18
* @parameter: player - the player piece to be inserted onto the board
* @parameter: xPos - the x position of the board the player piece will be inserted
* @parameter: yPos - the y position of the board the player piece will be inserted
************************/
void CBoard::Remove(int xPos, int yPos)
{
	board[xPos][yPos] = ' ';
}

/***********************
* ResetBoard: Reset the game board
* @author: Vivian Ngo
* @date: 14/03/18
************************/
void CBoard::ResetBoard()
{
	for (unsigned int i = 0; i < 3; ++i)
	{
		for (unsigned int j = 0; j < 3; ++j)
		{
			board[i][j] = ' '; //Change every piece to a blank piece
		}
	}
}

/***********************
* ResetWinBoard: Reset the boolean winner board
* @author: Vivian Ngo
* @date: 14/03/18
************************/
void CBoard::ResetWinBoard()
{
	for (unsigned int i = 0; i < 3; ++i)
	{
		for (unsigned int j = 0; j < 3; ++j)
		{
			winnerBoard[i][j] = false; //Change every value to false
		}
	}
}

/***********************
* CheckPiece: Checks a piece with the position specified on the board
* @author: Vivian Ngo
* @date: 14/03/18
* @parameter: xPos - the x position of the board to check
* @parameter: yPos - the y position of the board to check
* @parameter: piece - the piece to check the board position with
* @return: true if piece is equal to piece on board else false.
************************/
bool CBoard::CheckPiece(int xPos, int yPos, char piece)
{
	return (board[xPos][yPos] == piece ? true : false);
}

/***********************
* CheckForDraw: Check if the board is completely filled. If true, the game is a draw
* @author: Vivian Ngo
* @date: 14/03/18
* @return: boardIsFull - return true if board is full else return false
************************/
bool CBoard::CheckForDraw()
{
	bool boardIsFull = true;
	for (unsigned int i = 0; i < 3; ++i)
	{
		for (unsigned int j = 0; j < 3; ++j)
		{
			if(board[i][j] == ' ')
				boardIsFull = false; //If there is an empty space the board is not full
		}
	}
	return boardIsFull;
}

/***********************
* CheckForWinner: Check if there is a winner in the tictactoe board and if so, 
*				  set the 3 in a row in colour
* @author: Vivian Ngo
* @date: 14/03/18
* @return: winner - return true if the board has a winner
************************/
bool CBoard::CheckForWinner(char player)
{
	bool winner = false;
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == board[0][2] && board[0][0] == player)
	{
		winnerBoard[0][0] = winnerBoard[0][1] = winnerBoard[0][2] = winner = true;
	}
	else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == board[1][1] && board[1][0] == player)
	{
		winnerBoard[1][0] = winnerBoard[1][1] = winnerBoard[1][2] = winner = true;
	}
	else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == board[2][2] && board[2][0] == player)
	{
		winnerBoard[2][0] = winnerBoard[2][1] = winnerBoard[2][2] = winner = true;
	}
	else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[1][0] == board[2][0] && board[0][0] == player)
	{
		winnerBoard[0][0] = winnerBoard[1][0] = winnerBoard[2][0] = winner = true;
	}
	else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[1][1] == board[2][1] && board[0][1] == player)
	{
		winnerBoard[0][1] = winnerBoard[1][1] = winnerBoard[2][1] = winner = true;
	}
	else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[1][2] == board[2][2] && board[0][2] == player)
	{
		winnerBoard[0][2] = winnerBoard[1][2] = winnerBoard[2][2] = winner = true;
	}
	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == board[2][2] && board[0][0] == player)
	{
		winnerBoard[0][0] = winnerBoard[1][1] = winnerBoard[2][2] = winner = true;
	}
	else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] == board[0][2] && board[2][0] == player)
	{
		winnerBoard[2][0] = winnerBoard[1][1] = winnerBoard[0][2] = winner = true;
	}
	return winner;
}

//void CBoard::ConvertRowCol(int& xPos, int& yPos, int val)
//{
//	switch (val)
//	{
//		case 0;
//	}
//}
//
