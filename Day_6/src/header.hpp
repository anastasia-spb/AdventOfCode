#pragma once

#include <iostream>
#include <vector>
#include <map>

class Grid{
public:
	Grid(int width, int height);
	~Grid();

	void parse_and_execute_instruction(std::string& line);
	unsigned int count_lights();

private:
	/*lights grid*/
	std::vector<std::vector<unsigned int>> grid;

	/*result of parse instruction function*/
	std::string instruction;
	int x0, y0;
	int x1, y1;

	/*map of instructions*/
	std::map<std::string, void (Grid::*)(void)> instructions;

private:
	/*parse everything after instruction*/
	void parse_coordinates(std::string& line, std::size_t);

	/*Instructions: */
	void turn_on();
	void turn_off();
	void toggle();

};
