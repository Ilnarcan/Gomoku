
#include "BoardView.h"
#include <iostream>
#include <cassert>
#include <iomanip>

using namespace std;

BoardView::BoardView(Board *b) {
	board = b;
}

void BoardView::show() {

	int sizeOfField = board->getSize();

	cout << endl;

	for (int i = 0; i < sizeOfField; i++) {
		for (int j = 0; j < sizeOfField; j++) {
			if (board->getcell(i, j) == 0)
				cout << setw(5) << "+";
			else if (board->getcell(i, j) == 1)
				cout << setw(5) << "X";
			else
				cout << setw(5) << "O";
		}
		cout << endl << endl;
	}
}

void BoardView::startGame() {

	int x, y;
	int turn = 1;

	while (board->isWin() == board->nextTurn) {
		
		cout << turn << " player's turn: ";
		cin >> x >> y;

		if (board->makeMove(x, y, (Board::sign)turn) == false) {
			cout << "ERROR! You can't move here!\n" << endl;
			turn++;
		}
		else 
			show();

		turn %= 2;
		turn++;
	}

	Board::event res = board->isWin();
	
	if (res == 0)
		cout << "!	DRAW	!";
	else
		cout << "!	" << res  << " win	!" << endl;

}