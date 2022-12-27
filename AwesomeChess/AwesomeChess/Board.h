#pragma once
#include <iostream>
#include "Piece.h"

using std::string;

class Piece;

#define BOARD_SIZE 8

class Board
{
private:
	string BoardString;
	int turnColor;
	Piece* pieces[BOARD_SIZE][BOARD_SIZE];

public:
	Board(string boardSetup);
	~Board();
	bool isEmpty(int x, int y);
};