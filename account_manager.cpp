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

void account_manager::AccessSystem() {
    system("CLS");
    std::cout << "\n";
    std::cout << "\t1: Login\n";
    std::cout << "\t2: SignUP\n";
    std::cout << "\nEnter number in range " << "1 - 2: ";
    int choice;
    std::cin >> choice;
    if (choice == 1)
        Login();
    else
        SignUp();
}

void account_manager::Send() {
    int id;
    std::cout << "Enter Resever ID : ";
    std::cin >> id;
    std::cout << "Enter Amount of money : ";
    int amount;
    std::cin >> amount;
    if (current_account->available_to_use(amount)) {
        accounts[id]->Add_balance(amount);
        current_account->Reduse_balance(amount);
        std::cout << current_account->Get_user_name() << " Send " << amount << " to " << accounts[id]->Get_user_name()
                  << '\n';
    } else {
        std::cout << "You don't have enough money to Transfer to  " << accounts[id]->Get_user_name() << '\n';
    }
}

void account_manager::View() {
    system("CLS");
    int choice;
    std::cout << "\t1: View Profile\n";
    std::cout << "\t2: Withdraw\n";
    std::cout << "\t3: Transfer To\n";
    std::cout << "\t4: View Profile\n";
}

