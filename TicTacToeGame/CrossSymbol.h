#pragma once

#include "Symbol.h"

class CrossSymbol : public Symbol {
public:
	symbol_t getSymbol() {
		return 'X';
	}
};