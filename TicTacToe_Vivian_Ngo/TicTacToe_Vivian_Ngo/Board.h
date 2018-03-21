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
	void PrintBoard();
	void PrintWinningPiece(int x, int y);
	void Insert(char player, int xPos, int yPos);
	void Remove(int xPos, int yPos);
	void ResetBoard();
	void ResetWinBoard();

private:
	char board[3][3];
	bool winnerBoard[3][3];
	CControl* ctrl;
};

#endif // __BOARD_H__