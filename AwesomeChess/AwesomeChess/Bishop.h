#pragma once

#include "Board.h"
#include "Piece.h"

using std::string;

class Board;

class Bishop : public Piece
{
public:
	Bishop(Board* board, string pos, string type, int color);
	virtual ~Bishop();
	virtual bool checkMove(string place);
};