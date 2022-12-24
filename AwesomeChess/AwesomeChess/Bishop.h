#pragma once

#include "Board.h"
#include "Piece.h"

class Bishop : public Piece
{
	Bishop(string pos, int color);
	virtual ~Bishop();
	virtual bool checkMove(string place);
};