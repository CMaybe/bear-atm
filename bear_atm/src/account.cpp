#include "bear_atm/account.hpp"

#include <limits>

BearATM::Account::Account(const std::string& bank_name,
                          const std::string& user_name,
                          const std::string& account_number,
                          uint64_t balance)
    : bank_name_(bank_name), user_name_(user_name), account_number_(account_number), balance_(balance) {}

bool BearATM::Account::deposit(const uint64_t& dollars) {
    if (dollars > std::numeric_limits<uint64_t>::max() - balance_) {
        return false;
    }

    balance_ += dollars;
    return true;
}

bool BearATM::Account::withdraw(const uint64_t& dollars) {
    if (dollars > balance_) {
        return false;
    }

    balance_ -= dollars;
    return true;
}
bool BearATM::Account::operator==(const Account& other) const { return account_number_ == other.account_number_; }