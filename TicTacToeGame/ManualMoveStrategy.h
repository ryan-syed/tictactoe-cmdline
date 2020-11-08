#pragma once

#include "MoveStrategy.h"

class ManualMoveStrategy: public MoveStrategy
{
	void makeMove(Board &board, Player &player);
};