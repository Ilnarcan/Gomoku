// Gomoku.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "Board.h"
#include "BoardView.h"


int main()
{

	Board b;
	BoardView v(&b);

	v.startGame();


    return 0;
}

