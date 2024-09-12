#pragma once

struct InputData {
	std::weak_ptr<InputPin> pin;
	std::vector<char> data;
};

struct ChipInputPackage {
	std::vector<InputData> package;
};

struct ChipInputStream {
	std::vector<ChipInputPackage> stream;
};