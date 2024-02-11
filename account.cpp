
#include "account.h"

account::account() : password(""), balance(0), id(0) {

}

const int &account::Get_id() const {
    return id;
}

const int &account::Get_balance() const {
    return balance;
}

const std::string &account::Get_password() const {
    return password;
}

void account::set_id(int id) {
    this->id = id;
}

void account::set_balance(int balance) {
    this->balance = balance;
}

void account::set_password(std::string password) {
    this->password = password;
}
