//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: "TicTacToe.h"
// Description	: Implementation file for CTicTacToe
// Author		: Vivian Ngo
// Mail			: vivian.ngo7572@mediadesign.school.nz
//

#include "TicTacToe.h"
#include <conio.h>
#include <iostream>
#include <vector>
//#include "vld.h"
using namespace std;
/***********************
* TicTacToe Constructor
* @author: Vivian Ngo
* @date: 14/03/18
************************/
CTicTacToe::CTicTacToe()
{
	//Initialize global variables
	board = new CBoard();
	count = 0;
	p1Piece = 'X';
	p2Piece = 'O';
	p1Points = 0;
	p2Points = 0;
	gameEnded = false;
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL)
	{				 //  position	 size
		RECT rect;
		int width, height;
		if (GetWindowRect(hwnd, &rect))
		{
			width = rect.right - rect.left;
			height = rect.bottom - rect.top;
		}
		MoveWindow(hwnd, width/2, (height/2)-150, 700, 700, TRUE);  //Set console position to center
	}
}

/***********************
* TicTacToe Destructor
* @author: Vivian Ngo
* @date: 07/03/18
************************/
CTicTacToe::~CTicTacToe()
{
	delete board;
	board = 0;
}

/***********************
* Title: Prints the Tic Tac Toe title text
* @author: Vivian Ngo
* @date: 14/03/18
************************/
void CTicTacToe::Title()
{
	cout << "  _____ ___  ___ _____ ___   ___ _____  ___  ____ " << endl;
	cout << "    |    |  |      |  |___| |      |   |   | [__ " << endl;
	cout << "    |   _|_ |___   |  |   | |___   |   |___| [___ " << endl;
}

/***********************
* StartUp: Starts up the game by introducing the player to a main menu screen
* This main menu screen will allow the player to choose to either:
*	- Play a one player game against a computer AI
*		- This has an easy and hard setting
*	- Play a two player game against another human next to them
*	- Customize their board pieces
*	- Exit the game
* @author: Vivian Ngo
* @date: 07/03/18
************************/
void CTicTacToe::StartUp()
{
	while (!gameEnded)
	{
		system("CLS");
		Title(); //Print title that will last for the entire duration of the game until exited

		CControl::ClearScreen(0, 4);
		CControl::SetColour(6);
		cout << " =================================================" << endl;
		cout << " ||                By Vivian Ngo                ||" << endl;
		cout << " =================================================" << endl;
		cout << " ||              Player 1 piece: " << p1Piece << "              ||" << endl;
		cout << " ||              Player 2 piece: " << p2Piece << "              ||" << endl;
		cout << " =================================================" << endl << endl;	
		CControl::SetColour(7);
		cout << "     Main menu options: " << endl << endl;
		cout << "         1) Player vs Computer" << endl;
		cout << "         2) Player vs Player" << endl;
		cout << "         3) Customize" << endl;
		cout << "         4) Exit" << endl << endl; 
		cout << "     Please select an option: ";
		
		//Select an option from the title screen
		switch (ChooseOption("     Pick a valid option (1, 2, 3, 4): ", 4)) 
		{
			case '1':	//Player vs Computer
			{
				CControl::ClearScreen(0, 4);
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "             Player vs Computer Selected." << endl;
				cout << " =================================================" << endl << endl;
				CControl::SetColour(7);

				// Prompt player if they would like to play easy or hard mode
				cout << "     Would you like to play Easy or Hard Mode? " << endl << endl;
				cout << "         1) Easy" << endl;
				cout << "         2) Hard" << endl << endl;
				cout << "     Select an option: ";

				char easyOrHard = ChooseOption("     Pick a valid option (1, 2): ", 2);
				
				// Inform player of their difficulty choice
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "               " << ((easyOrHard == '1') ? "Easy mode" : "Hard mode") << " selected." << endl;
				cout << " =================================================" << endl << endl;
				CControl::SetColour(7);

				//Prompt user whether they would like to be player 1 or player 2
				cout << " Would you like to be player 1 (" << p1Piece 
									  << ") or player 2 (" << p2Piece << ")?: ";
				char p1Or2 = ChooseOption("     Pick a valid option (1, 2): ", 2);
				
				CControl::ClearScreen(0, 4);

				// Inform player of their turn choice
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "    " << ((easyOrHard == '1') ? "[Easy]" : "[Hard]") 
							   << " You are player " << ((p1Or2 == '1') ? '1' : '2') 
							   << " with the '" << ((p1Or2 == '1') ? p1Piece : p2Piece) << "' piece." << endl;
				cout << " =================================================" << endl << endl;
				CControl::SetColour(7);

				if (easyOrHard == '1')
				{
					//Starts up a new game match in easy mode
					PlayGame(p1Or2, true, false);
				}
				else
				{
					//Starts up a new game match in hard mode
					PlayGame(p1Or2, false, false);
				}
				break;
			}
			case '2':	//Player vs Player
			{
				CControl::ClearScreen(0, 4);
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "           Player vs Player Selected." << endl;
				cout << " =================================================" << endl << endl;
				CControl::SetColour(7);

				PlayGame('1', false, true);	//Start up Player vs Player game
				break;
			}
			case '3':
			{
				CControl::ClearScreen(0, 4);
				Customize();		//Customize player pieces
				break;
			}
			case '4':
			{
				gameEnded = true;	//Set the endGame value to true
			}
		}
		if (gameEnded)		//If game has ended, break while loop and close application
		{
			break;
		}
	}
}

