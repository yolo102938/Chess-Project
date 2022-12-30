#pragma once

#include "Piece.h"
#include "Board.h"

class King : public Piece
{
public:
	King(Board* board, string pos, string type, int color);
	virtual ~King();
	virtual bool checkMove(string place);
};