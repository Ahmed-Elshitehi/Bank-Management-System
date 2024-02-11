#ifndef BANK_MANAGEMENT_SYSTEM_ACCOUNT_H
#define BANK_MANAGEMENT_SYSTEM_ACCOUNT_H
#include <iostream>
class account {
private:
    int id;
    std::string password;
    int balance;
public:
    account();
    void set_id(int id);
    void set_balance(int balance);
    void set_password(std::string password);
    const int &Get_id() const;
    const int &Get_balance() const;
    const std::string &Get_password() const;
};


#endif
