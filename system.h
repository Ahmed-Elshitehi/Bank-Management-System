#ifndef BANK_MANAGEMENT_SYSTEM_SYSTEM_H
#define BANK_MANAGEMENT_SYSTEM_SYSTEM_H

#include "account_manager.h"
class system {
private:
    account_manager *accountManager;
public:
    system();
    void Run();
    ~system();
};


#endif