#include "Rook.h"

Rook::Rook(Board* board, string pos, string type, int color) : Piece(board, pos, type, color) {}

Rook::~Rook() {}

bool Rook::checkMove(string place)
{
	int tempPlaceX = this->getPositionNumber_X();
	int tempPlaceY = this->getPositionNumber_Y();
	int destx = Piece::getPositionNumber_X(place);
	int desty = Piece::getPositionNumber_Y(place);

	if ( destx == tempPlaceX) //if the path is the same col
	{
		for (tempPlaceY; tempPlaceY < desty; desty > tempPlaceY ? tempPlaceY++ : tempPlaceY--) //check there is something that is blocking, up or down depends on the dst
		{
			if (!_b->isEmpty(tempPlaceX, tempPlaceY)) {
				return(false);
			}
		}
		return(true);
	}
	if (desty == tempPlaceY) //if the path is the same row
	{
		for (tempPlaceX; tempPlaceX < destx; destx > tempPlaceX ? tempPlaceX++ : tempPlaceX--) //check there is something that is blocking, left or right depends on the dst
		{
			if (!_b->isEmpty(tempPlaceX, tempPlaceY))
			{
				return(false);
			}
		}
		return(true);
	}
	return(false);
}