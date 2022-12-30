#include "King.h"

King::King(Board* board, string pos, string type, int color) : Piece(board, pos, type, color) {}

King::~King() {}

bool King::checkMove(string place)
{
	int tempPlaceX = this->getPositionNumber_X();
	int tempPlaceY = this->getPositionNumber_Y();
	int destx = Piece::getPositionNumber_X(place);
	int desty = Piece::getPositionNumber_Y(place);

	return(abs(tempPlaceX - destx) <= 1 && abs(tempPlaceY - desty) <= 1);//all we need :D
}