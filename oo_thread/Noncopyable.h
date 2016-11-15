 ///
 /// @file    Noncopyable.h
 /// @author  jack(sunze0924@163.com)
 /// @date    2016-11-15 18:23:39
 ///
#ifndef __NONCOPYABLE_H__
#define __NONCOPYABLE_H__

namespace wd
{
class Noncopyable
{
protected:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable &);
	Noncopyable & operator =(const Noncopyable &);
};


}//end of namespace
#endif
