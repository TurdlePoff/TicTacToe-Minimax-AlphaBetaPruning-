//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2017 Media Design School
//
// File Name : control.cpp
// Description : Control implementation file.
//				 Handles background functions for the game
// Author : Vivian Ngo
// Mail : vivian.ngo7572@mediadesignschool.com
//

// Library Includes
#include <string>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cTime>
#include <iomanip>
#include <cstdlib>

// Local Includes

// This Include

#include "board.h"
#include "ship.h"


using namespace std;

//Initializing static variables
char CBoard::EmptyBoard[21][21] =
{
	{ '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+' },
	{ '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|' },
	{ '|', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '|' },
	{ '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|' },
	{ '|', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '|' },
	{ '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|' },
	{ '|', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '|' },
	{ '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|' },
	{ '|', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '|' },
	{ '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|' },
	{ '|', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '|' },
	{ '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|' },
	{ '|', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '|' },
	{ '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|' },
	{ '|', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '|' },
	{ '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|' },
	{ '|', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '|' },
	{ '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|' },
	{ '|', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '|' },
	{ '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|' },
	{ '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+' }
};
int CBoard::m_playerBoardCoordX = 0;
int CBoard::m_playerBoardCoordY = 0;
char CBoard::StoredPlayerBoard[21][21];
char CBoard::StoredEnemyBoard[21][21];
char CBoard::StoredEnemyMOBoard[21][21];
char CBoard::StoredPlayerMOBoard[21][21];
char CBoard::LetterMarkers[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
int CBoard::NumberMarkers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
char CBoard::ShipLetters[] = { 'P', 'S', 'D', 'B', 'A' };
const int CBoard::m_totalShips = 17;
bool CBoard::m_GameWin = false;

CShip pPatrol(PatrolBoat);					//Initialise a patrolBoat
CShip pSubmarine(Submarine);				//Set ship mode to Submarine
CShip pDestroyer(Destroyer);				//Set ship mode to Destroyer
CShip pBattleship(Battleship);				//Set ship mode to Battleship
CShip pAircraft(AircraftCarrier);			//Set ship mode to AircraftCarrier


/**
*
* // TF: Constructor
*
* @author : Vivian Ngo
*
*/
CBoard::CBoard(BoardState state, bool isPlayer)
{
	m_isUserPlayer = isPlayer;
	SetPlayerPosition(9, 9);
	m_vertNotHor = false;
	SetBoardState(state);
	CopyToBoard(ViewingBoard, EmptyBoard);
	CopyToBoard(StoredBoard, EmptyBoard);
	CopyToBoard(EnemyShootingBoard, EmptyBoard);
	CopyToBoard(StoredEnemyMOBoard, EmptyBoard);
	CopyToBoard(StoredPlayerMOBoard, EmptyBoard);

	cPatCount = 0;
	cSubCount = 0;
	cDesCount = 0;
	cBatCount = 0;
	cAirCount = 0;
}


/**
*
* // TF: Destructor
*
* @author : Vivian Ngo
*
*/
CBoard::~CBoard()
{

}

/*
*
* KeyType Function for detecting arrow keys to place ships
*
* @return void
*
*/
void CBoard::BoatPlacement(bool showShips, CControl cont)
{
	m_showAIships = showShips;
	SetPlayerPosition(9, 9);
	SetShipMode(PatrolBoat);
	if (GetBoardState() == SetUpChooseBoard)		//If board state = SetUpChooseBoard - Player chooses ship position
	{
		SetShipMode(PatrolBoat);					//Set ship mode to PatrolBoat
		while (GetShipMode() == PatrolBoat)			//If in PatrolBoat mode
		{
			CopyToBoard(ViewingBoard, EmptyBoard);	//Set board to empty
			SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), pPatrol, false);		//Set player position coordinates
			PrintBoard(10, 5, ViewingBoard);						//Display the current board
			SetShipNavigation(PatrolBoat);			//Detect keyboard actions from user
		}
		//pPatrol.SetShipCoords(GetBoardShipCoordsX(), GetBoardShipCoordsY());
		ResetPlayerPosition();						//Reset the players position to the center of the board
		while (GetShipMode() == Submarine)			//If in Submarine mode
		{
			CopyToBoard(ViewingBoard, StoredBoard);	//Set board to the saved board
			SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), pSubmarine, false);	//Set player position coordinates
			PrintBoard(10, 5, ViewingBoard);						//Display the current board
			SetShipNavigation(Submarine);			//Detect keyboard actions from user
		}
		//pSubmarine.SetShipCoords(GetBoardShipCoordsX(), GetBoardShipCoordsY());
		ResetPlayerPosition();						//Reset the players position to the center of the board
		while (GetShipMode() == Destroyer)			//If in Destroyer mode
		{
			CopyToBoard(ViewingBoard, StoredBoard);	//Set board to the saved board
			SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), pDestroyer, false);	//Set player position coordinates
			PrintBoard(10, 5, ViewingBoard);						//Display the current board
			SetShipNavigation(Destroyer);			//Detect keyboard actions from user
		}
		//pDestroyer.SetShipCoords(GetBoardShipCoordsX(), GetBoardShipCoordsY());
		ResetPlayerPosition();						//Reset the players position to the center of the board
		while (GetShipMode() == Battleship)			//If in Battleship mode
		{
			CopyToBoard(ViewingBoard, StoredBoard); //Set board to the saved board
			SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), pBattleship, false);	//Set player position coordinates
			PrintBoard(10, 5, ViewingBoard);						//Display the current board
			SetShipNavigation(Battleship);			//Detect keyboard actions from user
		}
		//pBattleship.SetShipCoords(GetBoardShipCoordsX(), GetBoardShipCoordsY());
		ResetPlayerPosition();						//Reset the players position to the center of the board
		while (GetShipMode() == AircraftCarrier)	//If in AircraftCarrier mode
		{
			CopyToBoard(ViewingBoard, StoredBoard);	//Set board to the saved board
			SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), pAircraft, false);		//Set player position coordinates
			PrintBoard(10, 5, ViewingBoard);						//Display the current board
			SetShipNavigation(AircraftCarrier);		//Detect keyboard actions from user
		}
		//pAircraft.SetShipCoords(GetBoardShipCoordsX(), GetBoardShipCoordsY());
		if (GetIsUserPlayer())
		{
			CopyToBoard(StoredPlayerBoard, StoredBoard);
		}
	}
	else if (GetBoardState() == SetUpRandomBoard)	//If SetUpRandomBoard is selected
	{
		SetShipMode(PatrolBoat);					//Set ship mode to PatrolBoat
		while (GetShipMode() == PatrolBoat)			//If in PatrolBoat mode
		{
			RandomPlayChoose(PatrolBoat);			//Detect keyboard actions from user
			CopyToBoard(ViewingBoard, EmptyBoard);	//Set board to empty
			SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), pPatrol, false);		//Set player position coordinates
																							//PrintBoard();							//Display the current board
		}
		while (GetShipMode() == Submarine)			//If in Submarine mode
		{
			RandomPlayChoose(Submarine);			//Detect keyboard actions from user
			CopyToBoard(ViewingBoard, StoredBoard);	//Set board to the saved board
			SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), pSubmarine, false);	//Set player position coordinates
																							//PrintBoard();							//Display the current board
		}
		while (GetShipMode() == Destroyer)			//If in Destroyer mode
		{
			RandomPlayChoose(Destroyer);			//Detect keyboard actions from user
			CopyToBoard(ViewingBoard, StoredBoard);	//Set board to the saved board
			SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), pDestroyer, false);	//Set player position coordinates
																							//PrintBoard();							//Display the current board
		}
		while (GetShipMode() == Battleship)			//If in Battleship mode
		{
			RandomPlayChoose(Battleship);			//Detect keyboard actions from user
			CopyToBoard(ViewingBoard, StoredBoard); //Set board to the saved board
			SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), pBattleship, false);	//Set player position coordinates
																							//PrintBoard();							//Display the current board
		}
		if (GetShipMode() == AircraftCarrier)		//If in Battleship mode
		{
			RandomPlayChoose(AircraftCarrier);		//Detect keyboard actions from user
			CopyToBoard(ViewingBoard, StoredBoard); //Set board to the saved board
			SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), pAircraft, false);	//Set player position coordinates
			PrintBoard(10, 5, ViewingBoard);						//Display the current board
		}
		SetDebugMode(showShips);
		if (GetIsUserPlayer())
		{
			CopyToBoard(StoredPlayerBoard, StoredBoard);
		}
		else
		{
			CopyToBoard(StoredEnemyBoard, StoredBoard);
		}
	}
}

