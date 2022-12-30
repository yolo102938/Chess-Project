#pragma once

#include "Board.h"
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Board* board, string pos, string type, int color);
	virtual ~Pawn();
	virtual bool checkMove(string place);
};