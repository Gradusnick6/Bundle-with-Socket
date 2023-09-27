#pragma once
#include <mutex>
#include <condition_variable>
using namespace std;

class Thread_Synchronizer
{
private:
	condition_variable cv;
	mutex mtx;
public:
	void wait();
	void notify_one();
};

