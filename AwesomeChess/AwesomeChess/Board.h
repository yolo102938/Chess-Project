#pragma once
#include <string> 
#include <iostream>
#include "Piece.h"

using std::string;

class Piece;

#define BOARD_SIZE 8

class Board
{
protected:
	string _BoardString;
	int _turnColor;
	Piece* _pieces[BOARD_SIZE][BOARD_SIZE];

public:
	Board(string boardSetup);
	~Board();
	string getBoardStr() const;
	int getTurn() const;
	void moveToNextTurn();
	bool isEmpty(int x, int y);
	bool checkCheck(int color) const;//funny name lolz
	bool checkMate(int color);//even funnier
	string findKing(int color) const;
	int checkMove(string begDest);
	
};