#include "Board.h"
#include "Rook.h"
#include "King.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "Bishop.h"
#include "Piece.h"

Board::Board(string boardSetup)
{
	int stringPlace = 0;
	this->_BoardString = boardSetup; //setting the board's string to the given string
	this->_turnColor = 0; //setting the number for the current color's turn (1 - black  |  0 - white)

	//looping to create all of the piece objects according to the given string, and forming the _pieces array.
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			////Maybe replaceing this later with switch case
			////Creator functions for the pieces are comments until we create them

			if (boardSetup[stringPlace] == 'r')
			{
				_pieces[i][j] = new Rook(this, std::to_string(i) + std::to_string(j + 65), "rook", 1);
			}
			else if (boardSetup[stringPlace] == 'R')
			{
				_pieces[i][j] = new Rook(this, std::to_string(i) + std::to_string(j + 65), "rook", 0);
			}
			else if (boardSetup[stringPlace] == 'k')
			{
				_pieces[i][j] = new King(this, std::to_string(i) + std::to_string(j + 65), "king", 1);
			}
			else if (boardSetup[stringPlace] == 'K')
			{
				_pieces[i][j] = new King(this, std::to_string(i) + std::to_string(j + 65), "king", 0);
			}
			else if (boardSetup[stringPlace] == 'b')
			{
				_pieces[i][j] = new Bishop(this, std::to_string(i) + std::to_string(j + 65), "bishop", 1);
			}
			else if (boardSetup[stringPlace] == 'B')
			{
				_pieces[i][j] = new Bishop(this, std::to_string(i) + std::to_string(j + 65), "bishop", 0);
			}
			else if (boardSetup[stringPlace] == 'n')
			{
				_pieces[i][j] = new Knight(this, std::to_string(i) + std::to_string(j + 65), "knight",1);
			}
			else if (boardSetup[stringPlace] == 'N')
			{
				_pieces[i][j] = new Knight(this, std::to_string(i) + std::to_string(j + 65), "knight", 0);
			}
			else if (boardSetup[stringPlace] == 'q')
			{
				_pieces[i][j] = new Queen(this, std::to_string(i) + std::to_string(j + 65), "queen", 1);
			}
			else if (boardSetup[stringPlace] == 'Q')
			{
				_pieces[i][j] = new Queen(this, std::to_string(i) + std::to_string(j + 65), "queen", 0);
			}
			else if (boardSetup[stringPlace] == 'p')
			{
				_pieces[i][j] = new Pawn(this, std::to_string(i) + std::to_string(j + 65), "pawn",1);
			}
			else if (boardSetup[stringPlace] == 'P')
			{
				_pieces[i][j] = new Pawn(this, std::to_string(i) + std::to_string(j + 65), "pawn", 0);
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
	//check if dest has same color as turn color
	if (dest != nullptr) {
		if (dest->getColor() == _turnColor) {
			return(3);
		}
	}
	//check if play piece is same color as turn color
	if (current->getColor() != _turnColor) {
		return(2);
	}
	//code 6 checker
	if (!current->checkMove(deststr)) {
		return(6);
	}
	//after all the normal checkers, move the piece and check for check/mate on both sides"
	//if there is one, the wrongfully deleted piece is saved in the dest pointer luckily so no need for temps
	
	_pieces[currY][currX] = nullptr;
	_pieces[desty][destx] = current;
	current->setPosition(deststr);
	if (checkCheck(abs(_turnColor))) //if the moves checks the current player (illegal move),undo the move and return error code 4
	{
		current->setPosition(begstr);
		_pieces[currY][currX] = current;
		_pieces[desty][destx] = dest;
		return(4);
	}

	_turnColor = abs(_turnColor - 1);//change turn color
	
	if (checkCheck(_turnColor)) //if the moves checks the other player,check for mate and return the right code.
	{
		
		if (checkMate(_turnColor)) 
		{
			return(8);
		}
		return(1);
	}
	_turnColor = abs(_turnColor - 1);
	return(0);//if nothing came up,return valid :D
}
bool Board::checkMate(int color) {
	string king = findKing(color);
	int kingX = Piece::getPositionNumber_X(king);
	int kingY = Piece::getPositionNumber_X(king);
	Piece* temp = nullptr;
	Piece* kingPiece = _pieces[kingX][kingY];
	bool ret = true;
	for (int y = -1; y < 2; y++) {
		for (int x = -1; x < 2; x++) {
			 if (_pieces[y][x]->getColor() == color) {}
			 else 
			 {
				 temp = _pieces[y][x];
				 _pieces[kingX][kingY] = nullptr;
				 _pieces[y][x] = kingPiece;
				 ret = checkCheck(color);
				  _pieces[y][x] = temp ;
				 _pieces[kingX][kingY] = kingPiece;
			 }
		}
	}
	return(ret);
}
bool Board::checkCheck(int color) 
{
	string king = findKing(color);
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_pieces[i][j] != nullptr) 
			{
				if (_pieces[i][j]->getColor() == abs(color-1) && _pieces[i][j]->checkMove(king) )
				{
					return(true);
				}
			}
		}
	}
	return(false);
}
string Board::findKing(int color) {
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++) 
		{
			if(_pieces[i][j]!=nullptr){
				if (_pieces[i][j]->getColor() == color && _pieces[i][j]->getType()=="king") {
					return(_pieces[i][j]->getPositionString());
			}
			}
		}
	}
}