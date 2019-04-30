#include "circuit.hpp"

static bool isValue(std::string s){

	if(s.size() == 0)
		throw std::invalid_argument( "wire name/value has 0 length" );

	return std::isdigit(static_cast<unsigned char>(s[0]));
}

Circuit::~Circuit(){

	for(auto& i : instructions)
		delete(i);
}

void Circuit::parse_instruction(std::string input){

	std::size_t find_sep = input.find(" -> "); //find assign symbol
	uint wire_name_length = input.size() - separator_length - find_sep;
	std::string wire_name = input.substr(find_sep + separator_length, wire_name_length);

	std::string instruction = input.substr(0, find_sep);
	instructions.push_back(new Gate(instruction, wire_name));

	return;
}

bool Circuit::execute_instruction(Gate * & i){

	//this is a main thread
	uint in1_value, in2_value;
	if ( isValue(i->getIn1()) ) {
		in1_value = std::stoi(i->getIn1());
	} else if (wires.find(i->getIn1()) == wires.end()){
		// first input doesn't have a value
		return false;
	} else {
		in1_value = wires[i->getIn1()];
	}

	if ( isValue(i->getIn2()) ) {
		in2_value = std::stoi(i->getIn2());
	} else if (wires.find(i->getIn2()) == wires.end()){
		// first input doesn't have a value
		return false;
	} else {
		in2_value = wires[i->getIn2()];
	}

	wires[i->getOut()] = (i->getFunc())(in1_value, in2_value);
	return true;
}


void Circuit::execute_instructions(){

	while(instructions.size() > 0){
		std::cout << "Size: " << instructions.size() << std::endl;
		auto i = instructions.begin();
		while(i != instructions.end()){
			if(execute_instruction(*i)){
				delete(*i);
				i = instructions.erase(i);
			}

			 else
				++i;
		}
	}
}

void Circuit::check_value(std::string s){
	while(wires.find(s) == wires.end()){}
}

uint Circuit::find_value(std::string s){

	std::thread execute_instructions_thread(&Circuit::execute_instructions, this);
	execute_instructions_thread.detach();

	std::thread wait_for_value_thread(&Circuit::check_value, this, s);
	wait_for_value_thread.join();

	return wires[s];
}


