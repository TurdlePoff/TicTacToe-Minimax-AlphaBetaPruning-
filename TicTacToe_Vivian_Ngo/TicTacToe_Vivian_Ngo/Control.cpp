// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	: "Control.cpp"
// Description	: Implementation file for Control
//
//					Control Class contains all extra functions 
//					that are used to make the TicTacToe game 
//					look better and is not necessarilly 'game logic'.
//
//
// Author		: Vivian Ngo
// Mail			: vivian.ngo7572@mediadesign.school.nz
//
#include "Control.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>

/**
* Function for creating a specified number of repeats of 
*	whatever character the user specifies
* @parameter: character - the character the user wishes to repeat
* @parameter: size - the amount of repeats the user wants to make
*/
void CControl::Spc(char character, int size)
{
	std::cout << std::setfill(character) << std::setw(size) << character;
}

/***********************
* ClearScreen: Function for clearing the command line screen
* @parameter: _iX - X coordinate of where to start clearing the screen
* @parameter: _iY - Y coordinate of where to start clearing the screen
***********************/
void CControl::ClearScreen(int _iX, int _iY)
{
	COORD coordScreen = { _iX, _iY };
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


/***********************
* GotoXY: Function for going to a certain location on the command line
***********************/
void CControl::GotoXY(int _iX, int _iY)
{
	COORD point;
	point.X = _iX;
	point.Y = _iY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

/***********************
* SetColour: Function for setting colour of text
* @parameter: color - number of the colour you would like to set the text
*     Colours:
*     0 = Black      |   4 = Red            |   8 = DarkGray     |   12 = LightRed
*     1 = Blue       |   5 = Magenta        |   9 = LightBlue    |   13 = LightMagenta
*     2 = Green      |   6 = Yellow         |   10 = LightGreen  |   14 = LightYellow
*     3 = Cyan       |   7 = LightGray      |   11 = LightCyan   |   15 = White
***********************/
void CControl::SetColour(WORD color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return;
}

/***********************
* SetColour: Function for setting colour of text
* @parameter: color - number of the colour you would like to set the text
* @parameter: piece - the character piece to change colour and print
***********************/
void CControl::PrintInColour(char piece)
{
	SetColour(14);
	std::cout << piece;
	SetColour(7);
}

/***********************
* KeyType Function for detecting arrow keys
* @return KeyType - returns an enum of the key name
***********************/
KeyType CControl::KeyDetection()
{

	int iKeyPress = _getch();
	if (iKeyPress != 0 && iKeyPress != 0xE0)
	{
		if (iKeyPress == 32)		//If SPACE is pressed
		{
			return SPACE;
		}
		//else if (iKeyPress == 27)	//If ` is pressed
		//{
		//	return EXIT;
		//}
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