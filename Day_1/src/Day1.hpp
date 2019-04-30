#ifndef DAY1_HPP
#define DAY1_HPP

#include <iostream>
#include <fstream>

class Santa{

public:

	Santa(int initialPos = 0):currentPos(initialPos), stepCounter(0),
	                          goalFloor(0), goalFloorIsReached(false){};

	void goUp();
	void goDown();
	void updatePosition(char c);
	int getCurrentPos();
	void checkPosition(char c);
	void setGoalFloor(int f);
	int getStepCounter();

private:

	int currentPos;
	int stepCounter;
	int goalFloor;
	bool goalFloorIsReached;

};


#endif
