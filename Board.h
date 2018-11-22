
#ifndef _BOARD_H_
#define _BOARD_H_

class Board {

private:
	int b[3][3];
	const int FIELD_SIZE = 3;

public:
	enum sign { H, X, O };
	enum event { draw, first, second, nextTurn };

	Board();
	bool makeMove(const int x, const int y, const enum sign);
	int getSize();
	event isWin();
	sign getcell(const int x, const int y);

};

#endif