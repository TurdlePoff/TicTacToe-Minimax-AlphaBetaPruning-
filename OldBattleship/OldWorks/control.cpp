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
#include "control.h"

using namespace std;

/**
*
* TF: Constructor
*
* Control functions
*   - GamePlay:  MainMenu, Title, MenuNavigation
*	- Technical: Spc, ClearScreen, GotoXY, KeyDetection, GetMenuType, SetColour, SetMenuType
*
* @author : Vivian Ngo
*
*/
CControl::CControl()
{
	//Set window size and position
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL)
	{				 //  position	 size
		MoveWindow(hwnd, 342, 5, 680, 700, TRUE);  //Set console position to center
	}

	SetMenuType(Start);		//Set game state to start screen
}

/**
*
* TF: Destructor
*
* @author : Vivian Ngo
*
*/
CControl::~CControl() {}

/*
*
* Function that allows the player to navigate the menu screen via keyboard
*
* @return KeyType - returns an enum of the key name
*
*/
void CControl::MenuNavigation()
{
	switch (KeyDetection())
	{
	case SPACE:
	{
		if (GetMenuType() < 3)
		{
			if (GetMenuType() == Start)
			{
				SetMenuType(GameChoose);
			}
			else if (GetMenuType() == Exit)
			{
				exit(0);
			}
			else if (GetMenuType() == Debug)
			{
				SetMenuType(DebugMode);
			}
		}
		else if (GetMenuType() == GameChoose)
		{
			SetMenuType(PlayGameChoose);
		}
		else if (GetMenuType() == GameRandom)
		{
			SetMenuType(PlayGameRandom);
		}
		break;
	}
	case EXIT:
	{
		SetMenuType(ExitMode);
		break;
	}
	case UP:
	{
		if (GetMenuType() == GameChoose || GetMenuType() == GameRandom) //If game is in 'Game' mode, change the selection
		{
			if (GetMenuType() == GameChoose)
			{										  //If highlight is on gamechoose
				SetMenuType(GameRandom);			  //Change to gamerandom when moved up
			}
			else //if menu == GameRandom
			{										  //If highlight is on gamerandom
				SetMenuType(GameChoose);			  //Change to gamechoose when moved up
			}
		}
		else if (GetMenuType() < 3)					  //If the game is in main menu, change the selection
		{
			if (GetMenuType() == Start)
			{										  //If highlight is on start
				SetMenuType(Debug);					  //Change to debug when moved up
			}
			else if (GetMenuType() == Exit)
			{										  //If highlight is on exit
				SetMenuType(Start);					  //Change to start when moved up
			}
			else
			{										  //If highlight is on debug
				SetMenuType(Exit);					  //Change to exit when moved up
			}
		}
		break;
	}
	case DOWN:
	{
		if (GetMenuType() == GameChoose || GetMenuType() == GameRandom) //If game is in 'Game' mode, change the selection
		{
			if (GetMenuType() == GameChoose)
			{										  //If highlight is on start
				SetMenuType(GameRandom);			  //Change to debug when moved down
			}
			else //if menu == GameRandom
			{										  //If highlight is on exit
				SetMenuType(GameChoose);			  //Change to start when moved up
			}
		}
		else if (GetMenuType() < 3)					  //If the game is in main menu, change the selection
		{
			if (GetMenuType() == Start)
			{										  //If highlight is on Start
				SetMenuType(Exit);					  //Change to exit
			}
			else if (GetMenuType() == Exit)
			{										  //If highlight is on Exit
				SetMenuType(Debug);					  //Change to debug
			}
			else
			{										  //If highlight is on Debug
				SetMenuType(Start);					  //Change to start
			}
		}
		break;
	}
	}
}

/*
*
* Function Getting the MenuType
*
* @return int m_menuType
*
*/
int CControl::GetMenuType()
{
	return m_menuType;
}

/*
*
* Function for Setting MenuType
*
* @return void.
*
*/
void CControl::SetMenuType(MenuType type)
{
	m_menuType = type;
}


/**
*
* Function for creating boxes of whatever character the user wishes to repeat
*
* @author : Vivian Ngo
*
* @return void.
*
*/
void CControl::Spc(char in, int size)
{
	cout << setfill(in) << setw(size) << in;
}

/*
*
* Function for setting colour of text
*
* @return void.
*
*/
void CControl::SetColour(WORD color)
{
	//     Colours:
	//     0 = Black      |   4 = Red            |   8 = DarkGray     |   12 = LightRed
	//     1 = Blue       |   5 = Magenta        |   9 = LightBlue    |   13 = LightMagenta
	//     2 = Green      |   6 = Yellow         |   10 = LightGreen  |   14 = LightYellow
	//     3 = Cyan       |   7 = LightGray      |   11 = LightCyan   |   15 = White

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return;
}

/*
*
* Function for going to a certain location on the command line
*
* @return void.
*
*/
void CControl::GotoXY(int _iX, int _iY)
{
	COORD point;
	point.X = _iX;
	point.Y = _iY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}


/*
*
* Function for clearing the command line screen
*
* @return void.
*
*/
void CControl::ClearScreen()
{
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);
}

/*
*
* KeyType Function for detecting arrow keys
*
* @return KeyType - returns an enum of the key name
*
*/
KeyType CControl::KeyDetection()
{
	int iKeyPress = _getch();
	if (iKeyPress != 0 && iKeyPress != 0xE0)
	{
		if (iKeyPress == 32)		//If SPACE is pressed
		{
			return SPACE;
		}
		else if (iKeyPress == 27)	//If ` is pressed
		{
			return EXIT;
		}
		else if (iKeyPress == 'r' || iKeyPress == 'R')
		{
			return ROTATE;
		}
	}
	else
	{
		// Arrow Key Codes.
		// TF: Constant
		const int g_kiDownArrow = 80;
		const int g_kiUpArrow = 72;
		const int g_kiLeftArrow = 75;
		const int g_kiRightArrow = 77;

		int iCheckForArrowKey = _getch();
		switch (iCheckForArrowKey)
		{
		case g_kiUpArrow:
		{
			return UP;
			break;
		}
		case g_kiDownArrow:
		{
			return DOWN;
			break;
		}
		case g_kiLeftArrow:
		{
			return LEFT;
			break;
		}
		case g_kiRightArrow:
		{
			return RIGHT;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}