#include "SQLiteDB.h"

SQLiteDB::SQLiteDB(const char* filename) : db(nullptr) {
    int rc = sqlite3_open(filename, &db);
    if (rc != SQLITE_OK) {
        std::cout << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        db = nullptr;
    }
}

SQLiteDB::~SQLiteDB() {
    if (db != nullptr) {
        sqlite3_close(db);
        db = nullptr;
    }
}

bool SQLiteDB::executeQuery(const char *query) {
    char* errorMessage = nullptr;
    int rc = sqlite3_exec(db, query, nullptr, nullptr, &errorMessage);
    if (rc != SQLITE_OK) {
        std::cerr << "Error executing SQL query: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        return false;
    }
    return true;
}

bool SQLiteDB::insertData(const char *tableName, const std::vector<std::string> &values) {
    std::string query = "INSERT INTO ";
    query += tableName;
    query += " (\"name\", \"password\", \"balance\")";
    query += " VALUES (";
    for (size_t i = 0; i < values.size(); ++i) {
        if (i > 0) query += ", ";
        query += "'";
        query += values[i];
        query += "'";
    }
    query += ");";
    return executeQuery(query.c_str());
}

std::vector<std::vector<std::string>> SQLiteDB::selectData(const char *tableName, const int id) {
    std::vector<std::vector<std::string>> result;
    std::string query = "SELECT * FROM ";
    query += tableName;
    query += " WHERE \"ID\" = '";
    query += std::to_string(id);
    query += "' ;";
    sqlite3_stmt* statement;
    int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &statement, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
        return result;
    }

    while ((rc = sqlite3_step(statement)) == SQLITE_ROW) {
        std::vector<std::string> row;
        int columns = sqlite3_column_count(statement);
        for (int i = 0; i < columns; ++i) {
            row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(statement, i)));
        }
        result.push_back(row);
    }

    sqlite3_finalize(statement);
    return result;
}

bool SQLiteDB::updateData(const char *tableName, const char *columnName, const char *columnValue, const int id) {
    std::string query = "UPDATE ";
    query += tableName;
    query += " SET ";
    query += columnName;
    query += " = '";
    query += columnValue;
    query += "' WHERE \"ID\" = ";
    query += std::to_string(id);
    query += ";";
    return executeQuery(query.c_str());
}

int SQLiteDB::getMaxID(const char *tableName) {
    std::string query = "SELECT MAX(ID) FROM ";
    query += tableName;
    query += ";";
    sqlite3_stmt* statement;
    int maxID = 0;
    int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &statement, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
        return maxID;
    }

    if (sqlite3_step(statement) == SQLITE_ROW) {
        maxID = sqlite3_column_int(statement, 0);
    }

    sqlite3_finalize(statement);
    return maxID;
}
