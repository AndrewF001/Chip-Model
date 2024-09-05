#include "Block.h"

Block::Block() : Block("unnamed", {}, {}) {};

Block::Block(std::string const& n) : Block(n, std::vector<std::shared_ptr<InputPin>>(), std::vector<std::shared_ptr<OutputPin>>()) {};

Block::Block(std::string const& n, std::vector<std::shared_ptr<InputPin>> i, std::vector<std::shared_ptr<OutputPin>> o) : b_name(n), b_in_reg(i), b_out_reg(o) {

    std::cout << "built " << b_name << " Block\n";
};

const bool Block::execute() {
    std::cout << "executing " << b_name << " block\n";

    entryFunction();    // Run user code	
	updateOutputs();    // Update block outputs to connected inputs

    std::cout << b_name << "finished " << b_name << " block executing\n";
    return true;
}

const bool Block::readyToExecute() {
	for (auto& in : b_in_reg) {
		if (!in->execuatable)
			return false;
	}
    return true;
}

bool Block::updateOutputs() {
    for (auto& out : b_out_reg) {
        for (auto& in : out->connected) {
            if (auto pin = in.lock()) {
                pin->data = out->data;
            } else {
                std::cout << "Input pin not connected\n";
                std::terminate();
                return false;
            }
        }
    }
    return true;
}
