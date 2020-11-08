#include <cstdlib>
#include "RandomMoveStrategy.h"
#include "Board.h"

void RandomMoveStrategy::makeMove(Board &board, Player &player)
{
	Board::Dimensions const& dimensions = board.getDimensions();
	int rows = dimensions.getRows();
	int cols = dimensions.getCols();

	bool safeMove = false;
	int i{}, j{};

	while (!safeMove) {
		i = rand() % rows;
		j = rand() % cols;
		if (board.isAllowed(Move{ i, j }))
			safeMove = true;
	}
	board.setMove(Move{ i, j }, player);
}
