#pragma once
#include "Board.h"
#include "Piece.h"

class King : public Piece
{
	King(Board* board, string pos, string type, int color);
	virtual ~King();
	virtual bool checkMove(string place);
};