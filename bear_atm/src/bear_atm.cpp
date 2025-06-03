#include "bear_atm/bear_atm.hpp"

namespace BearATM {
bool BearATM::makeCard(const std::string &bank_name, const std::string &user_name, const std::string &pin_number) {
    auto bank = banks_.find(bank_name);
    if (bank != banks_.end()) {
        return bank->second->makeCard(user_name, pin_number);
    }
    return false;
}

bool BearATM::addAccount(const std::string &account_number, uint64_t balance) {
    if (!current_card_) {
        return false;
    }
    auto bank_name = current_card_->bank_name();
    auto user_name = current_card_->user_name();
    if (current_card_->addAccount(std::make_shared<Account>(bank_name, user_name, account_number, balance)) == false) {
        return false;
    }
    return true;
}

bool BearATM::removeAccount(const std::string &account_number) {
    if (!current_card_) {
        return false;
    }
    if (current_card_->removeAccount(account_number)) {
        if (current_account_ && current_account_->account_number() == account_number) {
            current_account_.reset();
        }
        return true;
    }
    return false;
}

bool BearATM::insertCard(const std::shared_ptr<Card> &card) {
    if (current_card_) {
        return false;
    }
    current_card_ = card;
    return true;
}

bool BearATM::ejectCard() {
    if (!current_card_) {
        return false;
    }
    current_card_.reset();
    return true;
}

bool BearATM::selectAccount(const std::string &account_number) {
    if (!current_card_) {
        return false;
    }
    auto account = current_card_->getAccount(account_number);
    if (account) {
        current_account_ = account;
        return true;
    }
    return false;
}

bool BearATM::deposit(const uint64_t &dollars) {
    if (!current_account_) {
        return false;
    }
    return current_account_->deposit(dollars);
}

bool BearATM::withdraw(const uint64_t &dollars) {
    if (!current_account_) {
        return false;
    }
    return current_account_->withdraw(dollars);
}

uint64_t BearATM::getBalance() {
    if (!current_account_) {
        return 0;
    }
    return current_account_->balance();

    return 0;
}

bool BearATM::addBank(const std::string &name, const std::shared_ptr<Bank> &bank) {
    if (banks_.find(name) != banks_.end()) {
        return false;
    }
    banks_[name] = bank;
    return true;
}

bool BearATM::verifyPin(const std::string &pin_number) {
    if (!current_card_) {
        return false;
    }

    auto bank = banks_.find(current_card_->bank_name());
    if (bank != banks_.end()) {
        return bank->second->verifyPin(pin_number);
    }
    return false;
}
}  // namespace BearATM
