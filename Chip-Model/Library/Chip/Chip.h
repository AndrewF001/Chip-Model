#pragma once
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "../Block/Block.h"
#include "../Data/ChipInputData.h"


class Chip {
public:
	// Constructors
	Chip();
	Chip(std::string const& n);
	Chip(std::string const& n, std::vector<std::unique_ptr<Block>> b);

	// Methods
	const bool execute(std::vector<ChipInputData>& Data);
	bool addBlock(std::unique_ptr<Block>& b);
	bool addBlocks(std::vector<std::unique_ptr<Block>>& b);
	bool removeBlock(int idx);

private:
	// Data
	const std::string name = "";
	std::vector<std::unique_ptr<Block>> blocks = {};	// Unique pointer so that only one owner of the block exists
};
