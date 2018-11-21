
#ifndef _BOARD_VIEW_H_
#define _BOARD_VIEW_H_

#include "Board.h"

class BoardView {

private:
	Board * board;
	void show();

public:
	void startGame();
	BoardView(Board *b);
};

#endif