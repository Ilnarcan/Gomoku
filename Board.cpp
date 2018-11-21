
#include "Board.h"

Board::Board() {

	for (int i = 0; i < FIELD_SIZE; i++) {
		for (int j = 0; j < FIELD_SIZE; j++) {
			b[i][j] = 0;
		}
	}

}

bool Board::makeMove(int x, int y, sign s) {
	
	// �������� �� ���� ���������� �����
	if ((x >= 0 && x < FIELD_SIZE) && (y >= 0 && y < FIELD_SIZE)) {

		if (b[x][y] != 0) // �������� �� ����������� ���� � ������ ������ ����
			return false;

		b[x][y] = s; // ������ �� ������ ������� ��� �����

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

	// ������������ ��� ����������: ���������� ����������� ����� � ����� � ������, ������� ��� ���������
	// ���� ������ � ������ �������� ��������� � ����� ����� ������� �� ���� �� FIELD_SIZE, �� ���� ���������� = ���������� �������

	//�����������

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

	// ���������

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

	// ������� ���������

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

	// �������� ���������

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

	// ��������� �� ����������� ����

	for (int i = 0; i < FIELD_SIZE; i++) {
		for (int j = 0; j < FIELD_SIZE; j++) {
			if (b[i][j] == 0) {
				return (Board::event)(this->nextTurn);
			}
		}
	}
	
	// ���� �� ���� �� ���� ������� �� ���������(����������� ���� ��� ������ ������ �� �������(2)) �� �����

	return this->draw;
}
