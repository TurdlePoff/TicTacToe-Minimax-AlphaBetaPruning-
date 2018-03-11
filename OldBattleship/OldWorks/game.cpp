//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2017 Media Design School
//
// File Name : game.cpp
// Description : game implementation file
// Author : Vivian Ngo
// Mail : vivian.ngo7572@mediadesignschool.com
//

// Library Includes
#include <string>
#include <conio.h>
#include <iostream>

// Local Includes

// This Include
#include "game.h"
#include "board.h"

using namespace std;

CControl control;

/**
*
* TF: Constructor
*
* Game functions
*   - GamePlay:  MainMenu, Title, PlayChoose, PlayRandom, MenuNavigation
*	- Technical: Spc, ClearScreen, GotoXY, KeyDetection, GetMenuType, SetColour, SetMenuType
*
* @author : Vivian Ngo
*
*/
CGame::CGame()
{
	
}

/**
*
* TF: Destructor
*
* @author : Vivian Ngo
*
*/
CGame::~CGame() {}


/**
*
* Function for creating Main menu
*
* @author : Vivian Ngo
*
* @return void.
*
*/
void CGame::MainMenu()
{
	ClearScreen();
	Title();
	SetColour(3);
	GotoXY(8, 23); cout << "UP and DOWN - move     SPACEBAR - select     ` to exit at anytime" << endl;
	SetColour(7);
	while (true)
	{
		switch (GetMenuType())
		{
		case Start:
		{
			GotoXY(25, 6);
			SetColour(3);   cout << " __________________________" << endl;
			Spc(' ', 25);   cout << "|                          |" << endl;
			Spc(' ', 25);   cout << "|         S T A R T        |" << endl;
			Spc(' ', 25);   cout << "|__________________________|" << endl << endl; SetColour(7);
			Spc(' ', 25);   cout << " __________________________" << endl;
			Spc(' ', 25);   cout << "|                          |" << endl;
			Spc(' ', 25);   cout << "|          E X I T         |" << endl;
			Spc(' ', 25);   cout << "|__________________________|" << endl << endl;
			Spc(' ', 25);   cout << " __________________________" << endl;
			Spc(' ', 25);   cout << "|                          |" << endl;
			Spc(' ', 25);   cout << "|         D E B U G        |" << endl;
			Spc(' ', 25);   cout << "|__________________________|" << endl << endl; SetColour(7);
			MenuNavigation();
			break;
		}
		case Exit:
		{
			GotoXY(25, 6);  cout << " __________________________" << endl;
			Spc(' ', 25);   cout << "|                          |" << endl;
			Spc(' ', 25);   cout << "|         S T A R T        |" << endl;
			Spc(' ', 25);   cout << "|__________________________|" << endl << endl; SetColour(3);
			Spc(' ', 25);   cout << " __________________________" << endl;
			Spc(' ', 25);   cout << "|                          |" << endl;
			Spc(' ', 25);   cout << "|          E X I T         |" << endl;
			Spc(' ', 25);   cout << "|__________________________|" << endl << endl; SetColour(7);
			Spc(' ', 25);   cout << " __________________________" << endl;
			Spc(' ', 25);   cout << "|                          |" << endl;
			Spc(' ', 25);   cout << "|         D E B U G        |" << endl;
			Spc(' ', 25);   cout << "|__________________________|" << endl << endl; SetColour(7);
			MenuNavigation();
			break;
		}
		case Debug:
		{
			GotoXY(25, 6);  cout << " __________________________" << endl;
			Spc(' ', 25);   cout << "|                          |" << endl;
			Spc(' ', 25);   cout << "|         S T A R T        |" << endl;
			Spc(' ', 25);   cout << "|__________________________|" << endl << endl;
			Spc(' ', 25);   cout << " __________________________" << endl;
			Spc(' ', 25);   cout << "|                          |" << endl;
			Spc(' ', 25);   cout << "|          E X I T         |" << endl;
			Spc(' ', 25);   cout << "|__________________________|" << endl << endl; SetColour(3);
			Spc(' ', 25);   cout << " __________________________" << endl;
			Spc(' ', 25);   cout << "|                          |" << endl;
			Spc(' ', 25);   cout << "|         D E B U G        |" << endl;
			Spc(' ', 25);   cout << "|__________________________|" << endl << endl; SetColour(7);
			MenuNavigation();
			break;
		}
		case GameChoose:
		{
			GotoXY(25, 6);
			SetColour(3);   cout << " _____________________________" << endl;
			Spc(' ', 25);   cout << "|                             |" << endl;
			Spc(' ', 25);   cout << "|  Choose your own positions  |" << endl;
			Spc(' ', 25);   cout << "|_____________________________|" << endl << endl; SetColour(7);
			Spc(' ', 25);   cout << " _____________________________" << endl;
			Spc(' ', 25);   cout << "|                             |" << endl;
			Spc(' ', 25);   cout << "| Randomly generate positions |" << endl;
			Spc(' ', 25);   cout << "|_____________________________|" << endl << endl;
			Spc(' ', 53);   cout << endl;
			Spc(' ', 53);   cout << endl;
			Spc(' ', 53);   cout << endl;
			Spc(' ', 53);   cout << endl << endl; SetColour(7);
			MenuNavigation();
			break;
		}
		case GameRandom:
		{
			GotoXY(25, 6);
			SetColour(7);   cout << " _____________________________" << endl;
			Spc(' ', 25);   cout << "|                             |" << endl;
			Spc(' ', 25);   cout << "|  Choose your own positions  |" << endl;
			Spc(' ', 25);   cout << "|_____________________________|" << endl << endl; SetColour(3);
			Spc(' ', 25);   cout << " _____________________________" << endl;
			Spc(' ', 25);   cout << "|                             |" << endl;
			Spc(' ', 25);   cout << "| Randomly generate positions |" << endl;
			Spc(' ', 25);   cout << "|_____________________________|" << endl << endl; SetColour(7);
			Spc(' ', 53);   cout << endl;
			Spc(' ', 53);   cout << endl;
			Spc(' ', 53);   cout << endl;
			Spc(' ', 53);   cout << endl << endl; SetColour(7);
			MenuNavigation();
			break;
		}
		}
		if (GetMenuType() >= 6)
			break;
	}
}

