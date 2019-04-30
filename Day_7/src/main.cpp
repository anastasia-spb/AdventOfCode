#include <fstream>
#include "header.hpp"


int main(){

	Circuit circuit;
	std::ifstream instructions("Input.txt");     // open file
	std::string line;
	/*read input from file and parse instructions*/
	while (getline(instructions, line))  {
		circuit.parse_instruction(line);
	}
	instructions.close();

	std::string wire_name = "a";
	uint val = circuit.find_value(wire_name);
	std::cout << val << std::endl;

	return 0;
}
