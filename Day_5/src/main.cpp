#include "header.hpp"
#include <fstream>

const std::set<char> NiceStrings::vowels = {'a','e','i', 'o', 'u'};
const std::set<std::string> NiceStrings::forbidden_strings = {"ab", "cd", "pq", "xy"};

NiceStrings::NiceStrings(){
	condition1 = condition2 = condition3 = false;
	condition4 = condition5 = false;
}

NiceStrings::~NiceStrings(){}

bool NiceStrings::containsThreeVowels(std::string currentString){

	unsigned int count = 0;
	bool isIn = false;

	for (char  i : currentString){
		isIn = (vowels.find(i) != vowels.end());
		if(isIn){
			++count;
			if(count == 3) return true;
		}
	}

	return false;
}

bool NiceStrings::containsDoubleLetter(std::string currentString){

	for(unsigned int i = 0; i < currentString.size() - 1; i++){
		if(currentString[i] == currentString[i+1])
			return true;
	}

	return false;
}

bool NiceStrings::noForbiddenStrings(std::string currentString){

	std::string sub;
	bool isIn = false;
	for(unsigned int i = 0; i < currentString.size() - 1; i++){
		sub = currentString.substr(i, 2);
		isIn = (forbidden_strings.find(sub) != forbidden_strings.end());
		if(isIn) return false;
	}
	return true;
}

bool NiceStrings::twoLettersTwice(std::string currentString){

	std::string sub;
	std::string previous = "";
	std::set<std::string> unique;
	unsigned int sizeBefore;
	for(unsigned int i = 0; i < currentString.size() - 1; i++){
		sizeBefore = unique.size();
		sub = currentString.substr(i, 2);
		unique.insert(sub);
		if(sizeBefore == unique.size() && sub != previous) return true;
		previous = sub;
	}
	return false;
}

bool NiceStrings::letterRepeatsWithOneBetween(std::string currentString){

	char previous = ' ';
	for(unsigned int i = 0; i < currentString.size(); i+=2){
		if(currentString[i] == previous) return true;
		previous = currentString[i];
	}

	previous = ' ';
	for(unsigned int i = 1; i < currentString.size(); i+=2){
		if(currentString[i] == previous) return true;
		previous = currentString[i];
	}

	return false;
}

int main(){

	//read input from file
	std::ifstream f("Day5In.txt");     // open file
	std::string line;
	std::vector<std::string> input;
	while (getline(f, line))  {
		input.push_back(line);
	}
	f.close(); //close file

	unsigned int amount = 0;
	NiceStrings isNice;
	for (std::string  s : input)
		if(isNice(s)) ++amount;

	std::cout << amount;

	return 0;
}



