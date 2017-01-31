#include "PrimeCalculator.h"

PrimeCalculator::PrimeCalculator(ThreadSafeQueue<int>& queue) : m_queue(queue)
{
}

PrimeCalculator::~PrimeCalculator()
{
}

void PrimeCalculator::calculate(int low, int high)
{
	m_queue.add(low);
	m_queue.add(high);
}
