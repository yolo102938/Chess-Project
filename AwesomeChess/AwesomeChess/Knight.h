#pragma once

#include "Board.h"
#include "Piece.h"

class Board;
class Piece;

using std::string;

class Knight : public Piece
{
public:
	Knight(Board* board, string pos, string type, int color);
	virtual ~Knight();
	virtual bool checkMove(string place);
};