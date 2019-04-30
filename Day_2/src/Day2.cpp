#include "Day2.hpp"

Present::Present(){
	x = 0;
	y = 0;
	z = 0;
};

void Present::setDimensions(unsigned int a, unsigned int b, unsigned int c){
	x = a; y = b; z = c;
}

int Present::paperArea(){
	unsigned int a = x*y;
	unsigned int b = y*z;
	unsigned int c = z*x;
	return std::min(std::min(a, b), c) + 2*a + 2*b + 2*c;
}

int Present::ribbonLength(){

	return 2*x + 2*y + 2*z - 2*std::max(std::max(x, y), z) + x*y*z;
}

int splitInput(std::string input, char separator, std::vector<std::vector<unsigned int>>& dimensions){

	unsigned int begin = 0;
	unsigned int k = 0;
	unsigned int temp = 0;

	for (unsigned int i = 0; i < input.length(); i++){
		if(input[i] == separator){
			temp = std::stoi(input.substr(begin, i-begin));
			dimensions[k].push_back(temp);
			begin = i+1;
			k++;
		}
	}

	temp = std::stoi(input.substr(begin, input.length()-begin));
	dimensions[k].push_back(temp);

	return 0;
}

int main() {

	std::ifstream is("Day2In.txt");     // open file
    int sum = 0; //wrap paper
    int sum2 = 0; //ribbon
	std::string line;
	std::vector<std::vector<unsigned int>> dimensions(3, std::vector<unsigned int>());
	Present p;

	//read input from file
	while (getline(is, line))  {
		splitInput(line, 'x', dimensions);
	}

	for(unsigned int i = 0; i < dimensions[0].size(); i++){
		p.setDimensions(dimensions[0][i], dimensions[1][i], dimensions[2][i]);
		sum += p.paperArea();
		sum2 += p.ribbonLength();
	}

	is.close();
	std::cout << "Wrap paper: " << sum << std::endl; //wrap paper
	std::cout << "Ribbon: " << sum2 << std::endl; //ribbon

	return 0;
}
