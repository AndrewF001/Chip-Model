#include "Register.h"

// Register
Register::Register(unsigned int o, unsigned char s, std::string n) : offset(o), size(s), name(n) {
	data.reserve(s);
}

// OutputPin
OutputPin::OutputPin(std::vector<std::shared_ptr<InputPin>> c, unsigned int o, unsigned char s, std::string n) : Register(o, s, n) {
	for (auto& i : c) {
		connected.push_back(i);
	}
}

bool OutputPin::connect(std::shared_ptr<InputPin> i) {
	connected.push_back(i);
	return true;
}
