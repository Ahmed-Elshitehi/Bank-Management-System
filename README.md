# Bank Management System

## Overview
This console-based application is a simple bank management system implemented in C++. It allows users to perform various operations related to managing accounts such as logging in, signing up, withdrawing money, and transferring money between accounts. The system utilizes SQLite3 as the database management system to store account information.

## Features
- **Account Management**: Users can create new accounts, log in to existing accounts, and manage their account details.
- **Transaction Operations**: Users can withdraw money from their accounts and transfer money between accounts.
- **Secure Authentication**: User authentication is implemented using a username-password combination stored in the database.
- **Database Integration**: SQLite3 is used as the backend database to store account information securely.


## Usage
- **Logging In**: Users can log in using their account ID and password.
- **Signing Up**: New users can create an account by providing their details.
- **Withdrawal**: Users can withdraw money from their account balance.
- **Transfer**: Users can transfer money between their accounts.

## Database Schema
The SQLite3 database contains a single table named `accounts` with the following schema:
```SQL 
CREATE TABLE accounts (
id INTEGER PRIMARY KEY,
name TEXT NOT NULL,
password TEXT NOT NULL,
balance REAL
);
```


## Dependencies
- **SQLite3**: The system relies on SQLite3 for database management. Ensure that the SQLite3 library is installed on your system.
- Download source code from [here](https://www.sqlite.org/download.html) and replace [sqlite](/sqlite) with it.  
## Contributing
Contributions are welcome! Feel free to submit pull requests or raise issues if you encounter any problems or have suggestions for improvements.