/*
*
* Copys one boards values to another
*
* @author : Vivian Ngo
*
*/
void CBoard::CopyToBoard(char boardToClear[][21], char newBoard[][21])
{
	// TF: Array
	for (int i = 0; i < 21; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{
			boardToClear[i][j] = newBoard[i][j];
		}
	}
}

/*
*
* Prints current board to the screen
*
* @author : Vivian Ngo
*
*/
void CBoard::PrintBoard(int xOnScreen, int yOnScreen, char board[][21])
{
	for (int y = 0; y < 21; ++y)
	{
		
		if (y < 10) //If count is less than 10 (as there are 10 marker values each)
		{
			GotoXY(xOnScreen-2, yOnScreen + 1 + y * 2);
			cout << LetterMarkers[y];
			GotoXY(xOnScreen+1 + y * 2, yOnScreen + 21);
			cout << NumberMarkers[y];
		}
		GotoXY(xOnScreen, yOnScreen + y);
		
		for (int x = 0; x < 21; ++x)
		{
			if (board[y][x] == 'X')
			{
				SetColour(30);
				cout << board[y][x];
			}
			else if (board[y][x] == 'M')
			{
				SetColour(31);
				cout << board[y][x];
			}
			else if (board[y][x] == 'O')
			{
				SetColour(27);
				cout << board[y][x];
			}
			else if (board[y][x] == 'P' || board[y][x] == 'S' || board[y][x] == 'D' 
				  || board[y][x] == 'B' || board[y][x] == 'A')
			{
				SetColour(26);
				cout << board[y][x];
			}
			else
			{
				SetColour(7);
				cout << board[y][x];
			}
		}
	}
}

