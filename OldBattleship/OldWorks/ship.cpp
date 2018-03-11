//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2017 Media Design School
//
// File Name : ship.cpp
// Description : Ship implementation file.
// Author : Vivian Ngo
// Mail : vivian.ngo7572@mediadesignschool.com
//

// Library Includes
#include <string>
#include <iostream>

// Local Includes
// This Includes
#include "ship.h"

// Static Variables
int CShip::m_overallShipCount = 0;

// Static Function Prototypes
// Implementation
// Constructor

using namespace std;

/*
* // TF: Constructor
* CShip Constructor
*
* Each ship has
*   - A name
*	- Blocks
*	- Lives
*	- An Array
*
*/
CShip::CShip(ShipType ship)
{
	SetUpShip(ship);
	this->m_shipArray = 0;
	SetUpShipArray(this->m_shipArray, GetNumShipBlocks());
	//m_shipXCoord = 0;
	//m_shipYCoord = 0;
	++m_overallShipCount;
}

/*
*
* CShip Destructor
*
*/
CShip::~CShip()
{
	/*delete m_shipArray;
	m_shipArray = 0;
	--m_overallShipCount;*/
}

/*
*
* Function that sets the number of blocks a specific ship has
*
* @return void
*
*/
void CShip::SetShipBlocks(int spaces)
{
	this->m_shipBlocks = spaces;
}

/*
*
* Function that sets the string name of a specific ship
* while also setting the number of blocks it takes up
*
* @return void
*
*/
void CShip::SetUpShip(ShipType ship)
{
	switch (ship)
	{
	case PatrolBoat:
	{
		this->m_shipName = "Patrol Boat";
		SetShipBlocks(2);
		break;
	}
	case Submarine:
	{
		this->m_shipName = "Submarine";
		this->SetShipBlocks(3);
		break;
	}
	case Destroyer:
	{
		this->m_shipName = "Destroyer";
		this->SetShipBlocks(3);
		break;
	}
	case Battleship:
	{
		this->m_shipName = "Battleship";
		this->SetShipBlocks(4);
		break;
	}
	case AircraftCarrier:
	{
		this->m_shipName = "Aircraft Carrier";
		this->SetShipBlocks(5);
		break;
	}
	}
	this->m_shipType = ship; //Set enums for each individual ship
}

/*
*
* Function that returns the number of blocks a specific ship takes up
*
* @return int
*
*/
int CShip::GetNumShipBlocks()
{
	return this->m_shipBlocks;
}

/*
*
* Function that returns the name of a specific ship
*
* @return string
*
*/
string CShip::GetName() const
{
	return this->m_shipName;
}

/*
*
* Function that sets up the ships array
*
* @return int
*
*/
char* CShip::SetUpShipArray(char* arr, int numSpaces)
{
	this->m_shipArray = new char[numSpaces];
	for (int i = 0; i < numSpaces; ++i)
	{
		if (GetShipType() == PatrolBoat)		//Set symbols of patrol boat to P
		{
			this->m_shipArray[i] = 'P';
		}
		else if (GetShipType() == Submarine)	//Set symbols of submarine to S
		{
			this->m_shipArray[i] = 'S';
		}
		else if (GetShipType() == Destroyer)	//Set symbols of destroyer to D
		{
			this->m_shipArray[i] = 'D';
		}
		else if (GetShipType() == Battleship)	//Set symbols of battleship to B
		{
			this->m_shipArray[i] = 'B';
		}
		else if (GetShipType() == AircraftCarrier)//If type == AirCraftCarrier		//Set symbols of AirCraftCarrier to A
		{
			this->m_shipArray[i] = 'A';
		}
		else
		{
			//do nothing to END value
		}
	}
	return this->m_shipArray;
}

/*
*
* Function that returns the array of a specific ship
*
* @return char*
*
*/
char* CShip::GetShipArray()
{
	return this->m_shipArray;
}

/*
*
* Function that removes a life from withion the ships array (sets o -> x )
*
* @return void
*
*/
void CShip::RemoveShipLife(int arrayPos)
{
	this->m_shipArray[arrayPos] = 'x';
}

/*
*
* Function that gets how many lives are left for the individual ship
*
* @return int
*
*/
int CShip::GetTotalShipLives()
{
	int lifeCount = 0;
	for (int i = 0; i < GetNumShipBlocks(); i++)
	{
		if (this->m_shipArray[i] == 'o')
			++lifeCount;
	}
	return lifeCount;
}

/*
*
* Function that returns the overall ship count
*
* @return int
*
*/
int CShip::GetOverallShipCount()
{
	return m_overallShipCount;
}

/*
*
* Function that returns the ship type
*
* @return ShipType
*
*/
ShipType CShip::GetShipType()
{
	return m_shipType;
}