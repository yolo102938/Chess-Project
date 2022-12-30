#include "Bishop.h"

Bishop::Bishop(Board* board, string pos, string type, int color) : Piece(board, pos, type, color) {}

Bishop::~Bishop() {}

bool Bishop::checkMove(string place) 
{
	int tempPlaceX = this->getPositionNumber_X();
	int tempPlaceY = this->getPositionNumber_Y();
	int destx = Piece::getPositionNumber_X(place);
	int desty = Piece::getPositionNumber_Y(place);
	int move = 0;

	if (abs((desty - tempPlaceY) / (destx - tempPlaceX)) != 1) //if its not diagonal return false
	{
		return(false);
	}
	if (desty - tempPlaceY > 0)
	{
		move = -1;
	}
	else
	{
		move = 1;
	}
	while(destx!=tempPlaceX)//no need to check both cus it has the same number of moves
	{
		if (!_b->isEmpty(tempPlaceX, tempPlaceY))
		{
			return(false);
		}
		tempPlaceX=+move;
		tempPlaceY=+move;
	}
	return(true);
}