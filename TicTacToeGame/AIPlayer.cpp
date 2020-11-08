#include "AIPlayer.h"

AIPlayer::AIPlayer(std::string name, std::unique_ptr<Symbol> symbol, std::unique_ptr<MoveStrategy> moveStrategy)
	:m_name{ name },
	Player(move(symbol), move(moveStrategy))
{

}

void AIPlayer::setMoveStrategy(std::unique_ptr<MoveStrategy> moveStrategy)
{
	m_moveStrategy = move(moveStrategy);
}
