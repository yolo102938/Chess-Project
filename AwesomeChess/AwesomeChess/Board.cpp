#include "Board.h"

Board::Board(string boardSetup)
{
	int stringPlace = 0;
	this->_BoardString = boardSetup; //setting the board's string to the given string
	this->_turnColor = 0; //setting the number for the current color's turn (1 - black  |  0 - white)

	//looping to create all of the piece objects according to the given string, and forming the _pieces array.
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			////Maybe replaceing this later with switch case
			////Creator functions for the pieces are comments until we create them

			if (boardSetup[stringPlace] == 'r')
			{
				_pieces[i][j] = Rook(this, std::to_string(i) + std::to_string(j + 65), 1);
			}
			else if (boardSetup[stringPlace] == 'R')
			{
				_pieces[i][j] = Rook(this, std::to_string(i) + std::to_string(j + 65), 0);
			}
			else if (boardSetup[stringPlace] == 'k')
			{
				_pieces[i][j] = King(this, std::to_string(i) + std::to_string(j + 65), 1);
			}
			else if (boardSetup[stringPlace] == 'K')
			{
				_pieces[i][j] = King(this, std::to_string(i) + std::to_string(j + 65), 0);
			}
			else if (boardSetup[stringPlace] == 'b')
			{
				_pieces[i][j] = Bishop(this, std::to_string(i) + std::to_string(j + 65), 1);
			}
			else if (boardSetup[stringPlace] == 'B')
			{
				_pieces[i][j] = Bishop(this, std::to_string(i) + std::to_string(j + 65), 0);
			}
			else if (boardSetup[stringPlace] == 'n')
			{
				_pieces[i][j] = Knight(this, std::to_string(i) + std::to_string(j + 65), 1);
			}
			else if (boardSetup[stringPlace] == 'N')
			{
				_pieces[i][j] = Knight(this, std::to_string(i) + std::to_string(j + 65), 0);
			}
			else if (boardSetup[stringPlace] == 'q')
			{
				_pieces[i][j] = Queen(this, std::to_string(i) + std::to_string(j + 65), 1);
			}
			else if (boardSetup[stringPlace] == 'Q')
			{
				_pieces[i][j] = Queen(this, std::to_string(i) + std::to_string(j + 65), 0);
			}
			else if (boardSetup[stringPlace] == 'p')
			{
				_pieces[i][j] = Pawn(this, std::to_string(i) + std::to_string(j + 65),1);
			}
			else if (boardSetup[stringPlace] == 'P')
			{
				_pieces[i][j] = Pawn(this, std::to_string(i) + std::to_string(j + 65), 0);
			}
			else
			{
				_pieces[i][j] = nullptr;
			}
		}
	}
}
int Board::checkMove(string begDest) 
{
	//parsing the string
	string begstr = "te";//just temp cus idk how it works in cpp
	begstr[0] = begDest[0];
	begstr[1] = begDest[1];

	int currX = Piece::getPositionNumber_X(begstr);
	int currY = Piece::getPositionNumber_X(begstr);
	
	string deststr = "te";//just temp cus idk how it works in cpp
	deststr[0] = begDest[2];
	deststr[1] = begDest[3];

	int destx = Piece::getPositionNumber_X(deststr);
	int desty = Piece::getPositionNumber_Y(deststr);

	Piece* current = _pieces[currY][currX];
	Piece* dest = _pieces[desty][destx];
	//code 2 checker
	if (dest == nullptr) {
		return(2);
	}
	if (current->getColor() != _turnColor) {
		return(2);
	}
	//code 3 checker
	if (dest != nullptr) {
		if (dest->getColor() == _turnColor) {
			return(3);
		}
	}
	//code 6 checker
	if (!current->checkMove(deststr)) {
		return(6);
	}
	return(0);//if nothing came up,return valid :D
}