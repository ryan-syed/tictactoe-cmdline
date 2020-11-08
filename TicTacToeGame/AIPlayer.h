#pragma once

#include <string>
#include "Player.h"
#include "MoveStrategy.h"

class AIPlayer : public Player {
public:
	AIPlayer(std::string name, std::unique_ptr<Symbol> symbol, std::unique_ptr<MoveStrategy> moveStrategy);
	void setMoveStrategy(std::unique_ptr<MoveStrategy> moveStrategy);
private:
	std::string m_name;
};