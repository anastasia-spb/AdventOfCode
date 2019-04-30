#ifndef DAY2_HPP
#define DAY2_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Present{

public:
	Present();

	void setDimensions(unsigned int a, unsigned int b, unsigned int c);

	int paperArea();

	int ribbonLength();

private:
	 //dimensions:
	unsigned int x;
	unsigned int y;
	unsigned int z;

};


int splitInput(std::string input, char separator, std::vector<std::vector<unsigned int>>& dimensions);

#endif
