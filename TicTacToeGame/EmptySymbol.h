#pragma once

#include "Symbol.h"

class EmptySymbol : public Symbol {
public:
	symbol_t getSymbol() {
		return ' ';
	}
};