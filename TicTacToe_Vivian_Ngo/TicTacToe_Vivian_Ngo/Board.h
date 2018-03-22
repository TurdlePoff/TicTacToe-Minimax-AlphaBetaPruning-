#pragma once
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	: "Board.h"
// Description	: Implementation file for MiniMax
//
// Author		: Vivian Ngo
// Mail			: vivian.ngo7572@mediadesign.school.nz
//

#ifndef __BOARD_H__
#define __BOARD_H__
#include "Control.h"


class CBoard
{
public:
	CBoard();
	~CBoard();

	void PrintBoard();								//Prints the game board
	void PrintWinningPiece(int x, int y);			//Checks whether to print a board piece in colour (a winner) or not
	
	void Insert(char player, int xPos, int yPos);	//Insert a piece into the board
	void Remove(int xPos, int yPos);				//Remove a piece from the board
	
	void ResetBoard();								//Reset the game board
	void ResetWinBoard();							//Reset the winner board

	char CheckPiece(int xPos, int yPos);			//Return a piece from a position on the board
	bool CheckForDraw();							//Check if there is a draw
	bool CheckForWinner(char player);				//Check if there is a winner

private:
	char board[3][3];								//The TicTacToe game board
	bool winnerBoard[3][3];							//The winner board used to check if there is a 3 in a row
	CControl* ctrl;									//Control class with functions to support the aethetics of the game
};

#endif // __BOARD_H__