/***********************
* ChooseOption: Allows player to choose an option and prompts a question if a wrong input is entered
* @author: Vivian Ngo
* @date: 14/03/18
* @parameter: question - string containing the question to ask player if a wrong input is entered
* @parameter: numOptions - the number of options to select from
* @return: valid option inputted by player
************************/
char CTicTacToe::ChooseOption(std::string question, int numOptions)
{
	//Receive player input
	char option = _getch();
	//Recieve numbers depending on how many options are given
	while (option < 49 || option >(49 + numOptions - 1))
	{
		cout << endl;
		cout << question;
		option = _getch();
	}
	cout << option << endl << endl;
	return option;
}

/***********************
* CheckGameOver: Check if game is over and print scores if so
* @author: Vivian Ngo
* @date: 14/03/18
* @parameter: player - The character of the current player's piece
* @parameter: isPlayerTurn - Checks if it is player 1's turn
* @parameter: isPvP - Checks if the game match is PvP or PvC
* @parameter: p1Or2 - Checks if the current player is player 1 or player 2
* @return: gameOver - If true, the game is over. Else, the game continues.
************************/
bool CTicTacToe::CheckGameOver(char player, bool isPlayerTurn, bool isPvP, char p1Or2)
{
	bool gameOver = false;
	board->ResetWinBoard();

	// If there is a winner, print scores
	if (board->CheckForWinner(player)) 
	{
		cout << endl;
		CControl::ClearScreen(0, 7);

		board->PrintBoard();
		//Print scores in colour
		CControl::SetColour(6);
		PrintScores(false, isPvP, isPlayerTurn, p1Or2);
		CControl::SetColour(7);

		gameOver = true;
	}
	else if (board->CheckForDraw())
	{
		// If there is a draw, print scores
		cout << endl;
		CControl::ClearScreen(0, 7);

		board->PrintBoard();
		//Print scores in colour
		CControl::SetColour(6);
		PrintScores(true, isPvP, isPlayerTurn, p1Or2);
		CControl::SetColour(7);

		gameOver = true;
	}

	return gameOver;
}

