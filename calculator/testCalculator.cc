 ///
 /// @file    testCalculator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-13 16:45:00
 ///
 
#include "Scanner.h"
#include "ExpersionParser.h"
#include <unistd.h>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main(void){
	string expr;
	do{
		cout << "> ";
		getline(cin, expr);

		Scanner scanner(expr);
		ExpressionParser exprParser(scanner);
		exprParser.parse();
		cout << exprParser.calculate() << endl;
	}while(1);

	return 0;
}
