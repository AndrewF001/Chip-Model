#pragma once
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "../Block/Block.h"
#include "../Data/Register.h"

class Block {
public:
	// Constructors
	Block();
	Block(std::string const& n);
	Block(std::string const& n, std::vector<std::shared_ptr<InputPin>> i, std::vector<std::shared_ptr<OutputPin>> o);

	// Methods
	const bool execute();
	const bool readyToExecute();

	// Customer Code
	virtual bool entryFunction() = 0;


private:
	// Data
	const std::string b_name = "";
	const std::vector<std::shared_ptr<InputPin>> b_in_reg = {};
	const std::vector<std::shared_ptr<OutputPin>> b_out_reg = {};

	bool updateOutputs();
};