/*
*
* Function for the user to use keys to choose their ship positions
*
* @author : Vivian Ngo
*
*/
void CBoard::SetShipNavigation(CShip ship)
{
	switch (KeyDetection())
	{
	case SPACE:
	{	//Check if spot is clear of ships before placing it
		if (CheckIsSpotEmpty(GetBoardShipCoordsX(), GetBoardShipCoordsY(), ship))
		{
			SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), ship, true);
			switch (GetShipMode())
			{
			case PatrolBoat:
			{
				SetShipMode(Submarine);
				break;
			}
			case Submarine:
			{
				SetShipMode(Destroyer);
				break;
			}
			case Destroyer:
			{
				SetShipMode(Battleship);
				break;
			}
			case Battleship:
			{
				SetShipMode(AircraftCarrier);
				break;
			}
			case AircraftCarrier:
			{
				SetShipMode(END);
				break;
			}
			}
		}
		break;
	}
	case ROTATE:
	{
		SetVertNotHor(ship);
		break;
	}
	case EXIT:
	{
		exit(0);
		break;
	}
	case UP:
	{
		if (GetBoardShipCoordsY() >= 3)
		{
			SetPlayerBoardCoordsY(GetBoardShipCoordsY() - 2);
		}
		break;
	}
	case DOWN:
	{
		if (GetVertNotHor())
		{
			if (GetBoardShipCoordsY() + ship.GetNumShipBlocks() <= 17)//CheckIsSpotEmpty(GetBoardShipCoordsX(), GetBoardShipCoordsY() + 2, ship))
			{
				SetPlayerBoardCoordsY(GetBoardShipCoordsY() + 2);
			}
		}
		else
		{
			if (GetBoardShipCoordsY() <= 17)//CheckIsSpotEmpty(GetBoardShipCoordsX(), GetBoardShipCoordsY() + 2, ship))
			{
				SetPlayerBoardCoordsY(GetBoardShipCoordsY() + 2);
			}
		}
		break;
	}
	case LEFT:
	{
		if (GetBoardShipCoordsX() >= 3) //CheckIsSpotEmpty(GetBoardShipCoordsX() - 2, GetBoardShipCoordsY(), ship))
		{
			SetPlayerBoardCoordsX(GetBoardShipCoordsX() - 2);
		}
		break;
	}
	case RIGHT:
	{
		if (GetVertNotHor())
		{
			if (GetBoardShipCoordsX() <= 17)//CheckIsSpotEmpty(GetBoardShipCoordsX() + 2, GetBoardShipCoordsY(), ship))
			{
				SetPlayerBoardCoordsX(GetBoardShipCoordsX() + 2);
			}
		}
		else
		{
			if (GetBoardShipCoordsX() + ship.GetNumShipBlocks() <= 17)//CheckIsSpotEmpty(GetBoardShipCoordsX() + 2, GetBoardShipCoordsY(), ship))
			{
				SetPlayerBoardCoordsX(GetBoardShipCoordsX() + 2);
			}
		}
		break;
	}
	}
}

