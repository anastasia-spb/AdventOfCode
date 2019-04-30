#pragma once

#include <iostream>
#include <vector>
#include <thread>

#include "States.hpp"

class Consumer{
public:
	Consumer(unsigned);
	~Consumer(){};

	//start checking box and do work
	void activate();

	mutable std::pair<States, unsigned> my_slot;

private:
	unsigned myID;
	//check if input number satisfies condition
	void doWork(unsigned);
};
