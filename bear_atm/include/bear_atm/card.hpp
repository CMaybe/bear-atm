#ifndef BEAR_ATM_CARD_HPP
#define BEAR_ATM_CARD_HPP

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "bear_atm/account.hpp"
namespace BearATM {
class Card {
public:
    Card() = default;
    explicit Card(const std::string &bank_name, const std::string &user_name, const std::string &pin_number);

    inline std::string bank_name() const { return bank_name_; };
    inline std::string user_name() const { return user_name_; };
    inline std::string pin_number() const { return std::to_string(pin_number_); };

    bool addAccount(const std::shared_ptr<Account> &account);
    bool removeAccount(const std::string &account_number);
    std::shared_ptr<Account> getAccount(const std::string &account_number) const;

private:
    std::string bank_name_;
    std::string user_name_;
    uint64_t pin_number_;
    std::unordered_map<std::string, std::shared_ptr<Account>> accounts_;
};
}  // namespace BearATM

#endif  // CARD_HPP