/*
*
* Function that prints the title of the game (while clearing the screen before hand)
*
* @return void
*
*/
void CGame::Title()
{
	ClearScreen();
	SetColour(7);
	GotoXY(0, 1);
	Spc(' ', 15); cout << "___  ____ ___ ___ _    ____ ____ _  _ _ ___  ____ " << endl;
	Spc(' ', 15); cout << "|__] |__|  |   |  |    |___ [__  |__| | |__] [__  " << endl;
	Spc(' ', 15); cout << "|__] |  |  |   |  |___ |___ ___] |  | | |    ___]" << endl;
}

/*
*
* Function that prints ending screen
*
* @return void
*
*/
void CGame::EndingScreenLose()
{
	ClearScreen();
	Title();
	SetColour(12);

	GotoXY(23, 25); cout << "_    ____ ____ ____ ____   /" << endl;
	GotoXY(23, 26); cout << "|    |  | [__  |___ |__/  /" << endl;
	GotoXY(23, 27); cout << "|___ |__| ___] |___ |  \ ." << endl;
	GotoXY(23, 30); cout << "Press any key to continue....." << endl;
	SetColour(7);
	_getch();
}


/*
*
* Function that prints ending screen
*
* @return void
*
*/
void CGame::EndingScreen()
{
	ClearScreen();
	Title();
	SetColour(7);

	GotoXY(23, 25); cout << "_ _ _ _ _  _ _  _ ____ ____    /" << endl;
	GotoXY(23, 26); cout << "| | | | |\\ | |\\ | |___ |__/  / " << endl;
	GotoXY(23, 27); cout << "|_|_| | | \\| | \\| |___ |  \\ .  " << endl;
	GotoXY(23, 30); cout << "Press any key to continue....." << endl;
	_getch();
}
/*
*
* Function that proceeds with gameplay by allowing
* the player to choose their ship positions
*
* @return void
*
*/
void CGame::PlayChoose()
{
	Title();
	GotoXY(15, 28); cout << "Set your battleships using the arrow keys";
	GotoXY(15, 29); cout << "Press space to set your ship";
	GotoXY(15, 29); cout << "Press R or r to rotate";

	CBoard cpu(SetUpRandomBoard, false);
	cpu.BoatPlacement(false, control);
	CBoard player(SetUpChooseBoard, true);
	player.BoatPlacement(false, control);
	while (!player.CheckWin() && !cpu.CheckWin())
	{
		player.GamePlay();
		cpu.AIplay();
	}
	if (player.CheckWin() == true)
	{
		EndingScreen();
	}
	else
	{
		EndingScreenLose();
	}
}

/*
*
* Function that proceeds with gameplay by allowing
* the player to randomize their starting ship positions
*
* @return void
*
*/
void CGame::PlayRandom()
{
	Title();
	CBoard cpu(SetUpRandomBoard, false);
	cpu.BoatPlacement(false, control);
	CBoard player(SetUpRandomBoard, true);
	player.BoatPlacement(false, control);
	while (!player.CheckWin() && !cpu.CheckWin())
	{
		player.GamePlay();
		cpu.AIplay();
	}
	if (player.CheckWin() == true)
	{
		EndingScreen();
	}
	else
	{
		EndingScreenLose();
	}
}


/*
*
* Function that proceeds with gameplay by allowing
* the player to randomize their starting ship positions
*
* @return void
*
*/
void CGame::PlayDebug()
{
	Title();
	CBoard cpu(SetUpRandomBoard, false);
	cpu.BoatPlacement(true, control);
	CBoard player(SetUpRandomBoard, true);
	player.BoatPlacement(true, control);
	while (!player.CheckWin() && !cpu.CheckWin())
	{
		player.GamePlay();
		cpu.AIplay();
	}
	if (player.CheckWin() == true)
	{
		EndingScreen();
	}
	else
	{
		EndingScreenLose();
	}
}