#include "bear_atm/account.hpp"

#include <limits>
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