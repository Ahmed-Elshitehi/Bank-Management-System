#ifndef BANK_MANAGEMENT_SYSTEM_SQLITEDB_H
#define BANK_MANAGEMENT_SYSTEM_SQLITEDB_H

#include "sqlite/sqlite3.h"
#include <iostream>
#include <vector>
class SQLiteDB {
private:
private:
    sqlite3 *db;
public:
    SQLiteDB(const char *filename);
    ~SQLiteDB();
    bool executeQuery(const char *query);
    bool insertData(const char *tableName, const std::vector<std::string> &values);
    std::vector<std::vector<std::string>> selectData(const char* tableName, const int id);
    bool updateData(const char *tableName, const char *columnName, const char *columnValue, const int id);
    int getMaxID(const char* tableName);
};


#endif