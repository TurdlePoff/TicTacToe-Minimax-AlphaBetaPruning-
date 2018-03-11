//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2017 Media Design School
//
// File Name : board.h
// Description : board declaration file.
// Author : Vivian Ngo
// Mail : vivian.ngo7572@mediadesignschool.com
//

#ifndef __BOARD_H__
#define __BOARD_H__



// Library Includes
#include <string>
#include <cTime>
// Local Includes
#include "control.h"
#include "ship.h"

// Types
// Constants
// Prototypes



#pragma once

//States of the board when game is in progress
enum BoardState
{
	SetUpChooseBoard, SetUpRandomBoard, PlayerTurn, AITurn
};

// TF: Class
class CBoard : CControl 
{
public:
	//Member functions
	CBoard(BoardState m_state, bool isPlayer); //Board constructor
	~CBoard();	//Board Destructor

	//Methods
	// TF: Class Instance
	void CopyToBoard(char boardToReplace[][21], char newBoard[][21]); //Copies the data from one board to another
	void PrintBoard(int xOnScreenchar, int yOnScreen, char boardToPrint[][21]);		//print player board else print enemy board
	void BoatPlacement(bool showShips, CControl cont);//Set up mode for battleships (choose or randomize ship pieces)
	void RandomPlayChoose(CShip ship); //Function to randomly place ships on the board
	void ResetPlayerPosition();	//Resets player position to center of the board
	void PlayNavigation();
	void GamePlay(); //Returns true if turn is over
	bool CheckWin();
	void AIplay();
	void RandomGenAI();
	//bool CheckShips(int x, int y);

	// TF: Pointer
	void RandCoordGen(int* x, int* y, int* direction); //Randomly generates coordinates 

													   // TF: Access Specifier : Getters
	BoardState GetBoardState();
	char GetBoardShipCoordsX();		//Where keyboard x cursor is
	char GetBoardShipCoordsY();		//Where keyboard y cursor is
	ShipType GetShipMode();
	bool CheckIsSpotEmpty(int x, int y, CShip ship); //Checks if there is a ship or object in the way
	bool CheckIsHit(int x, int y); //Checks if there is something on the board
	bool GetVertNotHor();			//If true it is vert else horizontal
	bool GetIsUserPlayer();			//Gets the bool value for whether the board is used by a player or cpu
	bool GetIsDebugMode();

private:
	// TF: Variable Type
	BoardState m_state;				//States of the board when game is in progress
	char ViewingBoard[21][21];		//Viewing board. The updated board the user sees
	char EnemyShootingBoard[21][21];		//Viewing board. The updated board the user sees
	char StoredBoard[21][21];		//Stored board. A board that contains stored ships, miss and hits
	static char EmptyBoard[21][21];	//Static empty board //used to clear other boards
	static char StoredPlayerBoard[21][21];
	static char StoredEnemyMOBoard[21][21]; //Marker only boards
	static char StoredPlayerMOBoard[21][21];//Marker only boards
	static char StoredEnemyBoard[21][21];
	static char LetterMarkers[];
	static int NumberMarkers[];
	static char ShipLetters[];
	static const int m_totalShips;
	static bool m_GameWin;
	bool m_showAIships;
	bool m_isDebug;

	ShipType m_shipMode;	//ShipMode when setting up ship positions
	bool m_isUserPlayer;	//Is the user a player or a cpu
	bool m_vertNotHor;		//Variable for rotation where true = vertical and false = horizontal

	int cPatCount;
	int cSubCount;
	int cDesCount;
	int cBatCount;
	int cAirCount;

	static int m_playerBoardCoordX;	//The coordinate for the x value to navigate the game board
	static int m_playerBoardCoordY; //The coordinate for the y value to navigate the game board

									// TF: Setters
	void SetShipNavigation(CShip ship);		//Calls the function for the user to use keys to choose their ship positions
	void SetPlayerBoardCoordsX(int x);		//Setter to set x coord to navigate the game board
	void SetPlayerBoardCoordsY(int y);		//Setter to set y coord to navigate the game board
	void SetShipMode(ShipType type);		//Sets the ship mode (used for setting up positions)
	void SetToBoard(int placeX, int placeY, CShip ship, bool save);	//Sets the chosen ship position to a board
	bool SetToBoard(int placeY, int placeX, bool save); //For setting hit or miss markers
	void SetBoardState(BoardState m_state);	//Set the boardstate of the current game
	void SetVertNotHor(CShip ship);			//Change rotation of ship
	void SetPlayerPosition(int x, int y);	//Set player position for both x and y coordinates
	void SetDebugMode(bool val);

protected:

};

#endif //__BOARD_H__