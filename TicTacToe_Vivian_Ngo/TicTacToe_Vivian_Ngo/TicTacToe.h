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
#include "Board.h"

struct BestMove {				//BestMove stores row, int and score of the best found move
	BestMove() {};
	BestMove(int Score)			//BestScore allowing the return of only the score
		: score(Score) {}
	int row;					//row of best move
	int col;					//col of best move
	int score;					//score of best move
};

struct ABPruning {				//ABPruning stores ab values
	int alpha;					//alpha value
	int beta;					//beta value
};

class CTicTacToe
{
public:
	CTicTacToe();				//TicTacToe Constructor
	~CTicTacToe();				//TicTacToe Destructor
	
	void Title();				//Prints the Tic Tac Toe title text
	void StartUp();				//StartUp - A main menu screen for the game
	
	char ChooseOption(std::string question, int numOptions);					//Checks the option the player has selected
	bool CheckGameOver(char player, bool isPlayerTurn, bool isPvP, char p1Or2);	//Checks the winner of the game
	void PrintScores(bool isDraw, bool isPvP, bool isPlayerTurn, char p1Or2);	//Prints scores depending on the turn and winner

	void PlayGame(char p1Or2, bool easyMode, bool isPvP);	//Player vs Computer Easy mode

	void Customize();	//Allows player to change the game pieces
	char ChangePiece();	//Changes board piece with whatever the user inputs

	void MiniMax(char currentPlayer, char p1Or2, int& depth);	//MiniMax algorithm used for the computer's AI
	BestMove GetBestMove(char currentPlayer, char p1Or2, int& depth, ABPruning ab);
	int count;
private:
	CBoard* board;
	

	char p1Piece;					//Player 1's piece
	char p2Piece;					//Player 2's piece
	char row;						//Row input for the board
	char col;						//Column input for the board
	bool gameEnded;					//Variable determining whether game has ended or not
	int p1Points;					//Player 1's points
	int p2Points;					//Player 2's points
};

#endif // _TICTACTOE_H__68