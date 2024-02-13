#include "system.h"

system::system() : accountManager(new account_manager()) {

}

void system::Run() {
    char choose;
    do {
        accountManager->AccessSystem();
        std::cout << "DO You need any another operations? (Y/N) :";
        std::cin >> choose;
    } while (toupper(choose) == 'Y');
}

system::~system() {
    delete accountManager;
}