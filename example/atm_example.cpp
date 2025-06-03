#include <iostream>
#include <memory>

#include "bear_atm/bear_atm.hpp"

int main() {
    BearATM::BearATM atm;

    // Example setup
    if (atm.addBank("BankA", std::make_shared<BearATM::Bank>("BankA"))) {
        std::cout << "Bank added successfully." << std::endl;
    } else {
        std::cerr << "Failed to add bank." << std::endl;
        return 1;
    }

    if (atm.makeCard("BankA", "User1", "1234")) {
        std::cout << "Card created successfully." << std::endl;
    } else {
        std::cout << "Failed to create card." << std::endl;
        return 1;
    }

    // Simulate inserting a card
    auto card = std::make_shared<BearATM::Card>("BankA", "User1", "1234");
    if (atm.insertCard(card)) {
        std::cout << "Card inserted successfully." << std::endl;
    } else {
        std::cout << "Failed to insert card." << std::endl;
        return 1;
    }

    if (atm.addAccount("111111111", 1000)) {
        std::cout << "Account added successfully." << std::endl;
    } else {
        std::cerr << "Failed to add account." << std::endl;
        return 1;
    }

    // Verify PIN
    if (atm.verifyPin("1234")) {
        std::cout << "PIN verified successfully." << std::endl;
    } else {
        std::cout << "Invalid PIN." << std::endl;
        return 1;
    }

    // Select account
    if (atm.selectAccount("111111111")) {
        std::cout << "Account selected successfully." << std::endl;
    } else {
        std::cout << "Failed to select account." << std::endl;
        return 1;
    }

    // Check balance
    std::cout << "Current balance: $" << atm.getBalance() << std::endl;

    // Deposit money
    if (atm.deposit(500)) {
        std::cout << "Deposit successful. New balance: $" << atm.getBalance() << std::endl;
    } else {
        std::cout << "Deposit failed." << std::endl;
    }

    // Withdraw money
    if (atm.withdraw(300)) {
        std::cout << "Withdrawal successful. New balance: $" << atm.getBalance() << std::endl;
    } else {
        std::cout << "Withdrawal failed." << std::endl;
    }

    // Eject card
    if (atm.ejectCard()) {
        std::cout << "Card ejected successfully." << std::endl;
    } else {
        std::cout << "Failed to eject card." << std::endl;
    }

    return 0;
}