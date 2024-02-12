#include "account_manager.h"

account_manager::account_manager() : current_account(nullptr) {

}

void account_manager::Login() {
    while (true) {
        int id;
        std::string pass;
        std::cout << "Enter id (no spaces): ";
        std::cin >> id;
        std::cout << "Enter password (no spaces): ";
        std::cin >> pass;
        if (!accounts.count(id)) {
            std::cout << "\nInvalid user id number or password. Try again\n\n";
            continue;
        }
        account *account_exist = accounts.find(id)->second;
        if (pass != account_exist->Get_password()) {
            std::cout << "\nInvalid user user_name or password. Try again\n\n";
            continue;
        }
        current_account = account_exist;
        break;
    }
}

account_manager::~account_manager() {
    for (auto [id, account]: accounts) {
        delete account;
    }
    accounts.clear();
    current_account = nullptr;
}
