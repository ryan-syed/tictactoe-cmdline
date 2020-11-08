#pragma once

#include <vector>
#include <stack>
#include <iostream>
#include <memory>
#include "Move.h"
#include "Symbol.h"
#include "Player.h"

class Player;

class Board
{
public:
	class Dimensions {
	private:
		int m_rows;
		int m_cols;
	public:
		Dimensions(int rows, int cols) : m_rows{ rows }, m_cols{ cols } { }
		int getRows() const { return m_rows; }
		int getCols() const { return m_cols; }
	};

	Board(Dimensions dimensions, std::unique_ptr<Symbol> emptySymbol);
	void setMove(Move const&, Player const&);
	void undo();
	bool isAllowed(Move const&);
	
	Dimensions const& getDimensions() { return m_dimensions; }
	
private:
	void eraseMove(Move const&);
	void renderBoard();
	void emptyGrid();

	Dimensions m_dimensions;
	std::vector<std::vector<Symbol::symbol_t>> m_grid;
	std::stack<Move> m_moveHistory;
	std::unique_ptr<Symbol> m_emptySymbol;
};

