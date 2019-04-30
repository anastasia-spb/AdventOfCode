#pragma once

#include "gate.hpp"
#include <thread>
#include "signal_type.hpp"

class Circuit{
public:
	Circuit(){};
	~Circuit();
	void parse_instruction(std::string);

	uint find_value(std::string);

private:
	const std::string separator = " -> ";
	const uint separator_length = separator.size();

	std::map<std::string, uint> wires;
	std::list<Gate*> instructions;



private:
	bool execute_instruction(Gate * &);
	void execute_instructions();
	void check_value(std::string);

};
