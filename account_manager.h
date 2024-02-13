#ifndef BANK_MANAGEMENT_SYSTEM_ACCOUNT_MANAGER_H
#define BANK_MANAGEMENT_SYSTEM_ACCOUNT_MANAGER_H
#include "account.h"
#include "SQLiteDB.h"
#include <map>
class account_manager {
private:
    account *current_account;
public:
    account_manager();
    void Login();
    void SignUp();
    void AccessSystem();
    void View();
    void Withdraw();
    void Deposit_money();
    void Send();
    void LoadDatabase();
    ~account_manager();
};


#endif
