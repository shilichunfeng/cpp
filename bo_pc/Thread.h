 ///
 /// @file    Thread.h
 /// @author  jack(sunze0924@163.com)
 /// @date    2016-11-15 22:24:13
 ///
#ifndef __THREAD_H__
#define __THREAD_H__

#include "Noncopyable.h"
#include <pthread.h>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;

namespace wd
{

class Thread:Noncopyable
{
public:
	typedef function<void()> ThreadCallback;
	Thread(ThreadCallback cb);
	~Thread();
	void start();
	void join();
private:
	static void * threadFunc(void *);
private:
	pthread_t _pthId;
	ThreadCallback _cb;
	bool _isRunning;
};

}//end of namespace
#endif
