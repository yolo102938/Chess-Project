#pragma once
#include "Piece.h"
#include "Board.h"



class Bishop : public Piece
{
public:
	Bishop(Board* board, string pos, string type, int color);
	virtual ~Bishop();
	virtual bool checkMove(string place);
};