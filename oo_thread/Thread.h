 ///
 /// @file    Thread.h
 /// @author  jack(sunze0924@163.com)
 /// @date    2016-11-15 18:29:22
 ///
#ifndef __THREAD_H__
#define __THREAD_H__

#include "Noncopyable.h"
#include <pthread.h>
#include <iostream>
using std::endl;
using std::cout;

namespace wd
{
class Thread:Noncopyable
{
public:
	Thread();
	virtual ~Thread();
	void start();
	void join();
private:
	static void * threadFunc(void *);
	virtual void run()=0;
private:
	pthread_t _pthId;
	bool      _isRunning;
};


}//end of namespace
#endif
