 ///
 /// @file    Node.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-13 12:08:02
 ///
 
#include "Node.h"
#include <assert.h>

const int HUGE_VAL = 0x3ffffff;

double NumberNode::calc()const{
	return _number;
}

double UminusNode::calc()const{
	return - _child->calc();
}

MultipleNode::~MultipleNode(){
	for(auto it = _childs.begin();
		it != _childs.end();
		++it)
	{
		delete *it;
	}
}

double SumNode::calc() const{
	double result = 0.0;
	auto childIt = _childs.begin();
	auto positiveIt = _positives.begin();
	for(; childIt != _childs.end(); 
		++childIt, ++positiveIt)
	{
		assert(positiveIt != _positives.end());
		double val = (*childIt)->calc();
		if(*positiveIt)
			result += val;
		else
			result -= val;
	}

	assert(positiveIt == _positives.end());
	return result;
}


double ProductNode::calc() const{
	double result = 1.0;
	auto childIt = _childs.begin();
	auto positiveIt = _positives.begin();
	for(; childIt != _childs.end(); 
		++childIt, ++positiveIt)
	{
		assert(positiveIt != _positives.end());
		double val = (*childIt)->calc();
		if(*positiveIt)
			result *= val;
		else if(val != 0)
			result /= val;
		else{
			cout << "Division by zero." << endl;
			return 0x3fffffff;
		}
	}
	assert(positiveIt == _positives.end());
	return result;
}

#if 0
double AddNode::calc() const{
	return _left->calc() + _right->calc();
}

double SubNode::calc() const{
	return _left->calc() - _right->calc();
}

double MultiplyNode::calc() const{
	return _left->calc() * _right->calc();
}

double DivideNode::calc() const{
	double divisor = _right->calc();
	if(divisor != 0)
		return _left->calc() / _right->calc();
	else{
		cout << "Error: divisor is zero" << endl;
		return HUGE_VAL;
	}
}
#endif
