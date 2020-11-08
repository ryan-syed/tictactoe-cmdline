#pragma once

#include "MoveStrategy.h"

class RandomMoveStrategy : public MoveStrategy
{
	void makeMove(Board &board, Player &player);
};