/*
*
* Function that randomly generates coordinates on the board
*
* @author : Vivian Ngo
*
*/
void CBoard::RandCoordGen(int* x, int* y, int* direction)
{
	// TF: Pointer Dereferenced
	// TF: Pseudo Random Number
	*x = rand() % 19 + 1;		 //Generate a number from 1-19
	if (*x % 2 == 0 && *x != 0)  //If it is even and not 0
	{
		*x -= 1;					 //-1 (as i use odd numbers for my board)
	}

	// TF: Pointer Dereferenced	
	*y = rand() % 19 + 1;		 //Generate a number from 1-19
	if (*y % 2 == 0 && *y != 0)  //If it is even and not 0
	{
		*y -= 1;				 //-1 (as i use odd numbers for my board)
	}

	// TF: Pointer Dereferenced
	*direction = rand() % 2 + 1; //Generate either 1 or 2 for the direction boolean
}

/*
*
* Randomly generates positions on the board // AI playing batleship
*
* @author : Vivian Ngo
*/
void CBoard::RandomGenAI()
{
	bool success = false;
	while (!success)
	{
		int x = 20;
		int y = 20;
		int randDirection = 0;

		RandCoordGen(&x, &y, &randDirection);
		SetPlayerPosition(x, y);
		success = SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), true);
	}
}

/*
*
* Function to randomly place ships on the board
*
* @author : Vivian Ngo
*
*/
void CBoard::RandomPlayChoose(CShip ship)
{
	bool success = false;
	while (!success)
	{
		int x = 20;
		int y = 20;
		int randDirection = 0;

		RandCoordGen(&x, &y, &randDirection);

		if (randDirection == 1)
		{
			m_vertNotHor = true;
		}
		else
		{
			m_vertNotHor = false;
		}


		if (CheckIsSpotEmpty(x, y, ship))
		{
			success = true;
			SetPlayerPosition(x, y);
			SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), ship, true);
			switch (GetShipMode())
			{
			case PatrolBoat:
			{
				SetShipMode(Submarine);
				break;
			}
			case Submarine:
			{
				SetShipMode(Destroyer);
				break;
			}
			case Destroyer:
			{
				SetShipMode(Battleship);
				break;
			}
			case Battleship:
			{
				SetShipMode(AircraftCarrier);
				break;
			}
			case AircraftCarrier:
			{
				//SetShipMode(END);
				break;
			}
			}
		}
	}
}

/*
*
* Sets a board state //Different parts of the gameplay
*
* @author : Vivian Ngo
*
*/
void CBoard::SetBoardState(BoardState state)
{
	m_state = state;
}

/*
*
* Gets a board state //Different parts of the gameplay
*
* @author : Vivian Ngo
*
* @returns BoardState
*
*/
BoardState CBoard::GetBoardState()
{
	return m_state;
}


