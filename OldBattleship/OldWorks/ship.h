//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2017 Media Design School
//
// File Name : ship.h
// Description : Ship declaration file.
// Author : Vivian Ngo
// Mail : vivian.ngo7572@mediadesignschool.com
//

#ifndef __SHIP_H__
#define __SHIP_H__



// Library Includes
#include <string>

// Local Includes
// Types
// Constants
// Prototypes

#pragma once

enum ShipType
{
	PatrolBoat,		 //2
	Submarine,		 //3
	Destroyer,		 //3
	Battleship,		 //4
	AircraftCarrier, //5
	END				 //End of ship types
};

class CShip
{
public:
	//Member functions
	CShip(ShipType ship);
	~CShip();


	// TF: Access Specifier : Getters
	std::string GetName() const;		//Gets the name of the individual ship
	int GetTotalShipLives();			//Get how many lives are left (eg. oxoo == 3/4 lives)
	void RemoveShipLife(int arrayPos);	//Change 'o' to 'x'
	int GetNumShipBlocks();		//Get how many blocks the ship takes up (eg. PatrolBoats take up 2 blocks)
	char* GetShipArray();				//Returns the char array of the individual ship
	ShipType GetShipType();

	// Static Getters
	static int GetOverallShipCount();


private:
	// TF: Variable Type
	char* m_shipArray;
	ShipType m_shipType;
	bool m_isShipSet;

	// Static Variables
	static int m_overallShipCount;

	// TF: Access Specifier : Setters
	void SetShipBlocks(int spaces);
	void SetUpShip(ShipType ship);
	char* SetUpShipArray(char* arr, int numSpaces);


protected:
	std::string m_shipName;
	int m_shipBlocks;					//How many spaces the ship takes up
};

#endif //__SHIP_H__