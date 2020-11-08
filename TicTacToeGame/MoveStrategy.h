#pragma once

#include "Move.h"
#include "Board.h"
#include "Player.h"

class Board;
class Player;

class MoveStrategy {
public:
	virtual void makeMove(Board &board, Player &player) = 0;
};