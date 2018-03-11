//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2017 Media Design School
//
// File Name : main.cpp
// Description : Main implementation file.
// Author : Vivian Ngo
// Mail : vivian.ngo7572@mediadesignschool.com
//

// Library Includes
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <cTime>
#include <iomanip>
#include <cstdlib>

// Local Includes
#include "game.h"

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	
	while (true)
	{
		CGame play;
		play.MainMenu();

		switch (play.GetMenuType()) 
		{
		case PlayGameChoose:
		{
			play.PlayChoose();
			break;
		}
		case PlayGameRandom:
		{
			play.PlayRandom();
			break;
		}
		case DebugMode:
		{
			play.PlayDebug();
			break;
		}
		}
	}
}