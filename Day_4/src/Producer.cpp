#include "Producer.hpp"
#include "limits.h"
#include <iostream>

Producer::Producer(unsigned K):
	consumers_number(K)
{
};

void Producer::add_consumer(std::shared_ptr<Consumer const> c){
	my_consumers.push_back(c);
}


void Producer::activate(){

	start();
	stopConsumers();
}

void Producer::start(){

	unsigned i = 0;
	unsigned current_consumer = 0;

	while(i < UINT_MAX){
		while(my_consumers[current_consumer]->my_slot.first != empty){
			if(my_consumers[current_consumer]->my_slot.first == close) return;
			current_consumer = (current_consumer+1)%consumers_number;
		}
		my_consumers[current_consumer]->my_slot = {busy, i};
		++i;
	}
}


void Producer::stopConsumers(){

	unsigned numNotified = 0;
	while (numNotified < consumers_number) {
		my_consumers[numNotified]->my_slot.first = close;
	   ++numNotified;
	}
}
