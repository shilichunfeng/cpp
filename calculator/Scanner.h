 ///
 /// @file    Scanner.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-13 12:39:26
 ///
 
#ifndef __WANGDAO_SCANNER_H__
#define __WANGDAO_SCANNER_H__

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

enum EToken{
	TOKEN_END,
	TOKEN_ERROR,
	TOKEN_NUMBER,
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_MULTIPLY,
	TOKEN_DIVIDE,
	TOKEN_LPARENTHESIS,
	TOKEN_RPARENTHESIS,
	TOKEN_IDENTIFIER,
	TOKEN_ASSIGN
};

class Scanner{
public:
	Scanner(const string & expr);

	void scan();
	double number() const;
	EToken token() const;

private:
	void skipBlank();

private:
	const string _expr;
	unsigned int _curPos;
	EToken       _token;
	double       _number;
};

#endif