/***********************
* PrintScores: Prints the scores of the current game session
* @author: Vivian Ngo
* @date: 14/03/18
* @parameter: isDraw - Checks if game is a draw
* @parameter: isPvP - Checks if the game is a PvP (Player vs Player) or PvC (Player vs Computer) game
* @parameter: isPlayerTurn - Checks if the current player is player 1
* @parameter: p1Or2 - Checks if the player is player 1 or player 2 (PvC scores)
************************/
void CTicTacToe::PrintScores(bool isDraw, bool isPvP, bool isPlayerTurn, char p1Or2)
{
	if (isPvP) //Player vs Player game
	{
		if (isDraw) //If the game is a draw, print the current score
		{
			cout << " =================================================" << endl;
			cout << "                      DRAW!!" << endl;
			cout << endl << "     Player 1 Points: " << p1Points
				<< "      Player 2 Points: " << p2Points << endl;
			cout << " =================================================" << endl << endl;
		}
		else //If the game is won, add points to the person who one and print the score
		{
			if (isPlayerTurn)
				++p1Points;
			else
				++p2Points;

			cout << " =================================================" << endl;
			cout << "          PLAYER " << ((isPlayerTurn) ? '1' : '2') << ": " << ((isPlayerTurn) ? p1Piece : p2Piece)
				<< " HAS WON THE GAME!   " << endl << endl;
			cout << "     Player 1 Points: " << p1Points
				<< "      Player 2 Points: " << p2Points << endl;
			cout << " =================================================" << endl << endl;
		}
	}
	else //Player vs Computer game
	{
		if (isDraw)  //If the game is a draw, print the current score
		{
			cout << " =================================================" << endl;
			cout << "                      DRAW!!" << endl;
			cout << endl << "     Player Points: " << ((p1Or2 == '1') ? p1Points : p2Points)
				<< "      Computer Points: " << ((p1Or2 == '1') ? p2Points : p1Points) << endl;
			cout << " =================================================" << endl << endl;
		}
		else  //If the game is won, add points to the person who one and print the score
		{
			if (isPlayerTurn) //Add to player points then print score
			{
				if (p1Or2 == '1')
					++p1Points;
				else
					++p2Points;

				cout << " =================================================" << endl;
				cout << "          PLAYER: " << ((p1Or2 == '1') ? p1Piece : p2Piece)
					<< " HAS WON THE GAME!   " << endl << endl;
				cout << "     Player Points: " << ((p1Or2 == '1') ? p1Points : p2Points)
					<< "      Computer Points: " << ((p1Or2 == '1') ? p2Points : p1Points) << endl;
				cout << " =================================================" << endl << endl;
			}
			else  //Add to computer points then print score
			{
				if (p1Or2 != '1')
					++p1Points;
				else
					++p2Points;

				cout << " =================================================" << endl;
				cout << "          COMPUTER: " << ((p1Or2 != '1') ? p1Piece : p2Piece)
					<< " HAS WON THE GAME!   " << endl << endl;
				cout << "     Player Points: " << ((p1Or2 == '1') ? p1Points : p2Points)
					<< "      Computer Points: " << ((p1Or2 == '1') ? p2Points : p1Points) << endl;
				cout << " =================================================" << endl << endl;
			}
		}
	}
}

