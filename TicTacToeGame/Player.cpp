#include "Player.h"

Player::Player(std::unique_ptr<Symbol> symbol, std::unique_ptr<MoveStrategy> moveStrategy)
	: m_symbol{std::move(symbol)},
	m_moveStrategy{std::move(moveStrategy)}
{
}

void Player::makeMove(Board &board)
{
	m_moveStrategy->makeMove(board, *this);
}

Symbol& Player::getSymbolData() const
{
	return *m_symbol;
}
