 ///
 /// @file    Scanner.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-13 12:46:23
 ///
 
#include "Scanner.h"

#include <stdlib.h>

Scanner::Scanner(const string & expr)
: _expr(expr)
, _curPos(0)
, _token(TOKEN_ERROR)
{
	cout << "Scanner(const string &)" << endl;
	scan();
}
void Scanner::scan(){
	skipBlank();
	switch(_expr[_curPos]){
	case '+':
		{
		_token = TOKEN_PLUS;
		++_curPos;
		break;
		}
	case '-':
		{
		_token = TOKEN_MINUS;
		++_curPos;
		break;
		}
	case '*':
		{
		_token = TOKEN_MULTIPLY;
		++_curPos;
		break;
		}
	case '/':
		{
		_token = TOKEN_DIVIDE;
		++_curPos;
		break;
		}
	case '(':
		{
		_token = TOKEN_LPARENTHESIS;
		++_curPos;
		break;
		}
	case ')':
		{
		_token = TOKEN_RPARENTHESIS;
		++_curPos;
		break;
		}
	case '0':case '1':case '2':case '3': case '4':
	case '5':case '6':case '7':case '8': case '9':
	case '.':
		{
		_token = TOKEN_NUMBER;
		char * p = nullptr;
		_number = strtod(&_expr[_curPos], &p);
		_curPos = p - &_expr[0];
		break;
		}
	case '\0':case '\n':case '\r':case EOF:
		{
		_token = TOKEN_END;
		break;
		}
	default:
		{
		_token = TOKEN_ERROR;
		break;
		}
	}
}

double Scanner::number() const{
	return _number;
}

EToken Scanner::token() const{
	return _token;
}

void Scanner::skipBlank(){
	while(isspace(_expr[_curPos]))
		++_curPos;
}

