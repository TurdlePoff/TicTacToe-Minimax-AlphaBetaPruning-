#pragma once

// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	: "Board.cpp"
// Description	: Implementation file for MiniMax
//
// Author		: Vivian Ngo
// Mail			: vivian.ngo7572@mediadesign.school.nz
//

#include "Board.h"
#include <iostream>

CBoard::CBoard()
{
	//Initialise new tictactoe board
	ResetBoard();
	ResetWinBoard();
	ctrl = new CControl();
}

CBoard::~CBoard()
{
	delete ctrl;
	ctrl = 0;
}

/***********************
* PrintBoard: Print the tictactoe board
* @author: Vivian Ngo
* @date: 14/03/18
************************/
void CBoard::PrintBoard()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			board[i][j] = ' ';
		}
	}
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
		ctrl->PrintCharInColour(board[x][y], 14); //Print character piece in colour
	}
	else
	{
		std::cout << board[x][y];			 //Print character piece without colouring
	}
}

void CBoard::Insert(char player, int xPos, int yPos)
{
	board[xPos][yPos] = player;
}

void CBoard::Remove(int xPos, int yPos)
{
	board[xPos][yPos] = ' ';
}

void CBoard::ResetBoard()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			board[i][j] = ' ';
		}
	}
}

void CBoard::ResetWinBoard()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			winnerBoard[i][j] = false;
		}
	}
}
