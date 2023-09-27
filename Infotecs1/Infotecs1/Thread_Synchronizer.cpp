#include "Thread_Synchronizer.h"

void Thread_Synchronizer::wait()
{
    unique_lock<mutex> ulm(mtx);
    cv.wait(ulm);
}

void Thread_Synchronizer::notify_one()
{
    cv.notify_one();
}