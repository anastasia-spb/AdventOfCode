#pragma once

#include <iostream>
#include <map>
#include <list>
#include "signal_type.hpp"

typedef uint (*gate_func_t)(uint, uint);

class Gate{
public:
	Gate(std::string instruction, std::string out);
	~Gate(){};

	std::string getIn1() const;
	std::string getIn2() const;
	std::string getOut() const;
	gate_func_t getFunc() const;

private:
	std::string _in1 = " "; //left wire name
	std::string _in2 = " "; //right wire name
	std::string _out; //name of output wire
	gate_func_t gate_func;

};
