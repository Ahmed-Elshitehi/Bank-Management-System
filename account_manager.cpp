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

void account_manager::SignUp() {
    current_account = new account;
    std::string str;
    std::cout << "Enter user name (No spaces): ";
    std::cin >> str;
    current_account->Set_user_name(str);
    std::cout << "Enter password (no spaces): ";
    std::cin >> str;
    current_account->Set_password(str);
    std::cout << "your ID : " << current_account->Get_id() << '\n';
    accounts[current_account->Get_id()] = current_account;
}
