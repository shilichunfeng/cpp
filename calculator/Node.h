 ///
 /// @file    Node.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-13 11:38:14
 ///
 
#ifndef __WANGDAO_NODE_H__
#define __WANGDAO_NODE_H__

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Node{
public:
	virtual double calc() const = 0;
	virtual ~Node(){}
};


class NumberNode : public Node{
public:
	NumberNode(double number)
	: _number(number)
	{
		cout << "NumberNode(double)" << endl;
	}

	~NumberNode(){	cout << "~NumberNode()" << endl;	}

	double calc()const;
private:
	const double _number;
};

class UnaryNode : public Node{
public:
	UnaryNode(Node * child)
	: _child(child)
	{}

	~UnaryNode()
	{
		delete _child;
	}

protected:
	Node * _child;
};

class UminusNode : public UnaryNode{
public:
	UminusNode(Node * child)
	: UnaryNode(child)
	{
		cout << "UminusNode(Node*)" << endl;
	}

	~UminusNode(){	cout << "~UminusNode()" << endl;	}
	virtual double calc() const;
};

class MultipleNode : public Node{
public:
	MultipleNode(Node * node){
		appendChild(node, true);
	}

	void appendChild(Node * node, bool positive){
		_childs.push_back(node);
		_positives.push_back(positive);
	}

	~MultipleNode();

protected:
	vector<Node *> _childs;
	vector<bool>   _positives;
};

class SumNode : public MultipleNode{
public:
	SumNode(Node * node)
	: MultipleNode(node)
	{}

	double calc() const;
};

class ProductNode : public MultipleNode{
public:
	ProductNode(Node * node)
	: MultipleNode(node)
	{}

	double calc() const;

};



#if 0
//抽象类
class BinaryNode : public Node{
public:
	BinaryNode(Node * left, Node * right)
	: _left(left)
	, _right(right)
	{}

	~BinaryNode()
	{
		delete _left;
		delete _right;
	}
protected:
	Node * const _left;
	Node * const _right;
};

class AddNode : public BinaryNode{
public:
	AddNode(Node * left, Node * right)
	: BinaryNode(left, right)
	{
		cout << "AddNode(Node *, Node *)" << endl;
	}

	~AddNode()
	{	cout << "~AddNode()" << endl;	}
	
	virtual double calc() const;
};

class SubNode : public BinaryNode{
public:
	SubNode(Node * left, Node * right)
	: BinaryNode(left, right)
	{
		cout << "SubNode(Node *, Node *)" << endl;
	}

	~SubNode(){	cout << "~SubNode()" << endl;	}

	virtual double calc() const;
};

class MultiplyNode : public BinaryNode{
public:
	MultiplyNode(Node * left, Node * right)
	: BinaryNode(left, right)
	{
		cout << "MultiplyNode(Node *, Node *)" << endl;
	}

	~MultiplyNode(){	cout << "~MultiplyNode()" << endl;	}

	virtual double calc() const;
};

class DivideNode : public BinaryNode{
public:
	DivideNode(Node * left, Node * right)
	: BinaryNode(left, right)
	{
		cout << "DivideNode(Node *, Node *)" << endl;
	}

	~DivideNode(){	cout << "~DivideNode()" << endl;	}

	virtual	double calc() const;
};
#endif

#endif
