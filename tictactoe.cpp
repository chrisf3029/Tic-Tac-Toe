//Christopher Fong
//p2
//tictactoe.cpp
#include <iostream>
#include "tictactoe.h"
#include "playboard.h"

using namespace std;

//constructor sets grid size to default size(3)
TicTacToe::TicTacToe()
{
	//reset values
	turn = 'X';
	xWins = 0;
	oWins = 0;
	ties = 0;
	grid = new char*[DEFAULT_SIZE];
	setGridSize(DEFAULT_SIZE);
}

//copy constructor
TicTacToe::TicTacToe(const TicTacToe& other)
{
	setGridSize(other.getGridSize());
	turn = other.getTurn();
	xWins = other.getXWins();
	oWins = other.getOWins();
	ties = other.getTies();

	if (grid)
	{
		for (int i = 0; i < gridSize; i++)
		{
			delete[] grid[i];
		}
		delete[] grid;
		grid = NULL;
	}

	grid = new char*[other.getGridSize()];

	for (int i = 0; i < other.getGridSize(); i++)
	{
		grid[i] = new char[other.getGridSize()];
	}

	for (int i = 0; i < other.getGridSize(); i++)
	{
		for (int o = 0; o < other.getGridSize(); o++)
		{
			grid[i][o] = other.getGrid(i, o);
		}
	}
}

//copy assignment operator
TicTacToe& TicTacToe::operator = (const TicTacToe& other)
{
	setGridSize(other.getGridSize());
	turn = other.getTurn();
	xWins = other.getXWins();
	oWins = other.getOWins();
	ties = other.getTies();

	if (grid)
	{
		for (int i = 0; i < gridSize; i++)
		{
			delete[] grid[i];
		}
		delete[] grid;
		grid = NULL;
	}

	grid = new char*[other.getGridSize()];

	for (int i = 0; i < other.getGridSize(); i++)
	{
		grid[i] = new char[other.getGridSize()];
	}

	for (int i = 0; i < other.getGridSize(); i++)
	{
		for (int o = 0; o < other.getGridSize(); o++)
		{
			grid[i][o] = other.getGrid(i, o);
		}
	}
	return *this;
}

//destructor
TicTacToe::~TicTacToe()
{
	if (grid)
	{
		for (int i = 0; i < gridSize; i++)
		{
			delete[] grid[i];
		}
		delete[] grid;
		grid = NULL;
	}
}

//sets the gid size to the passed integer
void TicTacToe::setGridSize(int size)
{
	gridSize = size;
	if (grid)
	{
		for (int i = 0; i < gridSize; i++)
		{
			delete [] grid[i];
		}
		delete [] grid;
		grid = NULL;
	}
	grid = new char*[size];
	
	//make 2D dynamic array
	for (int i = 0; i < size; i++)							
	{
		grid[i] = new char[size];
	}

	//set all spots of 2D array to blanks
	for (int i = 0; i < size; i++)							
	{
		for (int o = 0; o < size; o++)
		{
			grid[i][o] = ' ';
		}
	}
}

//checks if space in grid is filled or not
bool TicTacToe::isOpen(int row, int col)
{
	if (grid[row][col] == ' ')
		return true;
	else
		return false;
}

//returns which player's turn it is
char TicTacToe::getTurn() const							
{
	return turn;
}

//changes whose turn it is
void TicTacToe::switchTurns()								
{
	if (turn == 'X')
		turn = 'O';
	else
		turn = 'X';
}

//sets the grid space at row and col to the players mark(X or O)
void TicTacToe::setGridSpot(int row, int col)				
{
	grid[row][col] = turn;
}

//returns the size of the grid
int TicTacToe::getGridSize() const						
{
	return gridSize;
}

//displays the playboard
void TicTacToe::getGrid() const
{
	Playboard * game = new Playboard(gridSize);
	game->setGrid(grid);
	game->display();
	delete game;
}

//checks if the game grid is full with no more open spaces
bool TicTacToe::isFull()
{
	int blanks = 0;
	for (int i = 0; i < gridSize; i++)
	{
		for (int o = 0; o < gridSize; o++)
		{
			if (grid[i][o] == ' ')
				blanks++;
		}
	}

	if (blanks == 0)
		return true;
	else
		return false;
}

//check if the game is over
bool TicTacToe::isDone()
{
	bool win = false;

	for (int i = 0; i < gridSize; i++)
	{
		//checks row win
		for (int o = 0; o < gridSize; o++)
		{
			if (grid[i][o] == turn)
			{
				win = true;
			}
			else
			{
				win = false;
				break;
			}
		}

		if (win)
		{
			cout << turn << " wins!" << endl;
			if (turn == 'X')
				xWins++;
			else
				oWins++;
			return win;
		}

		//checks col win
		for (int o = 0; o < gridSize; o++)
		{
			if (grid[o][i] == turn)
				win = true;

			else
			{
				win = false;
				break;
			}
		}

		if (win)
		{
			cout << turn << " wins!" << endl;
			if (turn == 'X')
				xWins++;
			else
				oWins++;
			return win;
		}
	}

	//checks diagonal from top left to bottom right corner win
	for (int i = 0; i < gridSize; i++)
	{
		if (grid[i][i] == turn)
			win = true;
		else
		{
			win = false;
			break;
		}
	}

	if (win)
	{
		cout << turn << " wins!" << endl;
		if (turn == 'X')
			xWins++;
		else
			oWins++;
		return win;
	}

	//checks diagonal from bottom left to top right corner win
	for (int i = 0; i < gridSize; i++)
	{
		if (grid[i][gridSize - 1 - i] == turn)
			win = true;
		else
		{
			win = false;
			break;
		}
	}

	if (win)
	{
		cout << turn << " wins!" << endl;
		if (turn == 'X')
			xWins++;
		else
			oWins++;
		return win;
	}

	//checks if tie
	if (isFull())
	{
		cout << "\nNobody wins, it's a tie!" << endl;
		ties++;
		return true;
	}

	return false;
}

//displays the current score between both players
void TicTacToe::getScore() const
{
	cout << "\nScore Board" << endl;
	cout << "X Wins: " << xWins << endl;
	cout << "O Wins: " << oWins << endl;
	cout << "Ties  : " << ties << endl;
}

//returns char at grid[row][col]
char TicTacToe::getGrid(int row, int col) const
{
	return grid[row][col];
}

//returns X wins
int TicTacToe::getXWins() const
{
	return xWins;
}

//returns O wins
int TicTacToe::getOWins() const
{
	return oWins;
}

//returns ties
int TicTacToe::getTies() const
{
	return ties;
}
