 ///
 /// @file    testQuery.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-09 15:51:49
 ///
 
#include "TextQuery.h"
#include "Query.h"
#include "WordQuery.h"
#include <iostream>
using std::cout;
using std::endl;

#if 0
class QueryParser
{
public:
	QueryParser(const string & query);
	Query parse();
private:
	string _query;
};
#endif

int main(void)
{
	TextQuery tq;
	tq.readFile("./data/data.txt");

	string s1 = "(fiery & bird)|wind";

	Query query = Query("fiery") & Query("bird") | Query("wind");

	set<int> ret = query.doQuery(tq);
	cout << "执行查询: " << query << endl; 

	showResult(tq, ret);
	return 0;
}
