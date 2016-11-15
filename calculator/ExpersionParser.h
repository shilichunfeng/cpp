 ///
 /// @file    ExpersionParser.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-13 13:52:16
 ///
 
#ifndef __WANGDAO_EXPRESSION_PARSER_H__
#define __WANGDAO_EXPRESSION_PARSER_H__
#include <iostream>
using std::cout;
using std::endl;

enum Status{
	STATUS_OK,
	STATUS_ERROR,
	STATUS_QUIT
};

class Node;
class Scanner;

class ExpressionParser{
public:
	ExpressionParser(Scanner & scanner);
	~ExpressionParser();
	void parse();
	double calculate() const;

	Node * expr();
	Node * term();
	Node * factor();

private:
	Scanner & _scanner;
	Node *    _root;
	Status    _status;
};

#endif
