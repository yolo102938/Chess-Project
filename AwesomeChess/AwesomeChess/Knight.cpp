#include "Knight.h"

Knight::Knight(Board* board, string pos, string type, int color) : Piece(board, pos, type, color) {}

Knight::~Knight() {}

bool Knight::checkMove(string place)
{
	return true; ///////TEMP!!
}