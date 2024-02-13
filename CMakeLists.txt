cmake_minimum_required(VERSION 3.26)
project(Bank_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bank_Management_System main.cpp
        account.h
        account.cpp
        account_manager.h
        account_manager.cpp
        account_manager.h
        system.h
        system.cpp
        sqlite/sqlite3.h
        sqlite/sqlite3.c
        SQLiteDB.h
        SQLiteDB.cpp
)
