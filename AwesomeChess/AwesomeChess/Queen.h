#pragma once

#include "Board.h"
#include "Piece.h"

class Queen : public Piece
{
	Queen(string pos, int color);
	virtual ~Queen();
	virtual bool checkMove(string place);
};