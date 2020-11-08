#pragma once

#include "Symbol.h"

class CircleSymbol : public Symbol {
public:
	symbol_t getSymbol() {
		return 'O';
	}
};