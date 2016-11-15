 ///
 /// @file    Condition.cc
 /// @author  jack(sunze0924@163.com)
 /// @date    2016-11-15 21:11:06
 ///
#include "Condition.h"
#include "MutexLock.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
Condition::Condition(MutexLock & mutex)
:_mutex(mutex)
{
	pthread_cond_init(&_cond,NULL);
}
Condition::~Condition()
{
	pthread_cond_destroy(&_cond);
}
void Condition::wait()
{
	pthread_cond_wait(&_cond,_mutex.getMutexLockPtr());
}
void Condition::notify()
{
	pthread_cond_signal(&_cond);
}
void Condition::notifyAll()
{
	pthread_cond_broadcast(&_cond);
}





}//end of namespace
