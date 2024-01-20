#include <iostream>
#include "sql_query_builder.h"

using namespace std;

typedef pair <string, string> Str_Pair;

void SendQuery(const SqlSelectQuery& e) {
	cout << e.query << endl;
}

int main() {
	AdvancedSqlSelectQueryBuilder query_builder;
	map<string, string> where;
	vector<string> columns;
	where.insert(Str_Pair("id", "42"));
	columns.push_back("name");
	columns.push_back("phone");
	query_builder.AddColumn(columns);
	query_builder.AddFrom("students");
	query_builder.AddWhereCond(where, ">");

	//static_assert(query_builder.BuildQuery(), "SELECT name, phone FROM students WHERE id>42;");
	SendQuery(query_builder.BuildQuery());
	system("pause");
}