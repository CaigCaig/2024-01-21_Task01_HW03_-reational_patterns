#include "sql_query_builder.h"

SqlSelectQuery SqlSelectQueryBuilder::BuildQuery() noexcept {
	string comma = ", ";
	string str_and = " AND ";
	sql_select_query.query = "SELECT ";
	if (sql_select_query.columns.size()) {
		for (const auto& i : sql_select_query.columns) { sql_select_query.query += i + comma; }
		sql_select_query.query.erase(sql_select_query.query.length() - comma.length(), comma.length());
	}
	else sql_select_query.query += "*";
	sql_select_query.query += " FROM " + sql_select_query.from + " WHERE ";
	for (const auto& i : sql_select_query.where) { sql_select_query.query += i.first + "=" + i.second + str_and; }
	sql_select_query.query.erase(sql_select_query.query.length() - str_and.length(), str_and.length());
	sql_select_query.query += ";";
	return sql_select_query;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const vector<string>& columns) noexcept {
	for (const auto& i : columns) { sql_select_query.columns.push_back(i); }
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const string& from) noexcept {
	sql_select_query.from = from;
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const map<string, string>& kv) noexcept {
	sql_select_query.where = kv;
	return *this;
}

SqlSelectQuery AdvancedSqlSelectQueryBuilder::BuildQuery() noexcept {
	string comma = ", ";
	string str_and = " AND ";
	sql_select_query.query = "SELECT ";
	if (sql_select_query.columns.size()) {
		for (const auto& i : sql_select_query.columns) { sql_select_query.query += i + comma; }
		sql_select_query.query.erase(sql_select_query.query.length() - comma.length(), comma.length());
	}
	else sql_select_query.query += "*";
	sql_select_query.query += " FROM " + sql_select_query.from + " WHERE ";
	for (const auto& i : sql_select_query.where) { sql_select_query.query += i.first + condition + i.second + str_and; }
	sql_select_query.query.erase(sql_select_query.query.length() - str_and.length(), str_and.length());
	sql_select_query.query += ";";
	return sql_select_query;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereCond(const map<string, string>& kv, string cond) noexcept {
	sql_select_query.where = kv;
	condition = cond;
	return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddColumn(const vector<string>& columns) noexcept {
	for (const auto& i : columns) { sql_select_query.columns.push_back(i); }
	return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddFrom(const string& from) noexcept {
	sql_select_query.from = from;
	return *this;
}

/*

Реализуйте потомок класса SqlSelectQueryBuilder, который сможет добавлять в условие FROM запроса дополнительные операторы «больше» и «меньше». Пример кода с таким классом:

AdvancedSqlSelectQueryBuilder query_builder;
query_builder.AddColumns({"name", "phone"});
query_builder.AddFrom("students");
query_builder.<SomeMethod>(...); // Добавляем условие id > 42
static_assert(query_builder.BuildQuery(),
				"SELECT name, phone FROM students WHERE id>42;");

*/