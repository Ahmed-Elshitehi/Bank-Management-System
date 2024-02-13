#include "system.h"

system::system() : accountManager(new account_manager()) {

}

void system::Run() {
    while (true) {
        accountManager->AccessSystem();
    }
}

system::~system() {
    delete accountManager;
}