
#include "account.h"

account::account() : password(""), balance(0), id(++current_id) {

}

int account::current_id = 0;

const int &account::Get_id() const {
    return id;
}

const int &account::Get_balance() const {
    return balance;
}

const std::string &account::Get_user_name() const {
    return user_name;
}

const std::string &account::Get_password() const {
    return password;
}

void account::Set_id(int id) {
    this->id = id;
}

void account::Set_balance(int balance) {
    this->balance = balance;
}

void account::Set_password(std::string password) {
    this->password = password;
}

void account::Set_user_name(std::string user_name) {
    this->user_name = user_name;
}

bool account::withdraw(int value) {
    if (available_to_use(value)) {
        std::cout << "\t\tCash Withdraw Successful\n";
        return true;
    } else {
        std::cout << "\t\tCash Withdraw Fail\n";
        return false;
    }
}

const bool account::available_to_use(int &value) const {
    return balance >= value;
}

void account::deposit(int value) {
    balance += value;
}
