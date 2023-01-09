#include "Bishop.h"

Bishop::Bishop(Board* board, string pos, string type, int color) : Piece(board, pos, type, color) {}

Bishop::~Bishop() {}

bool Bishop::checkMove(string place) 
{
	int tempPlaceX = this->getPositionNumber_X();
	int tempPlaceY = this->getPositionNumber_Y();
	int destx = Piece::getPositionNumber_X(place);
	int desty = Piece::getPositionNumber_Y(place);
	int movey = 0;
	int movex = 0;
	if (abs((desty - tempPlaceY)) != abs(destx - tempPlaceX) ) //if its not diagonal return false
	{
		return(false);
	}
	printf("%d %d", abs((desty - tempPlaceY)), abs(destx - tempPlaceX));
	if (desty - tempPlaceY > 0)
	{
		movey = 1;
	}
	else
	{
		movey = -1;
	}	
	if (destx - tempPlaceX > 0)
	{
		movex = 1;
	}
	else
	{
		movex = -1;
	}
	while (abs(destx - tempPlaceX) > 1)
	{
		tempPlaceX +=movex;
		tempPlaceY +=movey;
		if (!_b->isEmpty(tempPlaceX, tempPlaceY))
		{
			return(false);
		}
	}//no need to check both cus it has the same number of moves
	return(true);
}