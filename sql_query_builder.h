#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct SqlSelectQuery {
    vector<string> columns;
    string from;
    map<string, string> where;
    string query;
};

class SqlSelectQueryBuilder {
private:
    SqlSelectQuery sql_select_query;
public:
    explicit SqlSelectQueryBuilder() {};
    virtual SqlSelectQuery BuildQuery() noexcept;
    virtual SqlSelectQueryBuilder& AddColumn(const vector<string>& columns) noexcept;
    virtual SqlSelectQueryBuilder& AddFrom(const string& from) noexcept;
    virtual SqlSelectQueryBuilder& AddWhere(const map<string, string>& kv) noexcept;

};

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder {
private:
    SqlSelectQuery sql_select_query;
    string condition;
public:
    SqlSelectQuery BuildQuery() noexcept override;
    AdvancedSqlSelectQueryBuilder& AddColumn(const vector<string>& columns) noexcept override;
    AdvancedSqlSelectQueryBuilder& AddFrom(const string& from) noexcept override;
    AdvancedSqlSelectQueryBuilder& AddWhereCond(const map<string, string>& kv, string cond) noexcept;
};