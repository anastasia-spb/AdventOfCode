#include <memory>
#include "Producer.hpp"
#include "Consumer.hpp"
#include "States.hpp"
#include "Day4.hpp"


void find_and_print_result(const unsigned consumers_count){

	Producer prod(consumers_count); //create producer
	/*create threads and start search*/
	std::vector<std::thread> threads;

	std::vector<std::shared_ptr<Consumer>> vector_of_consumers(consumers_count);
	for(unsigned i = 0; i < consumers_count; i++){
		vector_of_consumers[i] = std::shared_ptr<Consumer>{new Consumer(i)};
		prod.add_consumer(vector_of_consumers[i]);
		threads.push_back(std::thread(&Consumer::activate, vector_of_consumers[i]));
	}

	threads.push_back(std::thread(&Producer::activate, prod));

	/*wait for threads*/
	for (std::thread& th : threads) th.join();
}

int main() {

	/*Input parameter*/
	unsigned numberOfThreads = 0;
	std::cout << "Enter the number of threads: ";
	std::cin >> numberOfThreads;

	if(numberOfThreads < 1 || numberOfThreads > 8)
		numberOfThreads = 7;//default value

	find_and_print_result(numberOfThreads);


	return 0;
}
