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

#ifndef __CONTROL_H__
#define __CONTROL_H__



// Library Includes
#include <string>
#include <Windows.h>

// Local Includes
// Types
// Constants
// Prototypes

#pragma once

enum MenuType
{
	Start, Exit, Debug, GameChoose, GameRandom,
	ExitMode, DebugMode, PlayGameChoose, PlayGameRandom, Ending
};

enum KeyType
{
	UP, DOWN, LEFT, RIGHT, SPACE, EXIT, ROTATE
};

class CControl
{
public:
	//Member functions
	CControl();
	~CControl();


	//Methods
	void MenuNavigation();

	//Technical Methods
	void Spc(char in, int size);
	void ClearScreen();
	void GotoXY(int _iX, int _iY);

	//Keyboard detection
	KeyType KeyDetection();

	// TF: Getters
	int GetMenuType();

	// TF: Setters
	void SetColour(WORD color);

private:
	// TF: Variable Type
	MenuType m_menuType;

	// TF: Access Specifier : Setters
	void SetMenuType(MenuType type);

protected:
};

#endif //__CONTROL_H__