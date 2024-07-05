#include "Register.h"

Register::Register(unsigned int o, unsigned char s, std::string n) : offset(o), size(s), name(n) {
	data.reserve(s);
}
