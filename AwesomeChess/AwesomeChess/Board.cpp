#include "Board.h"
#include "inc.h"
#include <string>

Board::Board(string boardSetup)
{
	int stringPlace = 0;
	this->_BoardString = boardSetup; //setting the board's string to the given string
	this->_turnColor = 1; //setting the number for the current color's turn (1 - black  |  0 - white)

	//looping to create all of the piece objects according to the given string, and forming the _pieces array.
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			////Maybe replaceing this later with switch case
			////Creator functions for the pieces are comments until we create them

			if (boardSetup[stringPlace] == 'r')
			{
				_pieces[i][j] = new Rook(this, char(j + 97) + std::to_string(i+1), "rook", 0);
			}
			else if (boardSetup[stringPlace] == 'R')
			{
				_pieces[i][j] = new Rook(this,  char(j + 97)+ std::to_string(i+1), "rook", 1);
			}
			else if (boardSetup[stringPlace] == 'k')
			{
				_pieces[i][j] = new King(this, char(j + 97) + std::to_string(i+1), "king", 0);
			}
			else if (boardSetup[stringPlace] == 'K')
			{
				_pieces[i][j] = new King(this, char(j + 97) + std::to_string(i+1), "king", 1);
			}
			else if (boardSetup[stringPlace] == 'b')
			{
				_pieces[i][j] = new Bishop(this, char(j + 97) + std::to_string(i+1), "bishop", 0);
			}
			else if (boardSetup[stringPlace] == 'B')
			{
				_pieces[i][j] = new Bishop(this, char(j + 97) + std::to_string(i+1), "bishop", 1);
			}
			else if (boardSetup[stringPlace] == 'n')
			{
				_pieces[i][j] = new Knight(this, char(j + 97) + std::to_string(i+1), "knight", 0);
			}
			else if (boardSetup[stringPlace] == 'N')
			{
				_pieces[i][j] = new Knight(this, char(j + 97) + std::to_string(i+1), "knight", 1);
			}
			else if (boardSetup[stringPlace] == 'q')
			{
				_pieces[i][j] = new Queen(this, char(j + 97) + std::to_string(i+1), "queen", 0);
			}
			else if (boardSetup[stringPlace] == 'Q')
			{
				_pieces[i][j] = new Queen(this, char(j + 97) + std::to_string(i+1), "queen", 1);
			}
			else if (boardSetup[stringPlace] == 'p')
			{
				_pieces[i][j] = new Pawn(this, char(j + 97) + std::to_string(i+1), "pawn", 0);
			}
			else if (boardSetup[stringPlace] == 'P')
			{
				_pieces[i][j] = new Pawn(this, char(j + 97) + std::to_string(i+1), "pawn", 1);
			}
			else if (boardSetup[stringPlace] == '#')
			{
				_pieces[i][j] = nullptr;
			}
			else
			{
				_pieces[i][j] = nullptr;
			}
			stringPlace++;
		}
	}
}

Board::~Board()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			delete _pieces[i][j];
		}
	}
}

string Board::getBoardStr() const
{
	return this->_BoardString;
}

int Board::getTurn() const
{
	return this->_turnColor;
}

void Board::moveToNextTurn()
{
	if (this->_turnColor == 0)
	{
		this->_turnColor = 1;
	}
	else if (this->_turnColor == 1)
	{
		this->_turnColor = 0;
	}
}

int Board::checkMove(string begDest) 
{
	//parsing the string
	string begstr = "te";//just temp cus idk how it works in cpp
	begstr[0] = begDest[0];
	begstr[1] = begDest[1];

	int currX = Piece::getPositionNumber_X(begstr)-1;
	int currY = Piece::getPositionNumber_Y(begstr)-1;
	
	string deststr = "te";//just temp cus idk how it works in cpp
	deststr[0] = begDest[2];
	deststr[1] = begDest[3];

	int destx = Piece::getPositionNumber_X(deststr)-1;
	int desty = Piece::getPositionNumber_Y(deststr)-1;

	Piece* current = _pieces[currY][currX];
	Piece* dest = _pieces[desty][destx];
	//check if dest has same color as turn color
	if (dest != nullptr)
	{
		if (dest->getColor() == _turnColor) {
			return(3);
		}
	}
	if (current == nullptr)
	{
		return(7);
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
	if (checkCheck(_turnColor)) //if the moves checks the current player (illegal move),undo the move and return error code 4
	{
		current->setPosition(begstr);
		_pieces[currY][currX] = current;
		_pieces[desty][destx] = dest;
		return(4);
	}

	
	
	if (checkCheck(_turnColor)) //if the moves checks the other player,check for mate and return the right code.
	{
		
		if (checkMate(_turnColor)) 
		{
			return(8);
		}
		return(1);
	}
	return(0);//if nothing came up,return valid :D
}
bool Board::checkMate(int color)
{
	string forwardCheck;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_pieces[i][j] != nullptr && _pieces[i][j]->getColor() == color)
			{
				for (int k = 0; k < BOARD_SIZE; k++)
				{
					for (int p = 0; p < BOARD_SIZE; p++)
					{
						forwardCheck = (char)((char)k + 96);
						forwardCheck += (char)((char)p + 48);
						if (_pieces[i][j]->checkMove(forwardCheck))
						{
							return false;
						}
					}
				}
			}
		}
	}
	return true;
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
bool Board::isEmpty(int x, int y) {
	return(_pieces[y-1][x-1] == nullptr);
}