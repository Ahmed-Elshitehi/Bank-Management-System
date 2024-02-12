#ifndef BANK_MANAGEMENT_SYSTEM_ACCOUNT_MANAGER_H
#define BANK_MANAGEMENT_SYSTEM_ACCOUNT_MANAGER_H
#include "account.h"
#include <map>
class account_manager {
private:
    account *current_account;
    std::map<int, account *> accounts; // id, account
public:
    account_manager();
    void Login();
    void SignUp();
    void LoadDatabase();

};


#endif
