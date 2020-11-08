#pragma once

#include <vector>
#include <memory>
#include "Player.h"

class Game
{
public:
	Game(std::unique_ptr <Board> board, std::unique_ptr<std::vector<std::unique_ptr<Player>>> players);
	void run();
	void endGame();
	void undo();
private:
	std::unique_ptr<std::vector<std::unique_ptr<Player>>> m_players;
	std::unique_ptr <Board> m_board;
	int m_turnCounter;
};

