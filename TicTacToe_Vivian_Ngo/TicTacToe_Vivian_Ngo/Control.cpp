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
* @author: Vivian Ngo
* @date: 07/03/18
* @parameter: character - the character the user wishes to repeat
* @parameter: size - the amount of repeats the user wants to make
*/
void CControl::Spc(char character, int size)
{
	std::cout << std::setfill(character) << std::setw(size) << character;
}

/***********************
* ClearScreen: Function for clearing the command line screen
* @author: Vivian Ngo
* @date: 07/03/18
* @parameter: _iX - X coordinate of where to start clearing the screen
* @parameter: _iY - Y coordinate of where to start clearing the screen
***********************/
void CControl::ClearScreen(int _iX, int _iY)
{
	COORD coordScreen = { (short) _iX, (short) _iY };
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
* @author: Vivian Ngo
* @date: 07/03/18
* @parameter: _iX - X coordinate of where to place cursor
* @parameter: _iY - Y coordinate of where to place cursor
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
* @author: Vivian Ngo
* @date: 07/03/18
* @parameter: color - number of the colour you would like to set the text
*     Colours:
*     0 = Black      |   4 = Red            |   8 = DarkGray     |   12 = LightRed
*     1 = Blue       |   5 = Magenta        |   9 = LightBlue    |   13 = LightMagenta
*     2 = Green      |   6 = Yellow         |   10 = LightGreen  |   14 = LightYellow
*     3 = Cyan       |   7 = LightGray      |   11 = LightCyan   |   15 = White
***********************/
void CControl::SetColour(WORD colour)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
	return;
}

/***********************
* PrintInColour: Function for printing a single character in the specified colour
* @author: Vivian Ngo
* @date: 07/03/18
* @parameter: piece - the character piece to change colour and print
* @parameter: piece - the character piece to change colour and print
***********************/
void CControl::PrintCharInColour(char piece, WORD colour)
{
	SetColour(colour);
	std::cout << piece;
	SetColour(7);
}