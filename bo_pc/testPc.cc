 ///
 /// @file    testPc.cc
 /// @author  jack(sunze0924@163.com)
 /// @date    2016-11-15 22:49:46
 ///
#include "Thread.h"
#include "Buffer.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <functional>
#include <iostream>
using std::cout;
using std::endl;
using std::bind;

struct Producer
{
	void produce(wd::Buffer & buffer)
	{
		::srand(time(NULL));
		while(1)
		{
			int number=::rand()%100;
			buffer.push(number);
			cout<<"produce a number: "<<number<<endl;
			::sleep(1);
		}
	}
};
struct Consumer
{
	void consume(wd::Buffer & buffer)
	{
		while(1)
		{
			int number=buffer.pop();
			cout<<number<<endl;
			sleep(2);
		}
	}
};

int main()
{

	wd::Buffer buffer(10);
	Producer producer;
	Consumer consumer;
	//bind是值传递，如果直接传递buffer对象，是会进行复制的
	//但是buffer类对象是不能进行复制的
	wd::Thread pro(bind(&Producer::produce,&producer,std::ref(buffer)));
	wd::Thread con(bind(&Consumer::consume,&consumer,std::ref(buffer)));

	pro.start();
	con.start();
	pro.join();
	con.join();
	return 0;
}
