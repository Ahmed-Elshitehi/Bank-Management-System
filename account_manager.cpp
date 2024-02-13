#include "account_manager.h"

account_manager::account_manager() : current_account(new account) {

}

void account_manager::Login() {
    while (true) {
        SQLiteDB db("../bank.db");
        int id;
        std::string pass;
        std::cout << "Enter id (no spaces): ";
        std::cin >> id;
        std::cout << "Enter password (no spaces): ";
        std::cin >> pass;
        std::vector<std::vector<std::string>> result = db.selectData("account", id);
        if (result[0][2] != pass) {
            std::cout << "\nInvalid user id number or password. Try again\n\n";
            continue;
        }
        current_account->Set_id(std::stoi(result[0][0]));
        current_account->Set_user_name(result[0][1]);
        current_account->Set_password(result[0][2]);
        current_account->Set_balance(std::stoi(result[0][3]));
        break;
    }
}

account_manager::~account_manager() {
    current_account = nullptr;
}

void account_manager::SignUp() {
    SQLiteDB db("../bank.db");
    std::string name,password;
    std::cout << "Enter user name (No spaces): ";
    std::cin >> name;
    current_account->Set_user_name(name);
    std::cout << "Enter password (no spaces): ";
    std::cin >> password;
    current_account->Set_password(password);
    db.insertData("account", {name, password, "0"});
    current_account->Set_id(db.getMaxID("account"));
    std::cout << "your ID : " << current_account->Get_id() << '\n';
}

void account_manager::AccessSystem() {
//    system("CLS");
    std::cout << "\n";
    std::cout << "\t1: Login\n";
    std::cout << "\t2: SignUP\n";
    std::cout << "\nEnter number in range " << "1 - 2: ";
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        Login();
        View();
        if (current_account == nullptr) {
            delete current_account;
            current_account = nullptr;
        }
    } else {
        SignUp();
    }
}

void account_manager::Withdraw() {
    std::cout << "Enter Amount of money : ";
    int amount;
    std::cin >> amount;
    if (current_account->available_to_use(amount)) {
        current_account->Reduse_balance(amount);
        std::cout << "Withdraw Done Successfully\n";
    } else {
        std::cout << "You don't have enough money to Withdraw.\n";
    }
    std::cout << "Your current balance is "
              << current_account->Get_balance() << '\n';
    SQLiteDB db("../bank.db");
    std::string b = std::to_string(current_account->Get_balance());
    db.updateData("account", "balance", b.c_str(), current_account->Get_id());
}

void account_manager::Deposit_money() {
    std::cout << "Enter Amount of money : ";
    int amount;
    std::cin >> amount;
    current_account->Add_balance(amount);
    std::cout << "Deposit Done Successfully\n"
              << "Your current balance is "
              << current_account->Get_balance() << '\n';

    SQLiteDB db("../bank.db");
    std::string b = std::to_string(current_account->Get_balance());
    db.updateData("account", "balance", b.c_str(), current_account->Get_id());
}

void account_manager::Send() {
    SQLiteDB db("../bank.db");
    int id;
    account rec;
    std::cout << "Enter the recipient ID : ";
    std::cin >> id;
    std::cout << "Enter Amount of money : ";
    int amount;
    std::cin >> amount;
    std::vector<std::vector<std::string>> result = db.selectData("account", id);
    rec.Set_id(std::stoi(result[0][0]));
    rec.Set_user_name(result[0][1]);
    rec.Set_password(result[0][2]);
    rec.Set_balance(std::stoi(result[0][3]));
    if (current_account->available_to_use(amount)) {
        rec.Add_balance(amount);
        current_account->Reduse_balance(amount);
        std::cout << current_account->Get_user_name() << " Send " << amount << " to " << rec.Get_user_name()
                  << '\n';
        std::string b = std::to_string(current_account->Get_balance());
        db.updateData("account", "balance", b.c_str(), current_account->Get_id());
        b = std::to_string(rec.Get_balance());
        db.updateData("account", "balance", b.c_str(), rec.Get_id());
    } else {
        std::cout << "You don't have enough money to Transfer \n";
    }
}

void account_manager::View() {
    std::cout << "\n\nHello " << current_account->Get_user_name() << '\n';
    while (true) {
        int choice;
        std::cout << "\t1: View Profile\n";
        std::cout << "\t2: Withdraw\n";
        std::cout << "\t3: Deposit money\n";
        std::cout << "\t4: Transfer To\n";
        std::cout << "\t5: Logout\n";
        std::cin >> choice;
        if (choice == 1) {
            current_account->PrintInfo();
        } else if (choice == 2) {
            Withdraw();
        } else if (choice == 3) {
            Deposit_money();
        } else if (choice == 4) {
            Send();
        } else {
            break;
        }
    }
}

