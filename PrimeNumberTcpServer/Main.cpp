#include <thread>

#include "ThreadSafeQueue.h"
#include "PrimeCalculator.h"

ThreadSafeQueue<int> m_queue;

void worker_thread()
{
	PrimeCalculator calculator(m_queue);
	calculator.calculate(1, 10);
}

void reader_thread()
{
	while (true)
	{
		int a = m_queue.pop();
		printf("thread %u, item: %i\n", std::this_thread::get_id(), a);
	}
}

int main()
{
	std::thread worker(worker_thread);
	std::thread reader(reader_thread);

	m_queue.add(1);

	worker.join();
	reader.join();

	return 0;
}\