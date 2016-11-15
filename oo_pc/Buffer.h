 ///
 /// @file    Buffer.h
 /// @author  jack(sunze0924@163.com)
 /// @date    2016-11-15 21:16:51
 ///
#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "MutexLock.h"
#include "Condition.h"
#include <queue>
using std::queue;

namespace wd
{
typedef int Data;
class Buffer
{
public:
	Buffer(size_t size);
	void push(Data data);
	Data pop();
	bool full()const;
	bool empty()const;
private:
	size_t _queSize;
	queue<Data> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
};

}//end of namespace
#endif

