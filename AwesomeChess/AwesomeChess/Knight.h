#pragma once
#include "Piece.h"
#include "Board.h"

class Knight : public Piece
{
public:
	Knight(Board* board, string pos, string type, int color);
	virtual ~Knight();
	virtual bool checkMove(string place);
};