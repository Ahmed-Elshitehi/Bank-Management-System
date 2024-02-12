
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

void account::Set_balance(int balance) {
    this->balance = balance;
}

void account::Set_password(std::string password) {
    this->password = password;
}

void account::Set_user_name(std::string user_name) {
    this->user_name = user_name;
}

void account::Add_balance(int value) {
    balance += value;
}

const bool account::available_to_use(int &value) const {
    return balance >= value;
}

void account::Reduse_balance(int value) {
    balance -= value;
}

void account::PrintInfo() {
    std::cout << "\n";
    std::cout << "user name : " << Get_user_name() << '\t' << "ID : " << Get_id() << '\n';
    std::cout << "Balance : " << Get_balance() << '\n';
}