/***********************
* PlayGame: Starts up and plays the game depending on the parameters given
*					(p1Or2 and easyMode parameters are used for player vs computer games
*					 these are defaulted to '1' [p1Or2] and true [easyMode] when calling pvp mode)
* @author: Vivian Ngo
* @date: 14/03/18
* @parameter: p1Or2 - (player vs computer) input from player for whether they want to play as player 1 or 2
* @parameter: easyMode - (player vs computer) input from player for whether they want to play easy or hard mode
* @parameter: isPvP - boolean variable that determines if the game is player vs player or player vs computer
************************/
void CTicTacToe::PlayGame(char p1Or2, bool easyMode, bool isPvP)
{
	//Reset player points when starting a completely new game session
	p1Points = 0;
	p2Points = 0;
	while (true) //While loop used to reset values if players want to play again
	{
		bool isPlayerTurn = ((p1Or2 == '1') ? true : false);	//Set true if player chose to go first
		char currentPlayer = p1Piece;							//Set the current player's piece to p1Piece 

		//Allow computer to choose a random position if they play first on hard mode
		bool compIsP2 = ((p1Or2 == '1' && !easyMode) ? true : false); 

		//Reset boards when starting new game
		board->ResetBoard();
		board->ResetWinBoard();

		while (true)			//While loop for a single game session
		{
			CControl::ClearScreen(0, 7);
			board->PrintBoard(); //Print current board status
			cout << "     Moves Checked: " << count << endl;
			count = 0;
			//Reset row and col variables
			row = 0;			//row to be picked
			col = 0;			//column to be picked

			if (isPvP || isPlayerTurn)	//If it is a PvP game OR If it is the players turn, allow player to set their position
			{
				//If it is PvP, print out whether is is player 1 or player 2's turn to play
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "                 Player" << ((isPvP) ? ((isPlayerTurn) ? " 1: " : " 2: ") : ": ") << currentPlayer << "'s turn" << endl;
				cout << " =================================================" << endl << endl;
				CControl::SetColour(7);

				while (true)
				{
					//Allow player to pick a row and column
					cout << endl << "     Pick a row: ";
					row = ChooseOption("     Pick a valid row (1, 2, 3): ", 3);

					cout << "     Pick a column: ";
					col = ChooseOption("     Pick a valid column (1, 2, 3): ", 3);

					//If position is valid, end loop
					if (board->CheckPiece(row - 49, col - 49, ' '))
					{
						row -= 49;
						col -= 49;

						break;
					}
					//Otherwise, repeat while loop
					cout << "     Please pick a valid position: " << endl;
				}
			}	
			else	//If players turn, allow player to set their position
			{
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "                Computer: " << currentPlayer << "'s turn" << endl;
				cout << " =================================================" << endl << endl;
				CControl::SetColour(7);

				if (easyMode ) //If easyMode is selected, randomly generate comp positions
				{
					while (true)
					{
						//Easy random computer position generator
						int compRow = (rand() % 3 + 1);
						row = '0' + compRow;

						int compCol = (rand() % 3 + 1);
						col = '0' + compCol;

						//If the position is valid, proceed with sleep
						if (board->CheckPiece(row - 49, col - 49, ' ')) 
						{
							row -= 49;
							col -= 49;

							break;
						}
					}
				}
				else    //If Hard mode is selected
				{
					//If the computer starts 2nd and a player piece is placed in the middle of the board
					if (compIsP2 && board->CheckPiece(1, 1, (p1Or2 == '1' ? p1Piece : p2Piece)))
					{
						//Choose one of the corner pieces
						int compCorner = (rand() % 4 + 1);
						switch (compCorner)
						{
							case 1:		//Top left corner
							{
								row = ('0' + 1) - 49;
								col = ('0' + 1) - 49;
								break;
							}
							case 2:		//Top right corner
							{
								row = ('0' + 1) - 49;
								col = ('0' + 3) - 49;
								break;
							}
							case 3:		//Bottom left corner
							{
								row = ('0' + 3) - 49;
								col = ('0' + 1) - 49;
								break;
							}
							case 4:		//Bottom right corner
							{
								row = ('0' + 3) - 49;
								col = ('0' + 3) - 49;
								break;
							}
						}
					}
					else //Call minimax algorithm
					{
						//Generate Minimax AI for hardmode
						int depth = 0;
						MiniMax(currentPlayer, p1Or2, depth);
					}
					compIsP2 = false;
				}
				
				//Make computer delay their move
				cout << "     Computer " << currentPlayer << " is making their move: ";

				//Call sleep so it seems like the computer is thinking
				Sleep(500);
				cout << ". ";
				Sleep(500);
				cout << ". ";
				Sleep(500);

				//Prevents user input while program is sleeping
				while (_kbhit()) 
					_getch();

				cout << endl << endl;
			}
			//Set player piece on board
			board->Insert(currentPlayer, row, col);

			//Check if there is a winner. If there is, break while loop and end round
			if (CheckGameOver(currentPlayer, isPlayerTurn, isPvP, p1Or2))
			{
				break;
			}

			//Switch players after a turn is up
			if (currentPlayer == p1Piece)
			{
				currentPlayer = p2Piece;
			}
			else
			{
				currentPlayer = p1Piece;
			}
			isPlayerTurn = !isPlayerTurn;

		}
		//Ask players if they want to play another round
		cout << "     Play again?" << endl << endl;
		cout << "         1) Yes" << endl;
		cout << "         2) No" << endl << endl;
		cout << "     Please select an option: ";
		//Allows player to choose whether to play again or not
		if (ChooseOption("     Pick a valid option (1, 2): ", 2) == '1')
		{
			CControl::ClearScreen(0, 4);

			CControl::SetColour(6);
			cout << " =================================================" << endl;
			cout << "    " << ((easyMode == true) ? "[Easy]" : "[Hard]") 
				 << " You are player " << ((p1Or2 == '1') ? '1' : '2') 
				 << " with the '" << p1Piece << "' piece." << endl;
			cout << " =================================================" << endl << endl;
			CControl::SetColour(7);
		}
		else
		{
			//Return to main menu by breaking the while loop
			break;
		}
	}
}

