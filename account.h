#ifndef BANK_MANAGEMENT_SYSTEM_ACCOUNT_H
#define BANK_MANAGEMENT_SYSTEM_ACCOUNT_H
#include <iostream>
class account {
private:
    int id;
    std::string password;
    std::string user_name;
    int balance;
    static int current_id;
    const bool available_to_use(int &value) const;
public:
    account();
    void Set_id(int id);
    void Set_balance(int balance);
    void Set_password(std::string password);
    void Set_user_name(std:: string);
    const int &Get_id() const;
    const int &Get_balance() const;
    const std::string &Get_user_name() const;
    const std::string &Get_password() const;
    bool withdraw(int value);
    void deposit(int value);
};


#endif
