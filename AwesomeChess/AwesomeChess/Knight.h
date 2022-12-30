#pragma once

#include "Board.h"
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(Board* board, string pos, string type, int color) : Piece(board, pos, type, color) {};
	virtual ~Knight();
	virtual bool checkMove(string place);
};