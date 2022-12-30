#include "Pawn.h"

Pawn::Pawn(Board* board, string pos, string type, int color) : Piece(board, pos, type, color) {}

Pawn::~Pawn() {}

bool Pawn::checkMove(string place)
{
	int tempPlaceX = this->getPositionNumber_X();
	int tempPlaceY = this->getPositionNumber_Y();
	int destx = Piece::getPositionNumber_X(place);
	int desty = Piece::getPositionNumber_Y(place);
	int move = 1;
	if (_color == 1) {
		move = -1;
	}
	if (desty != tempPlaceY + move)//if its not the next row
	{
		return(false);
	}
	if (destx == tempPlaceX)//if it tries to go forward
	{
		return(true);
	}
	if (destx == tempPlaceX + 1&& !_b->isEmpty(destx, desty))//if it eats,color check will be in board class
	{
		return(true);
	}
	if (destx == tempPlaceX - 1 && !_b->isEmpty(destx, desty))//if it eats,color check will be in board class
	{
		return(true);
	}
	return false;
}