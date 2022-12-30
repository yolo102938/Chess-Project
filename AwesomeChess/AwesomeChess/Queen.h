#pragma once

#include "Board.h"
#include "Piece.h"

using std::string;

class Board;
class Piece;

class Queen : public Piece
{
public:
	Queen(Board* board, string pos, string type, int color);
	virtual ~Queen();
	virtual bool checkMove(string place);
};