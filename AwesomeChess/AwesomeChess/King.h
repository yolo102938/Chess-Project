#pragma once

#include "Board.h"
#include "Piece.h"

class King : public Piece
{
	King(string pos, int color);
	virtual ~King();
	virtual bool checkMove(string place);
};