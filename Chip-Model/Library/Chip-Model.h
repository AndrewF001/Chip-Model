#pragma once
#include "Chip/Chip.h"

class adder : public Block {
public:
	bool entryFunction() { return true; }
};

int main() {
	Chip c;
	ChipInputStream s;
	// empty
	c.execute(s);

	// 1 block
	auto b = std::make_unique<adder>();
	c.addBlock(std::move(b));
	c.execute(s);
	return 0;
}