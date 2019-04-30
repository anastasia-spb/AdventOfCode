#pragma once

#include <iostream>
#include <string>
#include <set>
#include <vector>

class NiceStrings{
public:
	NiceStrings();
	~NiceStrings();

	bool operator()(std::string s){

		/*first task*/
		//condition1 = containsThreeVowels(s);
		//condition2 = containsDoubleLetter(s);
		//condition3 = noForbiddenStrings(s);

		//return condition1&&condition2&&condition3;

		/*second task*/
		condition4 = twoLettersTwice(s);
		condition5 = letterRepeatsWithOneBetween(s);

		return condition4&&condition5;
	};

private:

	static const std::set<char> vowels;
	static const std::set<std::string> forbidden_strings;

	bool condition1, condition2, condition3;
	bool condition4, condition5;

	bool containsThreeVowels(std::string);
	bool containsDoubleLetter(std::string);
	bool noForbiddenStrings(std::string);
	bool twoLettersTwice(std::string);
	bool letterRepeatsWithOneBetween(std::string);

};
