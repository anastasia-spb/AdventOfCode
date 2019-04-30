#include "Consumer.hpp"
#include "md5.h"
#include <atomic>

static std::string secret_key = "ckczppom";
static std::string target_sequence = "000000";

Consumer::Consumer(unsigned id):
		myID(id)
{
	my_slot = {empty, 0};
}

void Consumer::activate(){

	while((my_slot.first) != close){
			while(my_slot.first == empty){
				//wait;
				std::this_thread::yield();
			}
			if(my_slot.first != close){
				std::atomic<unsigned> task_value(my_slot.second); //read task from producer
				my_slot = {empty, 0}; //empty my slot
				doWork(task_value); //do task
			}
		}
}

void Consumer::doWork(unsigned int in){

	std::string md5_input = secret_key + std::to_string(in);
	MD5 md5 = MD5(md5_input);
	std::string md5_output = md5.hexdigest();
	std::string subs = md5_output.substr(0, target_sequence.size());

	if(subs.compare(target_sequence) == 0){
		my_slot = {close, 0};
		std::cout << "Thread number: " << myID << ". Answer: " << in << std::endl;
	}
}
