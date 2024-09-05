#pragma once
#include <string>
#include <vector>
#include <memory>

// Define classes
struct Register;
class InputPin;
class OutputPin;

struct Register {
public:
	// Data - used for logging, memory isnt mapped out into physical memory of simulator hardware
	const std::string name = "";
	const unsigned int offset = 0x0;
	const unsigned char size = 0x0;
	std::vector<char> data;				// TODO: add privileges

	// Constructor
	Register(unsigned int o = 0, unsigned char s = 0, std::string n = "");
};

class OutputPin : public Register {
public:
	// Data
	std::vector<std::weak_ptr<InputPin>> connected;	// Links registers (acts as a bus)
	
	// Constructor
	OutputPin(std::vector<std::shared_ptr<InputPin>> c, unsigned int o = 0x0, unsigned char s = 0x0, std::string n = "");

	// Methods
	bool connect(std::shared_ptr<InputPin> i);
};

class InputPin : public Register {
public:
	// Data
	bool execuatable;
};

