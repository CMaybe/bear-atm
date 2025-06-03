#include "bear_atm/card.hpp"

namespace BearATM {
Card::Card(const std::string &bank_name, const std::string &user_name, const std::string &pin_number)
    : bank_name_(bank_name), user_name_(user_name), pin_number_(pin_number) {}

bool Card::addAccount(const std::shared_ptr<Account> &account) {
    if (accounts_.find(account->account_number()) != accounts_.end()) {
        return false;
    }
    accounts_[account->account_number()] = account;
    return true;
}

bool Card::removeAccount(const std::string &account_number) { return accounts_.erase(account_number) > 0; }

std::shared_ptr<Account> Card::getAccount(const std::string &account_number) const {
    auto it = accounts_.find(account_number);
    if (it != accounts_.end()) {
        return it->second;
    }
    return nullptr;
}

bool Card::operator==(const Card &other) const {
    return bank_name_ == other.bank_name_ && user_name_ == other.user_name_ && pin_number_ == other.pin_number_;
}
}  // namespace BearATM