/***********************
* Customize: Allows player to customize the TicTacTie game pieces
* Player can change either:
*	- Player1's game piece
*	- Player2's game piece 
*	- Swap Player 1 and Player 2's pieces with each other
* @author: Vivian Ngo
* @date: 07/03/18
************************/
void CTicTacToe::Customize()
{
	bool custExit = false;
	while (true)
	{
		//Print customization menu
		CControl::SetColour(6);
		cout << " =================================================" << endl;
		cout << " ||                 CUSTOMIZATION               ||" << endl;
		cout << " =================================================" << endl;
		cout << " ||              Player 1 piece: " << p1Piece << "              ||" << endl;
		cout << " ||              Player 2 piece: " << p2Piece << "              ||" << endl;
		cout << " =================================================" << endl << endl;
		CControl::SetColour(7);
		cout << "     Customization options:" << endl << endl;
		cout << "         1) Change Player 1 piece" << endl;
		cout << "         2) Change Player 2 piece" << endl;
		cout << "         3) Switch pieces" << endl;
		cout << "         4) Return to main menu" << endl << endl;
		cout << "     Please select an option: ";

		switch (ChooseOption("     Pick a valid option (1, 2, 3, 4): ", 4))
		{
			case '1': //Allow player to change p1 piece
			{
				cout << "     Choose a new Player 1 piece: ";
				p1Piece = ChangePiece();
				CControl::ClearScreen(0, 4);
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "               Player 1 piece changed." << endl;
				cout << " =================================================" << endl;
				CControl::SetColour(7);
				break;
			}
			case '2': //Allow player to change p2 piece
			{
				cout << "     Choose a new Player 2 piece: ";
				p2Piece = ChangePiece();
				CControl::ClearScreen(0, 4);
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "               Player 2 piece changed." << endl;
				cout << " =================================================" << endl;
				CControl::SetColour(7);
				break;
			}
			case '3': //Allow player to swap p1 and p2 pieces
			{
				CControl::ClearScreen(0, 4);
				CControl::SetColour(6);
				cout << " =================================================" << endl;
				cout << "               P1 & P2 pieces Switched." << endl;
				cout << " =================================================" << endl;
				CControl::SetColour(7);

				//Swap the pieces around
				char tempPiece = p1Piece;
				p1Piece = p2Piece;
				p2Piece = tempPiece;

				break;
			}
			case '4':
			{
				//Return to main menu
				custExit = true;
				break;
			}
		}

		if (custExit) //Exit customization menu if custExit is true
		{
			break;
		}
	}
}

/***********************
* ChooseCharacter: Takes the user's input and checks if it is a valid board game piece
* @return: newPiece - The valid new piece the user inputed
* @author: Vivian Ngo
* @date: 14/03/18
************************/
char CTicTacToe::ChangePiece()
{
	char newPiece = 'n';
	while (true)
	{
		newPiece = _getch();
		cout << newPiece << endl;
		//If the new piece is not equals to player two's piece or a space character, return.
		if (newPiece != p1Piece && newPiece != p2Piece && newPiece != ' ')
		{
			break;
		}
		//prompt statement if input is invalid
		else
		{
			cout << "     Please choose a different character: ";
		}
	}
	return newPiece;
}

/***********************
* Minimax: Minimax function with pruning used to determine the AI for the computer
* @author: Vivian Ngo
* @date: 26/03/18
* @parameter: currentPlayer - The currentplayer
* @parameter: p1Or2 - char variable determining whether the player or computer starts first
* @parameter: depth - depth variable determining how far down the tree the recursion is
************************/
void CTicTacToe::MiniMax(char currentPlayer, char p1Or2, int& depth)
{
	//Initialize alphabeta variables where alpha is -1000 and beta is 1000
	ABPruning ab = { -1000, 1000 };

	//Get the best move depending on whether the computer goes 1st or 2nd
	BestMove move;

	if (p1Or2 == '1')
	{
		//If player 1 started first
		move = GetBestMove(currentPlayer, '2', depth, ab);
	}
	else
	{
		//If computer started first
		move = GetBestMove(currentPlayer, '1', depth, ab);
	}

	//Set the best move retrieved to the row and col value
	row = ('0' + move.row) - 48;
	col = ('0' + move.col) - 48;
}

