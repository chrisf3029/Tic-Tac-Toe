//Christopher Fong
//p2
//playboard.h
#pragma once

class Playboard
{
	public:
		//constructor that creates a playboard with the size of the passed int
		Playboard(int size);

		//copy constructor
		Playboard(const Playboard& other);

		//assignmnent operator
		Playboard& operator = (const Playboard& other);

		//destortor
		~Playboard();

		//sets the grid array to the tic tac toe grid array
		void setGrid(char** g);

		//displays the playboard
		void display() const;

		//returns the value of gridSize
		int getGridSize() const;

		//returns char** grid
		char getGrid(int row, int col) const;

	private:
		//dimension of the playboard
		int gridSize;

		//2d dynamic array that holds all the played characters and at which spot
		char** grid;

};