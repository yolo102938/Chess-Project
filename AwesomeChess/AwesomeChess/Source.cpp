/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include "Board.h"
#include <string>
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::string;


void main()
{
	srand(time_t(NULL));

	
	Pipe p;
	Board* b = new Board("rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0");
	//for easy debugging, delete l8r
	STARTUPINFO info = { sizeof(info) };
	PROCESS_INFORMATION processInfo;
	CreateProcess("chessGraphics.exe", NULL, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo);
	//WaitForSingleObject(processInfo.hProcess, INFINITE);
	Sleep(2000);
	//until here
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, (b->getBoardStr()).c_str()); // just example...
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		string res = std::to_string(b->checkMove(msgFromGraphics));
		// YOUR CODE
		strcpy_s(msgToGraphics, res.c_str()); // msgToGraphics should contain the result of the operation

		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);  

		if (res == "1" || res == "0")
		{
			b->moveToNextTurn();
		}

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}
	CloseHandle(processInfo.hProcess);
	CloseHandle(processInfo.hThread);
	p.close();
}