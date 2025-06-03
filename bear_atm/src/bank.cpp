#include "bear_atm/bank.hpp"

namespace BearATM {
Bank::Bank(const std::string& name) : name_(name) {}

bool Bank::makeCard(const std::string& name, const int& pin) {
    for (const auto& card : cards_) {
        if (card->user_name() == name) {
            return false;
        }
    }
    auto card = std::make_shared<Card>(name_, name, std::to_string(pin));
    cards_.push_back(card);
    return true;
}
bool Bank::addAccount(const std::string& user_name, const std::string& account_number, uint64_t balance) {
    for (const auto& card : cards_) {
        if (card->user_name() == user_name) {
            auto account = std::make_shared<Account>(name_, user_name, account_number, balance);
            return card->addAccount(account);
        }
    }
    return false;
}

bool Bank::removeAccount(const std::string& user_name, const std::string& account_number) {
    for (const auto& card : cards_) {
        if (card->user_name() == user_name) {
            return card->removeAccount(account_number);
        }
    }
    return false;
}
}  // namespace BearATM