 ///
 /// @file    Thread.cc
 /// @author  jack(sunze0924@163.com)
 /// @date    2016-11-15 18:46:47
 ///
 
#include "Thread.h"
namespace wd
{
Thread::Thread()
:_pthId(0)
,_isRunning(false)
{}
Thread::~Thread()
{
	if(_isRunning)
		pthread_detach(_pthId);
}
void Thread::start()
{
	pthread_create(&_pthId,NULL,
					&Thread::threadFunc,this);
	_isRunning=true;
}
void Thread::join()
{
	if(_isRunning)
		pthread_join(_pthId,NULL);
}
void * Thread::threadFunc(void *arg)
{
	Thread * pthread=static_cast<Thread*>(arg);
	if(pthread)
		pthread->run();
}

}//end of namespace 
