#pragma once

#include "Board.h"
#include "Piece.h"

class Rook : public Piece
{
	Rook(string pos, int color);
	virtual ~Rook();
	virtual bool checkMove(string place);
};