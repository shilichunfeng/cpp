 ///
 /// @file    Condition.h
 /// @author  jack(sunze0924@163.com)
 /// @date    2016-11-15 21:00:52
 ///

#ifndef __CONDITION_H__
#define __CONDITION_H__

#include "Noncopyable.h"
#include <pthread.h>
namespace wd
{
class MutexLock;
class Condition:Noncopyable
{
public:
	Condition(MutexLock & mutex);
	~Condition();
	void wait();
	void notify();
	void notifyAll();
private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};



}//end of namespace
#endif

