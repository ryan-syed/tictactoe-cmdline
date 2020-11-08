#include "Board.h"

using std::cout;
using std::vector;

Board::Board(Dimensions dimensions, std::unique_ptr<Symbol> emptySymbol)
	: m_dimensions{ dimensions },
	m_emptySymbol{std::move(emptySymbol)},
	m_grid{vector<vector<char>>(dimensions.getRows(), vector<char>(dimensions.getCols(), ' '))}
{
	emptyGrid();
	renderBoard();
}

void Board::setMove(Move const& move, Player const& player)
{
	m_grid[move.i][move.j] = player.getSymbolData().getSymbol();
	renderBoard();
}

void Board::undo()
{
	if (!m_moveHistory.empty()) {
		Move previousMove = m_moveHistory.top();
		eraseMove(previousMove);
		m_moveHistory.pop();
	}
}

bool Board::isAllowed(Move const& move)
{
	int rows = m_dimensions.getRows();
	int cols = m_dimensions.getCols();
	int i = move.i;
	int j = move.j;
	if ((i < 0 or i >= rows or j < 0 or j >= cols) or
		(m_grid[i][j] != m_emptySymbol->getSymbol()))
		return false;
	return true;
}

void Board::eraseMove(Move const& move)
{
	m_grid[move.i][move.j] = m_emptySymbol->getSymbol();
}

void Board::renderBoard()
{
	int rows = m_dimensions.getRows();
	int cols = m_dimensions.getCols();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << '|' << m_grid[i][j] << '|';
		}
		cout << '\n';
	}
}

void Board::emptyGrid()
{
	int rows = m_dimensions.getRows();
	int cols = m_dimensions.getCols();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			m_grid[i][j] = m_emptySymbol->getSymbol();
		}
	}
}
