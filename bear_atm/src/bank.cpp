#include "bear_atm/bank.hpp"

namespace BearATM {
Bank::Bank(const std::string& name) : name_(name) {}

bool Bank::makeCard(const std::string& name, const std::string& pin) {
    for (const auto& card : cards_) {
        if (card->user_name() == name) {
            return false;
        }
    }
    auto card = std::make_shared<Card>(name_, name, pin);
    cards_.push_back(card);
    return true;
}

bool Bank::verifyPin(const std::string& pin) const {
    for (const auto& card : cards_) {
        if (card->pin_number() == pin) {
            return true;
        }
    }
    return false;
}

}  // namespace BearATM