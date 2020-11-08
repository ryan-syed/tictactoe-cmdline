#include "ManualMoveStrategy.h"

#include <iostream>

using std::cout;
using std::cin;

void ManualMoveStrategy::makeMove(Board &board, Player &player)
{
	bool safeMove = false;
	int i{}, j{};

	while (!safeMove) {
		cout << "Enter i and j position:\n";
		cin >> i >> j;
		if (board.isAllowed(Move{ i, j }))
			safeMove = true;
		else
			cout << "Invalid move\n";
	}
	board.setMove(Move{ i, j }, player);
}
