#ifndef BEAR_ATM_ACCOUNT_HPP
#define BEAR_ATM_ACCOUNT_HPP

#include <string>

namespace BearATM {
class Account {
public:
    Account() = default;
    explicit Account(const std::string& bank_name,
                     const std::string& user_name,
                     const std::string& account_number,
                     uint64_t balance = 0);

    inline std::string bank_name() const { return bank_name_; };
    inline std::string user_name() const { return user_name_; };
    inline std::string account_number() const { return account_number_; }

    inline uint64_t balance() const { return balance_; }

    bool deposit(const uint64_t& dollars);
    bool withdraw(const uint64_t& dollars);
    bool operator==(const Account& other) const;

private:
    const std::string bank_name_;
    const std::string user_name_;
    const std::string account_number_;
    uint64_t balance_;
};
}  // namespace BearATM
#endif  // BEAR_ATM_ACCOUNT_HPP