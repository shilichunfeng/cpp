 ///
 /// @file    ExpressionParser.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-13 13:55:24
 ///
 
#include "ExpersionParser.h"
#include "Node.h"
#include "Scanner.h"

#include <assert.h>
#include <iostream>

using std::cout;
using std::endl;


ExpressionParser::ExpressionParser(Scanner & scanner)
: _scanner(scanner)
, _root(nullptr)
, _status(STATUS_OK)
{}

ExpressionParser::~ExpressionParser(){
	delete _root;
}

void ExpressionParser::parse(){
	_root = expr();
}

double ExpressionParser::calculate()const{
	assert(_root != nullptr);
	if(_status == STATUS_OK)
		return _root->calc();
	else
		return 0;
}

#if 1
Node * ExpressionParser::expr(){
	Node * node = term();
	EToken etoken = _scanner.token();
	if(etoken == TOKEN_PLUS || etoken == TOKEN_MINUS){
		MultipleNode * multiNode = new SumNode(node);
		do{
			_scanner.scan();
			Node * nextNode = term();
			multiNode->appendChild(nextNode, (etoken == TOKEN_PLUS));
			etoken = _scanner.token();
		}while(etoken == TOKEN_PLUS || etoken == TOKEN_MINUS);
		node = multiNode;
	}
	
	return node;
}

Node * ExpressionParser::term(){
	Node * node = factor();
	EToken etoken = _scanner.token();
	if(TOKEN_MULTIPLY == etoken || TOKEN_DIVIDE == etoken){
		MultipleNode * multiNode = new ProductNode(node);
		do{
			_scanner.scan();
			Node * nextNode = factor();
			multiNode->appendChild(nextNode,(etoken == TOKEN_MULTIPLY)); 
			etoken = _scanner.token();
		}while(etoken == TOKEN_MULTIPLY||etoken == TOKEN_DIVIDE);
		node = multiNode;
	}

	return node;
}
#endif

#if 0
Node * ExpressionParser::expr(){
	Node * node = term();
	EToken etoken = _scanner.token();
	if(TOKEN_PLUS == etoken){	
		_scanner.scan();//向后
		Node * right = expr();
		node = new AddNode(node, right);
	}
	else if(TOKEN_MINUS == etoken)
	{
		_scanner.scan();//向后
		Node * right = expr();
		node = new SubNode(node, right);
	}
	return node;
}

Node * ExpressionParser::term(){
	Node * node = factor();
	EToken etoken = _scanner.token();
	if(TOKEN_MULTIPLY == etoken){
		_scanner.scan();//向后
		Node * right = term();
		node = new MultiplyNode(node, right);
	}
	else if(TOKEN_DIVIDE == etoken){
		_scanner.scan();
		Node * right = term();
		node = new DivideNode(node, right);
	}
	return node;
}
#endif

Node * ExpressionParser::factor(){
	Node * node = nullptr;
	EToken etoken = _scanner.token();
	if(TOKEN_LPARENTHESIS == etoken){
		_scanner.scan();//向后扫描
		node = expr();
		if(_scanner.token() == TOKEN_RPARENTHESIS){
			_scanner.scan();//向后
		}
		else{
			_status = STATUS_ERROR;
			//处理异常
			cout << "missing parenthesis" << endl;
			node = nullptr;
		}
	}
	else if(TOKEN_NUMBER == etoken){
		node = new NumberNode(_scanner.number());
		_scanner.scan();//向后
	}
	else if(TOKEN_MINUS == etoken){
		_scanner.scan();//这句必须在前面
		node = new UminusNode(factor());
	}
	else{
		_status = STATUS_ERROR;
		cout << "it is not a valid expression!" << endl;
		node = nullptr;
	}
	return node;
}

















