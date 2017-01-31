#pragma once

#include <mutex>
#include <queue>

using namespace std;

template <typename T> class ThreadSafeQueue
{
	queue<T>   m_queue;
	std::mutex m_mutex;
	std::condition_variable m_condv;

public:

	void add(T item) {
		std::unique_lock<std::mutex> guard(m_mutex);
		m_queue.push(item);
		guard.unlock();
		m_condv.notify_one();
	}

	T pop() {
		std::unique_lock<std::mutex> guard(m_mutex);
		m_condv.wait(guard, [this]() { return !m_queue.empty(); });
		
		T item = m_queue.front();
		m_queue.pop();

		guard.unlock();

		return item;
	}
};