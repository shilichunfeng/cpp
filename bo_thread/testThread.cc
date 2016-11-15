 ///
 /// @file    testThread.cc
 /// @author  jack(sunze0924@163.com)
 /// @date    2016-11-15 19:41:58
 ///
#include "Thread.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <functional>
#include <iostream>
using std::cout;
using std::endl;
using std::bind;

struct Foo
{
	void run()
	{
		::srand(time(NULL));
		while(1)
		{
			int number=rand()%100;
			cout<<"number= "<<number<<endl;
			::sleep(1);
		}
	}
};
int main()
{
	wd::Thread *pThread=new wd::Thread(bind(&Foo::run,Foo()));
	pThread->start();
	pThread->join();
	return 0;
}
