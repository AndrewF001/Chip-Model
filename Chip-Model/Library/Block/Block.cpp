#include "Block.h"

Block::Block() : Block("unnamed", {}, {}) {};

Block::Block(std::string const& n) : Block(n, std::vector<std::unique_ptr<InputPin>>(), std::vector<std::unique_ptr<OutputPin>>()) {};

Block::Block(std::string const& n, std::vector<std::unique_ptr<InputPin>> i, std::vector<std::unique_ptr<OutputPin>> o) : b_name(n), b_in_reg(i), b_out_reg(o) {

    std::cout << "built " << b_name << " Block\n";
};

const bool Block::execute() {
    std::cout << "executing " << b_name << " block\n";

    entryFunction();

    std::cout << b_name << "finished " << b_name << " block executing\n";
    return false;
}

const bool Block::readyExecute() {
    return false;
}
