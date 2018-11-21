
#include "Board.h"

Board::Board() {

	for (int i = 0; i < FIELD_SIZE; i++) {
		for (int j = 0; j < FIELD_SIZE; j++) {
			b[i][j] = 0;
		}
	}

}

bool Board::makeMove(int x, int y, sign s) {
	
	// проверка на ввод дозволеных чисел
	if ((x >= 0 && x < FIELD_SIZE) && (y >= 0 && y < FIELD_SIZE)) {

		if (b[x][y] != 0) // проверка на возможность хода в данную клетку поля
			return false;

		b[x][y] = s; // ставим на клетку крестик или нолик

		return true;
	}
	else
		return false;

}

int Board::getSize() {
	return this->FIELD_SIZE;
}

Board::sign Board::getcell(int x, int y) {
	if (b[x][y] == 0)
		return this->H;
	else if (b[x][y] == 1)
		return this->X;
	else 
		return this->O;
}

Board::event Board::isWin() {

	// используются две переменные: количество заполненных ячеек и сумма в строке, столбце или диагонале
	// если ячейки в данной проверке заполнены и сумма чисел делится на цело на FIELD_SIZE, то есть победитель = результату деления

	//горизонталь

	int filled_cells = 0;
	int sum = 0;
	for (int i = 0; i < FIELD_SIZE; i++) {
		for (int j = 0; j < FIELD_SIZE; j++) {
			if (b[i][j] != 0)
				filled_cells++;
			sum = sum + b[i][j];
		}
		if (filled_cells == FIELD_SIZE && sum != 0 && sum % FIELD_SIZE == 0) {
			return (Board::event)(sum / FIELD_SIZE);
		}
		filled_cells = 0;
		sum = 0;
	}

	// вертикаль

	filled_cells = 0;
	sum = 0;
	for (int i = 0; i < FIELD_SIZE; i++) {
		for (int j = 0; j < FIELD_SIZE; j++) {
			if (b[j][i] != 0)
				filled_cells++;
			sum = sum + b[j][i];
		}
		if (filled_cells == FIELD_SIZE && sum != 0 && sum % FIELD_SIZE == 0) {
			return (Board::event)(sum / FIELD_SIZE);
		}
		filled_cells = 0;
		sum = 0;
	}

	// главная диагональ

	filled_cells = 0;
	sum = 0;
	for (int i = 0; i < FIELD_SIZE; i++) {
		if (b[i][i] != 0)
			filled_cells++;
		sum = sum + b[i][i];
	}
	if (filled_cells == FIELD_SIZE && sum != 0 && sum % FIELD_SIZE == 0) {
		return (Board::event)(sum / FIELD_SIZE);
	}

	// побочная диагональ

	filled_cells = 0;
	sum = 0;
	for (int i = 0; i < FIELD_SIZE; i++) {
		if (b[i][FIELD_SIZE - 1 - i] != 0)
			filled_cells++;
		sum = sum + b[i][FIELD_SIZE - 1 - i];
	}
	if (filled_cells == FIELD_SIZE && sum != 0 && sum % FIELD_SIZE == 0) {
		return (Board::event)(sum / FIELD_SIZE);
	}

	// проверяем на возможность хода

	for (int i = 0; i < FIELD_SIZE; i++) {
		for (int j = 0; j < FIELD_SIZE; j++) {
			if (b[i][j] == 0) {
				return (Board::event)(this->nextTurn);
			}
		}
	}
	
	// если ни одно из трех условий не выполнено(возможность хода или победа одного из игроков(2)) то ничья

	return this->draw;
}
