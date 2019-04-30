#include "header.hpp"
#include <fstream>
#include <algorithm>    // std::count_if


Grid::Grid(int width, int height){

	/*set grid size and turn lights off*/
	grid.resize(height, std::vector<unsigned int>(width, 0));
	/*initialize coordinates*/
	x0 = y0 = 0;
	x1 = y1 = 0;
	/*initialize map of instructions*/
	instructions.insert(std::make_pair("turn on ", &turn_on));
	instructions.insert(std::make_pair("turn off ", &turn_off));
	instructions.insert(std::make_pair("toggle ", &toggle));
};

Grid::~Grid(){};

void Grid::parse_coordinates(std::string& line, std::size_t x0_start){

	std::size_t find_comma = line.find(",", x0_start);
	x0 = std::stoi(line.substr(x0_start, find_comma - x0_start));

	std::size_t find_through = line.find("through", find_comma);
	y0 = std::stoi(line.substr(find_comma + 1, find_through-find_comma-1)); //1 is for ' ' symbol

	std::size_t find_space = line.find(" ", find_through);
	find_comma = line.find(",", find_space);
	x1 = std::stoi(line.substr(find_space+1, find_comma-find_space-1));

	y1 = std::stoi(line.substr(find_comma+1, line.size()-find_comma));

	//std::cout << "DEBUG: " << x0 << " " << y0 << " ";
	//std::cout <<  x1 << " " << y1 << std::endl;

};

void Grid::parse_and_execute_instruction(std::string& line){

	for(auto& i : instructions){
		std::size_t find = line.find(i.first);
		if (find != std::string::npos){
			//std::cout << i.first << std::endl;
			parse_coordinates(line, i.first.size());
			(this->*i.second)();
			return;
		}
	}
};

void Grid::turn_on(){

	for(auto i = y0; i <= y1; i++){
		for(auto j = x0; j <= x1; j++)
			++grid[i][j];
	}

};

void Grid::turn_off(){

	for(auto i = y0; i <= y1; i++){
		for(auto j = x0; j <= x1; j++)
			if(grid[i][j] > 0) --grid[i][j];
	}

};

void Grid::toggle(){

	for(auto i = y0; i <= y1; i++){
		for(auto j = x0; j <= x1; j++)
			grid[i][j]+=2;
	}

};

unsigned int Grid::count_lights(){

	unsigned int count = 0;
	for(auto& row : grid)
		std::for_each(row.begin(), row.end(), [&count](unsigned int x){count += x;});

	return count;
};

int main(){

	Grid grid(1000, 1000);
	std::ifstream instructions("Input.txt");     // open file
	std::string line;
	//read input from file
	while (getline(instructions, line))  {
		grid.parse_and_execute_instruction(line);
	}
	instructions.close();

	std::cout << grid.count_lights() << std::endl;

	return 0;
}
