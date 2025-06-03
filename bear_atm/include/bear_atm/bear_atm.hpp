#ifndef BAER_ATM_BAER_ATM_HPP
#define BAER_ATM_BAER_ATM_HPP

#include <memory>
#include <string>
#include <vector>

#include "bear_atm/account.hpp"
#include "bear_atm/bank.hpp"
#include "bear_atm/card.hpp"

namespace BearATM {
class BearATM {
public:
    BearATM() = default;
    bool makeCard(const std::string &bank_name, const std::string &user_name, const std::string &pin_number);
    bool addAccount(const std::string &account_number, uint64_t balance);

    bool removeAccount(const std::string &account_number);
    bool insertCard(const std::shared_ptr<Card> &card);
    bool ejectCard();
    bool selectAccount(const std::string &account_number);
    bool deposit(const uint64_t &dollars);
    bool withdraw(const uint64_t &dollars);
    bool addBank(const std::string &name, const std::shared_ptr<Bank> &bank);
    bool verifyPin(const std::string &pin_number);

    uint64_t getBalance();

private:
    std::shared_ptr<Card> current_card_;
    std::shared_ptr<Account> current_account_;
    std::unordered_map<std::string, std::shared_ptr<Bank>> banks_;
};
}  // namespace BearATM

#endif  // BAER_ATM_BAER_ATM_HPP