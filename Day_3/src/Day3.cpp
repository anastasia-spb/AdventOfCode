#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>


class Carrier{

private:
	std::map <char,unsigned int> directionMap;
	std::map <char,unsigned int> opositeDirectionMap;
	std::vector<unsigned int> direction; //^>v<

public:
	Carrier(){
		directionMap = {{ '^', 0 },	{ '>', 1 },
			            { 'v', 2 }, { '<', 3 }};
		opositeDirectionMap = {{ 'v', 0 }, { '<', 1 },
					           { '^', 2 }, { '>', 3 }};
		direction.resize(directionMap.size());
	};

	int move(char c);
	unsigned int returnDirectionKey();

};

int Carrier::move(char c){

	if(direction[opositeDirectionMap.at(c)] > 0){
		direction[opositeDirectionMap.at(c)]--;
	} else {
		direction[directionMap.at(c)]++;
	}

	return 0;
}

unsigned int Carrier::returnDirectionKey(){

	unsigned int key = 0;
	//we suppose, that maximum distance to one direction is 1000
	for (unsigned int i = 0; i < direction.size(); i++){
		key += direction[i]*pow(1000, i);
	}

	std::cout << key << std::endl;
	return key;
}


int main() {

	std::set<unsigned int> directionsSet;
	std::vector<Carrier> carrier(2); //0 - Santa, 1 - Robot
	directionsSet.insert(0); //insert initial position
	std::ifstream is("Day3In.txt");     // open file
	char c; int ii = 0;
	while (is.get(c))  {
		carrier[ii % carrier.size()].move(c);
		directionsSet.insert(carrier[ii % carrier.size()].returnDirectionKey());
		ii++;
	}

	std::cout << directionsSet.size();
	return 0;
}
