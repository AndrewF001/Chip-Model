#include "Chip.h"

Chip::Chip() : Chip("unnamed", {}) {};

Chip::Chip(std::string const& n) : Chip(n, std::vector<std::unique_ptr<Block>>()) {};

Chip::Chip(std::string const& n, std::vector<std::unique_ptr<Block>> b) : name(n), blocks(std::move(b)) {
    std::cout << "built " << name << " chip\n";
};

const bool Chip::execute(std::vector<InputData>& Data) {
    std::cout << "executing " << name << " chip\n";

    std::cout << name << "finished executing\n";
    return false;
}

bool Chip::addBlock(std::unique_ptr<Block>& b) {
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
