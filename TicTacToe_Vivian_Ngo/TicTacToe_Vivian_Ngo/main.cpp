//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	: "main.cpp"
// Description	: main.cpp for TicTacToe
// Author		: Vivian Ngo
// Mail			: vivian.ngo7572@mediadesign.school.nz
//
#include "TicTacToe.h"

#include <iostream>
#include <conio.h>
#include <time.h>
//#include "vld.h"

using namespace std;

int main()
{
	srand((unsigned)time(NULL));

	CTicTacToe game;
	game.StartUp();
	return(0);
	//int depth = 0;
	//game.MiniMax('X', '1', depth);
	//game.MiniMax('O', '2', depth);
	cout << game.count;
	_getch();
}