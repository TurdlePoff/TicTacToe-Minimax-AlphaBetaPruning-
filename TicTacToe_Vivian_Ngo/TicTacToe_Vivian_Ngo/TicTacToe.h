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
	
	//void Title();
	void StartUp();				//StartUp - a title screen for the game
	void SetGameEnd();			//Sets endGame to true
	bool GetHasGameEnded();		//Checks if game has ended

	char ChooseOption(std::string question, int numOptions); //Checks the option the player selected
	char ChangePiece(char checkWithPlayer);
	//int PosSelection();
	void PrintBoard();					//Prints the game board
	void PrintWinningPiece(int x, int y);
	bool CheckWinner(char player, bool isPlayerTurn, bool isPvP, char p1Or2);	//Checks the winner of the game
	void PrintScores(char p1Or2, bool isPvP, bool isPlayerTurn, bool isDraw);

	void PlayGame(char p1Or2, bool easyMode, bool pvp);	//Player vs Computer Easy mode
	//void PvCHard(char p1Or2);	//Player vs Computer Hard mode
	void PlayerVsPlayer();		//Player vs Player
	void Customize();

	void Minimax(); //----------------------------------

	//Setters and Getters
	void SetP1Piece(char p1);	//Sets Player 1's symbol
	void SetP2Piece(char p2);	//Sets Player 2's symbol
	char GetP1Piece();			//Gets Player 1's symbol
	char GetP2Piece();			//Gets Player 2's symbol

private:
	CControl ctrl;				//Class supplying functions to support aesthetics of game
	char p1Piece;				//Player 1's symbol
	char p2Piece;				//Player 2's symbol
	bool endGame;				//variable determining whether game has ended or not
	int p1Points;
	int p2Points;
	char row;
	char col;
};

#endif // _TICTACTOE_H__68