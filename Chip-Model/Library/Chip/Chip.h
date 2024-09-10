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
	const bool execute(ChipInputStream& Stream);
	bool addBlock(std::unique_ptr<Block>& b);
	bool addBlocks(std::vector<std::unique_ptr<Block>>& b);
	bool removeBlock(int idx);

private:
	// Data
	const std::string name = "";
	const std::vector<std::shared_ptr<InputPin>> c_in_pin = {};
	const std::vector<std::shared_ptr<OutputPin>> c_out_pin = {};
	std::vector<std::unique_ptr<Block>> blocks = {};	// Unique pointer so that only one owner of the block exists

	bool resetBlocksAndLoadPackage(ChipInputPackage& p);
};