/*
*
* Function to set x player board position
*
* @author : Vivian Ngo
*
*/
void CBoard::SetPlayerBoardCoordsX(int x)
{
	m_playerBoardCoordX = x;
}

/*
*
* Function to set y player board position
*
* @author : Vivian Ngo
*
*/
void CBoard::SetPlayerBoardCoordsY(int y)
{
	m_playerBoardCoordY = y;
}

/*
*
* Getter to get x player board position
*
* @author : Vivian Ngo
* @return char
*/
char CBoard::GetBoardShipCoordsX()
{
	return m_playerBoardCoordX;
}

/*
*
* Getter to get y player board position
*
* @author : Vivian Ngo
* @return char
*/
char CBoard::GetBoardShipCoordsY()
{
	return m_playerBoardCoordY;
}

/*
*
* Setter to set shipmode (for ship placement)
*
* @author : Vivian Ngo
*/
void CBoard::SetShipMode(ShipType type)
{
	m_shipMode = type;
}

/*
*
* Getter to get shipmode (for ship placement)
*
* @author : Vivian Ngo
* @return ShipType
*/
ShipType CBoard::GetShipMode()
{
	return m_shipMode;
}

/*
*
* Function checking whether the place on the board is empty (for ship placement)
*
* @author : Vivian Ngo
* @return bool
*/
bool CBoard::CheckIsSpotEmpty(int x, int y, CShip ship)
{
	int emptyCount = 0;
	for (int i = 0; i < ship.GetNumShipBlocks(); ++i)
	{
		if (GetVertNotHor() == true)
		{
			if (StoredBoard[y + i * 2][x] == ' ')
			{
				++emptyCount;
			}
		}
		else
		{
			if (StoredBoard[y][x + i * 2] == ' ')
			{
				++emptyCount;
			}
		}
	}
	if (emptyCount == ship.GetNumShipBlocks())
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*
*
* Setter to set ships to the board
*
* @author : Vivian Ngo
*
*/
void CBoard::SetToBoard(int placeY, int placeX, CShip ship, bool save)
{
	for (int i = 0; i < ship.GetNumShipBlocks(); ++i)
	{
		// TF: Relational Operator
		// TF: Conditional Statement
		if (GetVertNotHor() == true) //If Ship is vertical
		{
			//Vertical
			// TF: Conditional Statement
			if (save)	//If save is true, then copy it to storage
			{
				StoredBoard[placeY + i * 2][placeX] = ship.GetShipArray()[i];
			}
			else		//If save is false, then copy it to the temporary board
			{
				ViewingBoard[placeY + i * 2][placeX] = ship.GetShipArray()[i];
			}
		}
		else //If Ship is horizontal
		{
			//Horizontal
			if (save)	//If save is true, then copy it to storage
			{
				StoredBoard[placeY][placeX + i * 2] = ship.GetShipArray()[i];
			}
			else		//If save is false, then copy it to the temporary board
			{
				ViewingBoard[placeY][placeX + i * 2] = ship.GetShipArray()[i];
			}
		}
	}
}

/*
*
* Checks if a ship has been hit
*
* @author : Vivian Ngo
* @return true
*/
bool CBoard::CheckIsHit(int x, int y)
{
	bool shipIsHit = false;
	for (char c : ShipLetters)
	{
		if ((GetBoardState() == PlayerTurn && StoredEnemyBoard[y][x] == c) || ((GetBoardState() == AITurn && StoredPlayerBoard[y][x] == c)))
		{
			shipIsHit = true;
			switch (c)
			{
			case 'P':
			{
				++cPatCount;
				break;
			}
			case 'S':
			{
				++cSubCount;
				break;
			}
			case 'D':
			{
				++cDesCount;
				break;
			}
			case 'B':
			{
				++cBatCount;
				break;
			}
			case 'A':
			{
				++cAirCount;
				break;
			}
			}
		}
	}
	if (shipIsHit)
	{
		return true;
	}
	else
	{
		return false;
	}
}




/*
*
* Setter to set ships to the board
*
* @author : Vivian Ngo
*
*/
bool CBoard::SetToBoard(int placeY, int placeX, bool save)
{
	if (save)
	{
		if (GetBoardState() == PlayerTurn)
		{
			if (CheckIsHit(placeX, placeY) && StoredEnemyBoard[placeY][placeX] != 'X' && StoredEnemyBoard[placeY][placeX] != 'M')	//If save is true, then copy it to storage
			{
				GotoXY(15, 31);  
				StoredEnemyMOBoard[placeY][placeX] = 'X';
				StoredEnemyBoard[placeY][placeX] = 'X';
				Sleep(100);
				SetBoardState(AITurn);
				return true;
			}
			else if (StoredEnemyBoard[placeY][placeX] == 'X' || StoredEnemyBoard[placeY][placeX] == 'M')
			{
				GotoXY(15, 32); //Already shot here
				return false;
			}
			else
			{
				CheckIsHit(placeX, placeY);
				StoredEnemyMOBoard[placeY][placeX] = 'M';
				StoredEnemyBoard[placeY][placeX] = 'M';
				Sleep(100);		//Miss shot here
				SetBoardState(AITurn);
				return false;
			}
		}
		else if(GetBoardState() == AITurn)
		{
			if (CheckIsHit(placeX, placeY) && StoredPlayerBoard[placeY][placeX] != 'X' && StoredPlayerBoard[placeY][placeX] != 'M')	//If save is true, then copy it to storage
			{
				GotoXY(15, 31);
				StoredPlayerMOBoard[placeY][placeX] = 'X';
				StoredPlayerBoard[placeY][placeX] = 'X';
				SetBoardState(PlayerTurn);
				Sleep(100);
				return true;
			}
			else if (StoredPlayerBoard[placeY][placeX] == 'X' || StoredPlayerBoard[placeY][placeX] == 'M')
			{
				GotoXY(15, 32);
				return false;
			}
			else
			{
				CheckIsHit(placeX, placeY);
				GotoXY(15, 33);
				StoredPlayerMOBoard[placeY][placeX] = 'M';
				StoredPlayerBoard[placeY][placeX] = 'M';
				SetBoardState(PlayerTurn);
				return true;
			}
		}
	}		//If save is false, then copy it to the temporary board
	else
	{
		if (GetBoardState() == PlayerTurn)
		{
			GotoXY(15, 28); cout << "Set your battleships using the arrow keys";
			GotoXY(19, 29); cout << "Press space to shoot your missile!       ";

			EnemyShootingBoard[placeY][placeX] = 'O';
		}
	}
	//PrintBoard(StoredEnemyBoard);
	return false;
}

/*
*
* Function for gameplay
*
* @author : Vivian Ngo
*
*/
void CBoard::GamePlay()
{
	ResetPlayerPosition();
	SetBoardState(PlayerTurn);
	while (GetBoardState() == PlayerTurn)
	{
		GotoXY(35, 30); cout << "                                   ";
		//CopyToBoard(EnemyShootingBoard, StoredEnemyBoard);	//Set board to empty
		CopyToBoard(EnemyShootingBoard, StoredEnemyMOBoard);
		SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), false);
		PrintBoard(45, 5, EnemyShootingBoard);
		PlayNavigation();
	}
	SetBoardState(PlayerTurn);
	//CopyToBoard(EnemyShootingBoard, StoredEnemyBoard);	//Set board to empty
	CopyToBoard(EnemyShootingBoard, StoredEnemyMOBoard);
	SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), false);
	if (GetIsDebugMode() == true)
	{
		PrintBoard(45, 30, StoredEnemyBoard);
	}
	SetBoardState(AITurn);
}

