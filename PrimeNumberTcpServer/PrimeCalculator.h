#pragma once

#include "ThreadSafeQueue.h"

class PrimeCalculator
{
public:
	PrimeCalculator(ThreadSafeQueue<int>& queue);
	~PrimeCalculator();

public:
	void calculate(int low, int high);

private:
	ThreadSafeQueue<int>& m_queue;
};

