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
	executed = true;

    std::cout << b_name << "finished " << b_name << " block executing\n";
    return true;
}

const bool Block::readyToExecute() {
	if (executed)
		return false;

	for (auto& in : b_in_reg) {
		if (!in->execuatable)
			return false;
	}
    return true;
}

const bool Block::resetBlock() {
    executed = false;

    for (auto& in : b_in_reg) {
        in->execuatable = false;
    }

    return true;
}

const bool Block::connectBlock(Block& block) {
    // Create registers
	auto in = std::shared_ptr<InputPin>();
	auto out = std::shared_ptr<OutputPin>();

    // Link registers
	out->connect(in);

	// Add registers to block
    block.b_in_reg.push_back(std::move(in));
	b_out_reg.push_back(std::move(out));
    return false;
}

const bool Block::connectBlock(std::vector<Block&> blocks) {
    auto out = std::shared_ptr<OutputPin>();

    // Link registers
	for (auto& b : blocks) {
		auto in = std::shared_ptr<InputPin>();
		out->connect(in);
		b.b_in_reg.push_back(std::move(in));
	}

    b_out_reg.push_back(std::move(out));
    return false;
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
