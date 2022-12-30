#pragma once
#include <string> 
#include <iostream>
#include "Piece.h"
#include "inc.h"
using std::string;

class Piece;

#define BOARD_SIZE 8
#include "inc.h"
class Board
{
private:
	string _BoardString;
	int _turnColor;
	Piece* _pieces[BOARD_SIZE][BOARD_SIZE];

public:
	Board(string boardSetup);
	~Board();
	bool isEmpty(int x, int y);
	bool checkCheck(int color);//funny name lolz
	bool checkMate(int color);//even funnier
	string findKing(int color);
	int checkMove(string begDest);
	
};