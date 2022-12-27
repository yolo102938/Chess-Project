#include "Pawn.h"
bool Pawn::checkMove(string place) {
	int tempPlaceX = this->getPositionNumber_X();
	int tempPlaceY = this->getPositionNumber_Y();
	int destx = Piece::getPositionNumber_X(place);
	int desty = Piece::getPositionNumber_Y(place);
	if (desty != tempPlaceY + 1) {//if its not the next row
		return(false);
	}
	if ( _b->isEmpty(desty, destx) && destx == tempPlaceX) {//if it tries to go forward
		return(true);
	}
	if (destx == tempPlaceX + 1&& !_b->isEmpty(desty, destx)) {//if it eats,color check will be in board class
		return(true);
	}
	if (destx == tempPlaceX - 1 && !_b->isEmpty(desty, destx)) {//if it eats,color check will be in board class
		return(true);
	}
	return false;
}