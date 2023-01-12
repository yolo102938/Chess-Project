#include "Queen.h"

Queen::Queen(Board* board, string pos, string type, int color) : Piece(board, pos, type, color) {}

Queen::~Queen() {}

bool Queen::checkMove(string place) 
{
	int tempPlaceX = this->getPositionNumber_X();
	int tempPlaceY = this->getPositionNumber_Y();
	int destx = Piece::getPositionNumber_X(place);
	int desty = Piece::getPositionNumber_Y(place);
	int movey = 0;
	int movex = 0;
	//up and down chckers
	if (destx == tempPlaceX) //if the path is the same col
	{
		desty < tempPlaceY ? tempPlaceY-- : tempPlaceY++;
		for (tempPlaceY; desty < tempPlaceY ? desty < tempPlaceY : desty > tempPlaceY; desty < tempPlaceY ? tempPlaceY-- : tempPlaceY++) //check there is something that is blocking, up or down depends on the dst
		{
			if (!_b->isEmpty(tempPlaceX, tempPlaceY)) {
				return(false);
			}
		}
		return(true);
	}
	if (desty == tempPlaceY) //if the path is the same row
	{
		destx < tempPlaceX ? tempPlaceX-- : tempPlaceX++;
		for (tempPlaceX; desty < tempPlaceX ? destx < tempPlaceX : destx > tempPlaceX; destx < tempPlaceX ? tempPlaceX-- : tempPlaceX++) //check there is something that is blocking, left or right depends on the dst
		{
			if (!_b->isEmpty(tempPlaceX, tempPlaceY))
			{
				return(false);
			}
		}
		return(true);
	}
	//if not up and down, check diagonal. if not, return false
	int move = 0;

	if (abs((desty - tempPlaceY)) != abs(destx - tempPlaceX) ) //if its not diagonal return false
	{
		return(false);
	}
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
		tempPlaceX += movex;
		tempPlaceY += movey;
		if (!_b->isEmpty(tempPlaceX, tempPlaceY))
		{
			return(false);
		}
	}
	
}