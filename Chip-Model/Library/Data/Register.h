#pragma once
#include <string>
#include <vector>
#include <memory>

struct Register {
public:
	// Data - used for logging, memory isn't mapped out into physical memory of simulator hardware
	const std::string name = "";
	const unsigned int offset = 0x0;
	const unsigned char size = 0x0;
	std::vector<char> data;	// TODO: add privileges

	// Constructor
	Register(unsigned int o = 0, unsigned char s = 0, std::string n = "");
};

class OutputPin : public Register {
	std::vector<std::shared_ptr<InputPin>> connected;
};

class InputPin : public Register {
	bool execuatable;
};

