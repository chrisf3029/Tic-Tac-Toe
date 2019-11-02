//Christopher Fong
//p2
//tictactoe.h
#pragma once

const int DEFAULT_SIZE = 3;

class TicTacToe
{
public:
	//constructs a tic tac toe game with DEFAULT_SIZE dimensions
	TicTacToe();

	//copy constructor
	TicTacToe(const TicTacToe& other);

	//assignment operator
	TicTacToe& operator = (const TicTacToe& other);

	//destructor
	~TicTacToe();

	//sets grid size
	void setGridSize(int size);						

	//sets grid space with either x or o
	void setGridSpot(int row, int col);				

	//displays the game board
	void getGrid() const;									

	//switchs turn to the next player
	void switchTurns();								

	//displays the score board
	void getScore() const;

	//checks if space in grid is open
	bool isOpen(int row, int col);					

	//checks if grid is full of x's and o's
	bool isFull();									

	//checks if game over
	bool isDone();									

	//returns the size of the grid
	int getGridSize() const;

	//returns X wins
	int getXWins() const;

	//returns O wins
	int getOWins() const;

	//returns ties
	int getTies() const;

	//returns whose turn it is currently
	char getTurn() const;

	//returns value at grid[row][col]
	char getGrid(int row, int col) const;

private:
	//pointer of pointer of char grid to create a dynamic 2d array
	char** grid;

	//character of whose turn it is
	char turn;

	//size of the grid
	int gridSize;

	//x win counter
	int xWins;

	//o win counter
	int oWins;

	//tie counter
	int ties;		
};