#pragma once

#include "Board.h"
#include "Piece.h"

class Bishop : public Piece
{
	Bishop(Board* board, string pos, string type, int color);
	virtual ~Bishop();
	virtual bool checkMove(string place);
};