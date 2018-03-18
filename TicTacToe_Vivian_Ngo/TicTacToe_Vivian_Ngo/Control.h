// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	: "Control.h"
// Description	: Declaration file for Control
//
//					Control Class contains all extra functions 
//					that are used to make the TicTacToe game 
//					look better and is not necessarilly 'game logic'.
//
//
// Author		: Vivian Ngo
// Mail			: vivian.ngo7572@mediadesign.school.nz
//

#pragma once

#ifndef __CONTROL_H__
#define __CONTROL_H__

#include <Windows.h>

class CControl
{
public:
	void Spc(char character, int size);		//Sets specified num spaces with specified character inputted
	void ClearScreen(int _iX, int _iY);		//Clears screen from the coordinate input onwards
	void GotoXY(int _iX, int _iY);			//Goes to the coordinates specified
	void SetColour(WORD colour);				//Sets the colour of text to whatever is specified after the function is called
	void PrintCharInColour(char piece, WORD colour);		//Prints a specified character in colour (hardcoded light yellow)

private:

};

#endif // _CONTROL_H__