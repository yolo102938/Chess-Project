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
				_pieces[i][j] = 0;//Rook(string position, 1 (black color))
			}
			else if (boardSetup[stringPlace] == 'R')
			{
				_pieces[i][j] = 0;//Rook(string position, 0 (white color));
			}
			else if (boardSetup[stringPlace] == 'k')
			{
				_pieces[i][j] = 0;//King(string position, 1 (black color));
			}
			else if (boardSetup[stringPlace] == 'K')
			{
				_pieces[i][j] = 0;//King(string position, 0 (white color));
			}
			else if (boardSetup[stringPlace] == 'b')
			{
				_pieces[i][j] = 0;//Bishop(string position, 1 (black color));
			}
			else if (boardSetup[stringPlace] == 'B')
			{
				_pieces[i][j] = 0;//Bishop(string position, 0 (white color));
			}
			else if (boardSetup[stringPlace] == 'n')
			{
				_pieces[i][j] = 0;//Knight(string position, 1 (black color));
			}
			else if (boardSetup[stringPlace] == 'N')
			{
				_pieces[i][j] = 0;//Knight(string position, 0 (white color));
			}
			else if (boardSetup[stringPlace] == 'q')
			{
				_pieces[i][j] = 0;//Queen(string position, 1 (black color));
			}
			else if (boardSetup[stringPlace] == 'Q')
			{
				_pieces[i][j] = 0;//Queen(string position, 0 (white color));
			}
			else if (boardSetup[stringPlace] == 'p')
			{
				_pieces[i][j] = 0;//Pawn(string position, 1 (black color));
			}
			else if (boardSetup[stringPlace] == 'P')
			{
				_pieces[i][j] = 0;//Pawn(string position, 0 (white color));
			}
			else
			{
				//(empty tool creator?);
			}
		}
	}
}