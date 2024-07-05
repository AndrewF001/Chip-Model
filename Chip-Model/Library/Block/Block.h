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
	Block(std::string const& n, std::vector<std::unique_ptr<InputPin>> i, std::vector<std::unique_ptr<OutputPin>> b_out_reg o);

	// Methods
	const bool execute();
	const bool readyExecute();

	// Customer Code
	virtual bool entryFunction() = 0;


private:
	// Data
	const std::string b_name = "";
	std::vector<std::unique_ptr<InputPin>> b_in_reg = {};
	std::vector<std::unique_ptr<OutputPin>> b_out_reg = {};
};
