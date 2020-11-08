#pragma once

class Symbol {
public:
	using symbol_t = char;
	virtual symbol_t getSymbol() = 0;
};