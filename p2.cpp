//Christopher Fong
//p2
//p2.cpp
#include <iostream>
#include "tictactoe.h"

using namespace std;

int main()
{
	int r;
	int c;
	bool playAgain;
	char again;

	//clear console 25 lines down
	for (int i = 0; i < 25; i++)
		cout << endl;

	//welcome message
	cout << "Welcome to TicTacToe!\n\n" << endl;						
	
	//initialize game
	TicTacToe game;														
	
	//do while loop that repeats if the game isn't over or if the user decides to play another game
	do
	{
		//show playboard
		game.getGrid();													
		
		cout << "\n" << game.getTurn() << ", it is your turn." << endl;

		//do while loop that repeats if an invalid grid spot is inputed
		do
		{
			cout << "Which row? ";
			cin >> r;

			//checks if row is in bounds of grid
			while (r > game.getGridSize() - 1 || r < 0)
			{
				cout << "\nPlease enter a valid row: ";
				cin >> r;
			}

			cout << "Which colomn? ";
			cin >> c;

			//checks if col is in bounds of grid
			while (c > game.getGridSize() - 1 || c < 0)
			{
				cout << "\n\nPlease enter a valid colomn: ";
				cin >> c;
			}

			//checks if the chosen grid spot is blank
			if (!game.isOpen(r, c))
				cout << "\nThis space is already taken, please enter a new location." << endl << endl;
		} while (!game.isOpen(r, c));

		//sets the grid spot to X or O dependng on whose turn
		game.setGridSpot(r, c);

		//checks if game over
		if (game.isDone())
		{
			game.getGrid();
			cout << endl;
			game.getScore();
			cout << endl;

			game.switchTurns();

			//player decides whether or not to play again
			cout << "Do you want to play again(y or n)? ";
			cin >> again;
			if (again != 'y' && again != 'Y')
				playAgain = false;
			else
			{
				playAgain = true;
				game.setGridSize(DEFAULT_SIZE);
			}
		}

		//if game is not over repeat loop and change to next player turn
		else
		{
			playAgain = true;
			game.switchTurns();
		}

	} while (playAgain);

	//good-bye message
	cout << "\nThanks for playing Tic Tac Toe!\n\n" << endl;

	return 0;
}



