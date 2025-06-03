#ifndef BANK_HPP
#define BANK_HPP

#include <memory>
#include <string>
#include <vector>

#include "bear_atm/account.hpp"
#include "bear_atm/card.hpp"

namespace BearATM {
class Bank {
public:
    Bank() = default;
    explicit Bank(const std::string& name);
    bool makeCard(const std::string& name, const std::string& pin);
    bool verifyPin(const std::string& pin) const;
    inline std::string name() const { return name_; }

private:
    const std::string name_;
    std::vector<std::shared_ptr<Card>> cards_;
};
}  // namespace BearATM

#endif  // BEAR_ATM_BANK_HPP