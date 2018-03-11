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

#ifndef __GAME_H__
#define __GAME_H__



// Library Includes
#include <string>

// Local Includes
#include "control.h"
#include "board.h"
#include "ship.h"

// Types
// Constants
// Prototypes

#pragma once

class CGame : public CControl
{
public:
	//Member functions
	CGame();
	~CGame();


	//Methods
	void Title();
	void MainMenu();
	void PlayChoose();
	void PlayRandom();
	void PlayDebug();
	void EndingScreen();
	void EndingScreenLose();
	//Technical Methods

	//Keyboard detection

	// TF: Getters

private:
	// TF: Variable Type

	// TF: Access Specifier : Setters


protected:
};

#endif //__GAME_H__