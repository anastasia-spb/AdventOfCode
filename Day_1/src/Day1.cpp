#include "Day1.hpp"

void Santa::setGoalFloor(int f){
	goalFloor = f;
	return;
}

int Santa::getCurrentPos(){
	return currentPos;
}

int Santa::getStepCounter(){
	return stepCounter;
}

void Santa::goUp(){
	currentPos++;
	return;
}

void Santa::goDown(){
	currentPos--;
	return;
}

void Santa::updatePosition(char c){
	if(c == '('){
		goUp();
	} else if(c == ')'){
		goDown();
	} else {
		std::cout << "Wrong input" << std::endl;
	}

	return;
}

void Santa::checkPosition(char c){

	if(goalFloorIsReached)
		return;

	stepCounter++;
	if(currentPos == goalFloor)
		goalFloorIsReached = true;

	return;
}


int main() {

	Santa santa(0);
	santa.setGoalFloor(-1);

	char c;
	std::ifstream is("Task1In.txt");
	while (is.get(c))  {
	   santa.updatePosition(c);
	   santa.checkPosition(c);
	}

	is.close();

	std::cout << "Part 1: " << santa.getCurrentPos() << std::endl;
	std::cout << "Part 2: " << santa.getStepCounter() << std::endl;

	return 0;
}
