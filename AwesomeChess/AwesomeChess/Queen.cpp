#include "Queen.h"

Queen::Queen(Board* board, string pos, string type, int color) : Piece(board, pos, type, color) {}

Queen::~Queen() {}

bool Queen::checkMove(string place) 
{
	int tempPlaceX = this->getPositionNumber_X();
	int tempPlaceY = this->getPositionNumber_Y();
	int destx = Piece::getPositionNumber_X(place);
	int desty = Piece::getPositionNumber_Y(place);

	//up and down chckers
	if (destx == tempPlaceX) //if the path is the same col
	{
		for (tempPlaceY; tempPlaceY < desty; desty > tempPlaceY ? tempPlaceY++ : tempPlaceY--) //check there is something that is blocking, up or down depends on the dst
		{
			if (!_b->isEmpty(tempPlaceX, tempPlaceY)) {
				return(false);
			}
		}
		return(true);
	}
	else if (desty == tempPlaceY) //if the path is the same row
	{
		for (tempPlaceX; tempPlaceX < destx; destx > tempPlaceX ? tempPlaceX++ : tempPlaceX--) //check there is something that is blocking, left or right depends on the dst
		{
			if (!_b->isEmpty(tempPlaceX, tempPlaceY)) {
				return(false);
			}
		}
		return(true);
	}

	tempPlaceX = this->getPositionNumber_X();
	tempPlaceY = this->getPositionNumber_Y();
	//if not up and down, check diagonal. if not, return false
	int move = 0;
	if (abs((desty - tempPlaceY) / (destx - tempPlaceX)) == 1)
	{
		if (desty - tempPlaceY > 0) {
			move = -1;
		}
		else {
			move = 1;
		}
		while (destx != tempPlaceX)//no need to check both cus it has the same number of moves
		{
			if (!_b->isEmpty(tempPlaceX, tempPlaceY)) {
				return(false);
			}
			tempPlaceX = +move;
			tempPlaceY = +move;
		}
		return true;
	}
	return(false);
	
}