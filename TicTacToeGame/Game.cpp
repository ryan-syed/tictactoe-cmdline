#include "Game.h"

Game::Game(std::unique_ptr<Board> board, std::unique_ptr<std::vector<std::unique_ptr<Player>>> players)
	: m_board{std::move(board)},
	m_players{std::move(players)}
{

}

void Game::run()
{
	while (true) {
		m_players->at(m_turnCounter)->makeMove(*m_board);
		m_turnCounter = (m_turnCounter + 1) % m_players->size();
	}
}

void Game::endGame()
{

}

void Game::undo()
{
}
