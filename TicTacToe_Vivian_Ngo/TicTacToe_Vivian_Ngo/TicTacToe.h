//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	: "TicTacToe.h"
// Description	: Declaration file for TicTacToe
// Author		: Vivian Ngo
// Mail			: vivian.ngo7572@mediadesign.school.nz
//

#pragma once

#ifndef __TICTACTOE_H__
#define __TICTACTOE_H__

#include "Control.h"
#include <string>


class CTicTacToe
{
public:
	CTicTacToe();				//TicTacToe Constructor
	~CTicTacToe();				//TicTacToe Destructor
	
	void Title();				//Prints the Tic Tac Toe title text
	void StartUp();				//StartUp - A main menu screen for the game
	
	void PrintBoard();						//Prints the game board
	void PrintWinningPiece(int x, int y);	//Checks whether to print a board piece in colour (a winner) or not
	char ChooseOption(std::string question, int numOptions);					//Checks the option the player has selected
	bool CheckWinner(char player, bool isPlayerTurn, bool isPvP, char p1Or2);	//Checks the winner of the game
	void PrintScores(bool isDraw, bool isPvP, bool isPlayerTurn, char p1Or2);	//Prints scores depending on the turn and winner

	void PlayGame(char p1Or2, bool easyMode, bool isPvP);	//Player vs Computer Easy mode

	void Customize();						//Allows player to change the game pieces
	char ChangePiece(char checkWithPlayer);	//Changes board piece with whatever the user inputs

	void SetGameEnd();			//Sets endGame to true
	bool GetHasGameEnded();		//Checks if game has ended

	void Minimax();				//MiniMax algorithm used for the computer's AI

private:
	CControl ctrl;					//Class supplying functions to support aesthetics of game
	char p1Piece;					//Player 1's piece
	char p2Piece;					//Player 2's piece
	char row;						//Row input for the board
	char col;						//Column input for the board
	bool endGame;					//Variable determining whether game has ended or not
	int p1Points;					//Player 1's points
	int p2Points;					//Player 2's points

	//Static
	static char board[3][3];
	static bool winnerBoard[3][3];
};

#endif // _TICTACTOE_H__68