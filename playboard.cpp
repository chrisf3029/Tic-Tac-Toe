//Christopher Fong
//p2
//playboard.cpp
#include <iostream>
#include "playboard.h"

using namespace std;

//constructor that creates a playboard with the size of the passed int
Playboard::Playboard(int size)
{
	gridSize = size;
}

//copy constructor
Playboard::Playboard(const Playboard& other)
{
	gridSize = other.gridSize;
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
Playboard& Playboard::operator = (const Playboard& other)
{
	gridSize = other.getGridSize();
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
			grid[i][o] = other.getGrid(i,o);
		}
	}
	return *this;
}

//destructor
Playboard::~Playboard()
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

//sets grid to the TicTacToe grid
void Playboard::setGrid(char** g)
{/*
	if (grid)
	{
		for (int i = 0; i < gridSize; i++)
		{
			delete[] grid[i];
		}
		delete[] grid;
		grid = NULL;
	}*/
	grid = new char*[gridSize];
	for (int i = 0; i < gridSize; i++)
	{
		grid[i] = new char[gridSize];
		for (int o = 0; o < gridSize; o++)
		{
			grid[i][o] = g[i][o];
		}
	}
}

//displays the entire game board
void Playboard::display() const
{
	cout << "  ";

	for (int i = 0; i < gridSize; i++)
	{
		cout << i << "   ";
	}

	cout << endl;

	for (int i = 0; i < gridSize; i++)
	{
		cout << i << " ";

		for (int o = 0; o < gridSize; o++)
		{
			cout << grid[i][o];
			if (o < gridSize - 1)
				cout << " | ";
		}

		cout << endl << " ";
		if (i < gridSize - 1)
		{
			for (int p = 0; p < gridSize * 4; p++)
			{
				cout << '_';
			}
		}

		cout << endl;
	}
}

//returns gridSize value
int Playboard::getGridSize() const
{
	return gridSize;
}

//returns char at row, col
char Playboard::getGrid(int row, int col) const
{
	return grid[row][col];
}
