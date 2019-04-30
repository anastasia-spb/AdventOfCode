#pragma once

#include <vector>
#include "States.hpp"
#include "Consumer.hpp"
#include <memory>

class Producer{
public:
	Producer(unsigned); //input is the number of consumers
	~Producer(){};

	void activate(); //start Producer's thread
	void add_consumer(std::shared_ptr<Consumer const>); //add shared pointer to a consumer

private:
	unsigned consumers_number;
	std::vector<std::shared_ptr<Consumer const>> my_consumers;

private:
	void start();
	void stopConsumers();
};
