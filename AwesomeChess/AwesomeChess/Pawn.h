#pragma once

#include "Board.h"
#include "Piece.h"

class Pawn : public Piece
{
	Pawn(string pos, int color);
	virtual ~Pawn();
	virtual bool checkMove(string place);
};