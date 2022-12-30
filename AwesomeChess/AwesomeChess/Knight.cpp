#include "Knight.h"

Knight::Knight(Board* board, string pos, string type, int color) : Piece(board, pos, type, color) 
{
}

Knight::~Knight() {}
bool Knight::checkMove(string place) {
	
	int tempPlaceX = this->getPositionNumber_X();
	int tempPlaceY = this->getPositionNumber_Y();
	int destx = Piece::getPositionNumber_X(place);
	int desty = Piece::getPositionNumber_Y(place);
	return(abs(desty - tempPlaceY) + abs(destx - tempPlaceX) == 3);
}