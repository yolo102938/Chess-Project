#pragma once

#include "Board.h"
#include "Piece.h"

class Knight : public Piece
{
	Knight(string pos, int color);
	virtual ~Knight();
	virtual bool checkMove(string place);
};