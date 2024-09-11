#include "Chip.h"

Chip::Chip() : Chip("unnamed", {}) {};

Chip::Chip(std::string const& n) : Chip(n, std::vector<std::unique_ptr<Block>>()) {};

Chip::Chip(std::string const& n, std::vector<std::unique_ptr<Block>> b) : name(n), blocks(std::move(b)) {
    std::cout << "built " << name << " chip\n";
};

const bool Chip::execute(ChipInputStream& Stream) {
    std::cout << "executing " << name << " chip\n";

	for (auto& package : Stream.stream) {  // Read stream of data
		resetBlocksAndLoadPackage(package);

        int executedBlocks = 0;
        while (executedBlocks != blocks.size()) {   // TODO: make multithreaded
            int currentExecuted = 0;
			for (auto& block : blocks) {
                if (block->readyToExecute()) {
                    block->execute();
                    currentExecuted++;
                }
			}

            if (currentExecuted == 0) {
                std::cerr << "Infinite loop detected";
				return false;
            }

			executedBlocks += currentExecuted;
		}
	}

    std::cout << name << " finished executing\n";
    return true;
}

bool Chip::addBlock(std::unique_ptr<Block> b) {
    blocks.push_back(std::move(b));
    return true;
}

bool Chip::addBlocks(std::vector<std::unique_ptr<Block>>& b) {
    blocks.insert(blocks.end(),
        std::make_move_iterator(b.begin()),
        std::make_move_iterator(b.end()));
    return true;
}

bool Chip::removeBlock(int idx) {
    if (idx < 0 || idx >= blocks.size())
        return false;
    
    blocks.erase(blocks.begin() + idx);
    return true;
}

bool Chip::resetBlocksAndLoadPackage(ChipInputPackage& package) {
    for (auto& block : blocks) {
        block->resetBlock();
    }
    for (auto& data : package.data) {
        data.first.lock()->data = data.second;
    }
    return false;
}
