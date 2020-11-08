#include "Game.h"
#include "Board.h"
#include "Symbol.h"
#include "EmptySymbol.h"
#include "CrossSymbol.h"
#include "CircleSymbol.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "MoveStrategy.h"
#include "ManualMoveStrategy.h"
#include <memory>
#include <string>

using namespace std;

int main() {
	Board::Dimensions dimensions{ 3, 3 };
	unique_ptr<Symbol> emptySymbol = make_unique<EmptySymbol>(EmptySymbol{});
	unique_ptr<Board> board = make_unique<Board>(Board {dimensions, std::move(emptySymbol) });
	
	unique_ptr<Player> player1 = make_unique<HumanPlayer>(
		"Ryan",
		move(make_unique<CrossSymbol>()),
		move(make_unique<ManualMoveStrategy>(ManualMoveStrategy())
		));

	unique_ptr<Player> player2 = make_unique<HumanPlayer>(
		"Sweha",
		move(make_unique<CircleSymbol>()),
		move(make_unique<ManualMoveStrategy>(ManualMoveStrategy())
		));

	unique_ptr<vector<unique_ptr<Player>>> players = make_unique<vector<unique_ptr<Player>>>();
	players->push_back(move(player1));
	players->push_back(move(player2));

	Game game{ move(board), move(players) };
	game.run();

	getchar();
	return 0;
}