/*
*
* Function managing AI gameplay
*
* @author : Vivian Ngo
*
*/
void CBoard::AIplay()
{
	ResetPlayerPosition();
	SetBoardState(AITurn);
	while (GetBoardState() == AITurn)
	{
		GotoXY(35, 30); cout << "                                   ";
		CopyToBoard(ViewingBoard, StoredPlayerBoard);	//Set board to empty
		SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), false);
		PrintBoard(10, 5, ViewingBoard);						//Display the current board
		if (GetIsDebugMode() == true)
		{
			PrintBoard(10, 30, StoredPlayerMOBoard); //Display the current board
		}
		RandomGenAI();
	}
	SetBoardState(AITurn);
	CopyToBoard(ViewingBoard, StoredPlayerBoard);	//Set board to empty
	SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), false);
	PrintBoard(10, 5, ViewingBoard); //Display the current board
	if (GetIsDebugMode() == true)
	{
		PrintBoard(10, 30, StoredPlayerMOBoard); //Display the current board
	}
	SetBoardState(PlayerTurn);
}

/*
*
* bool function checking winner
*
* @author : Vivian Ngo
* @returns bool
*/
bool CBoard::CheckWin()
{
	if ((cPatCount + cSubCount + cDesCount + cBatCount + cAirCount) == m_totalShips)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
*
* Function for the user to use keys to choose their ship positions
*
* @author : Vivian Ngo
*
*/
void CBoard::PlayNavigation()
{
	switch (KeyDetection())
	{
	case SPACE:
	{
		//Set hit or miss
		SetToBoard(GetBoardShipCoordsY(), GetBoardShipCoordsX(), true);
		break;
	}
	case EXIT:
	{
		exit(0);
		break;
	}
	case UP:
	{
		if (GetBoardShipCoordsY() >= 3)
		{
			SetPlayerBoardCoordsY(GetBoardShipCoordsY() - 2);
		}
		break;
	}
	case DOWN:
	{
		if (GetBoardShipCoordsY() <= 17)
		{
			SetPlayerBoardCoordsY(GetBoardShipCoordsY() + 2);
		}
		break;
	}
	case LEFT:
	{
		if (GetBoardShipCoordsX() >= 3)
		{
			SetPlayerBoardCoordsX(GetBoardShipCoordsX() - 2);
		}
		break;
	}
	case RIGHT:
	{
		if (GetBoardShipCoordsX() <= 17)
		{
			SetPlayerBoardCoordsX(GetBoardShipCoordsX() + 2);
		}
		break;
	}
	}
}


/*
*
* Getter to get ship orientation/rotation
*
* @author : Vivian Ngo
* @return bool
*/
bool CBoard::GetVertNotHor()
{
	return m_vertNotHor;
}

/*
*
* Setter to set ship orientation/rotation
*
* @author : Vivian Ngo
*
*/
void CBoard::SetVertNotHor(CShip ship)
{
	if (m_vertNotHor == true) //If it is vertical
	{
		//Check if there is an object in the way
		if (CheckIsSpotEmpty(GetBoardShipCoordsX() + (ship.GetNumShipBlocks() * 2 - 2), GetBoardShipCoordsY(), ship))
		{
			m_vertNotHor = !m_vertNotHor;
		}
	}
	else
	{
		//Check if there is an object in the way
		if (CheckIsSpotEmpty(GetBoardShipCoordsX(), GetBoardShipCoordsY() + (ship.GetNumShipBlocks() * 2 - 2), ship))
		{
			m_vertNotHor = !m_vertNotHor;
		}

	}
}

/*
*
* Set player on board position
*
* @author : Vivian Ngo
*
*/
void CBoard::SetPlayerPosition(int x, int y)
{
	SetPlayerBoardCoordsX(x);
	SetPlayerBoardCoordsY(y);
}

/*
*
* Reset player on board position
*
* @author : Vivian Ngo
*
*/
void CBoard::ResetPlayerPosition()
{
	SetPlayerBoardCoordsX(9);
	SetPlayerBoardCoordsY(9);
	m_vertNotHor = false;
}

/*
*
* Check if current user is the player
*
* @author : Vivian Ngo
* @return bool
*/
bool CBoard::GetIsUserPlayer()
{
	return m_isUserPlayer;
}

/*
*
* Set mode to debug
*
* @author : Vivian Ngo
*
*/
void CBoard::SetDebugMode(bool val)
{
	m_isDebug = val;
}

/*
*
* Getter to check if game is in debug mode
*
* @author : Vivian Ngo
*
*/
bool CBoard::GetIsDebugMode()
{
	return m_isDebug;
}