/***********************
* MiniMaxScore: Determines the minimax score for the AI algorithm
* @author: Vivian Ngo
* @date: 26/03/18
* @parameter: currentPlayer - The current player
* @parameter: p1Or2 - char variable determining whether the player or computer starts first
* @parameter: depth - depth variable determining how far down the tree the recursion is
* @parameter: ab - alpha beta value used to determine whether 
*				   certain branches of a node can be pruned
* @return: BestMove - Returns four types of best scores
*						- Max wins = 10 - depth
*						- Min wins = depth - 10
*						- Move determined through alpha beta pruning
*						- Best move determined from accumulated vector - moves[bestMove];
************************/
BestMove CTicTacToe::GetBestMove(char currentPlayer, char p1Or2, int& depth, ABPruning ab)
{
	
	//Base case returning a value if the game is won or a draw
	if ((p1Or2 == '1' && board->CheckForWinner(p2Piece)) 
	 || (p1Or2 == '2' && board->CheckForWinner(p1Piece)))
	{
		return BestMove(10 - depth); //If best max move
	}
	else if (p1Or2 == '1' && board->CheckForWinner(p1Piece) 
		  || p1Or2 == '2' && board->CheckForWinner(p2Piece))
	{
		return BestMove(depth - 10); //If best min move
	}
	else if (board->CheckForDraw())
	{
		return BestMove(0);			 //If best move is a draw
	}

	std::vector<BestMove> moves;	//Initialize vector to store all the best moves found

	for (unsigned int i = 0; i < 3; ++i)
	{
		for (unsigned int j = 0; j < 3; ++j)
		{
			if (board->CheckPiece(i, j, ' '))		//Check if board pos is empty
			{
				//Initialize BestMove to store the best row, column and score found
				BestMove move;
				move.row = i;
				move.col = j;

				board->Insert(currentPlayer, i, j); //Insert a default value
				++depth;							//Increase depth when getting a new best value

				if (currentPlayer == p1Piece)		//Get best move score
				{
					move.score = GetBestMove(p2Piece, p1Or2, depth, ab).score; //Run best move for player 2
				}
				else
				{
					move.score = GetBestMove(p1Piece, p1Or2, depth, ab).score; //Run best move for player 1
				}
				++count;
				//If player is max
				if ((p1Or2 == '1' && currentPlayer == p2Piece) 
				 || (p1Or2 == '2' && currentPlayer == p1Piece))
				{
					if (ab.alpha <= move.score) //If alpha is smaller or equal to the best score
					{
						ab.alpha = move.score;	//Set the best score to alpha
					}
				}
				else //If player is min
				{
					if (ab.beta >= move.score)	//If beta is bigger or equal to the best score
					{
						ab.beta = move.score;	//Set best score to beta
					}

					//ONLY IN BETA 
					if (ab.beta <= ab.alpha)	//If beta is less than or equal to alpha
					{
						--depth;				//Go back up the branch
						board->Remove(i, j);	//Remove the temporary variable
						return move;			//Prune the branch by returning the best score immediately
					}
				}
				//Once a branch's best move has been found
				--depth;				//Go back up the branch
				moves.push_back(move);	//Add best move to vector of moves
				board->Remove(i, j);	//Remove the temporary variable
			}
		}
	}

	//Determine the best moves for each player

	//Variable determining the array value of the 
	//best move within the best moves vector
	int bestMove = 0; 

	//If player is Max
	if ((p1Or2 == '1' && currentPlayer == p2Piece) 
	 || (p1Or2 == '2' && currentPlayer == p1Piece))
	{
		//Determine the best max value if the currentPlayer is the computer
		int bestScore = -1000;
		for (unsigned int i = 0; i < moves.size(); ++i)
		{
			//If the score being checked is higher than the current best score
			if (moves[i].score >= bestScore) 
			{
				//Set it as the best move and best score for max
				bestMove = i;
				bestScore = moves[i].score;
			}
		}
	}
	else //If player is Min
	{
		//Determine the best min value if the currentPlayer is the temporary player
		int bestScore = 1000;
		for (unsigned int i = 0; i < moves.size(); ++i)
		{
			//If the score being checked is lesser than the current best score
			if (moves[i].score <= bestScore)
			{
				//Set it as the best move and best score for min
				bestMove = i;
				bestScore = moves[i].score;
			}
		}
	}

	//Return the best score
	return moves[bestMove];
}