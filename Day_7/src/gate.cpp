#include "gate.hpp"

//======================= Gate functions ==========================

static uint and_gate(uint in1, uint in2){
	return in1 & in2;
}

static uint or_gate(uint in1, uint in2){
	return in1 | in2;
}

static uint not_gate(uint in1, uint in2){
	return ~in2;
}

static uint rshift_gate(uint in1, uint in2){
	return in1 >> in2;
}

static uint lshift_gate(uint in1, uint in2){
	return in1 << in2;
}

static uint assign(uint in1, uint in2){
	return in1;
}

static std::map<std::string, gate_func_t> gate_functions = {
		{"AND", and_gate}, {"OR", or_gate}, {"NOT", not_gate},
		{"RSHIFT", rshift_gate}, {"LSHIFT", lshift_gate}
};

//==================================================================

Gate::Gate(std::string instruction, std::string out):
			_out(out)
{
	std::size_t find;
	for(auto& i : gate_functions){
		find = instruction.find(i.first);
		if (find != std::string::npos){
			if(find > 0)
				_in1 = instruction.substr(0, find - 1);//minus space
			else
				_in1 = "0";
			_in2 = instruction.substr(find + i.first.size() + 1); //+1 for space char
			gate_func = i.second;
			return;
		}
	}

	_in1 = instruction; //this is the value of out
	_in2 = "0";
	gate_func = &assign;
};

std::string Gate::getIn1() const{
	return _in1;
}
std::string Gate::getIn2() const{
	return _in2;
}
std::string Gate::getOut() const{
	return _out;
}

gate_func_t Gate::getFunc() const{
	return gate_func;
}

