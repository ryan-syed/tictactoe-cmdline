#pragma once

#include <memory>
#include "MoveStrategy.h"
#include "Symbol.h"

class MoveStrategy;
class Symbol;
class Board;

class Player {
public:
	Player(std::unique_ptr<Symbol> symbol, std::unique_ptr<MoveStrategy> moveStrategy);
	void makeMove(Board &);
	virtual void setMoveStrategy(std::unique_ptr<MoveStrategy> moveStrategy) = 0;
	Symbol& getSymbolData() const;
protected:
	std::unique_ptr<Symbol> m_symbol;
	std::unique_ptr<MoveStrategy> m_moveStrategy;
};