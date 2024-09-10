#pragma once

struct ChipInputPackage {
	std::vector<std::pair<std::weak_ptr<InputPin>, std::vector<char>>> data;
};

struct ChipInputStream {
	std::vector<ChipInputPackage> stream;
};