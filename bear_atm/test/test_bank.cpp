#include <gtest/gtest.h>

#include "bear_atm/account.hpp"
#include "bear_atm/bank.hpp"
#include "bear_atm/card.hpp"

// Test for Bank class
TEST(BankTest, MakeBank) {
    BearATM::Bank bank("TestBank");

    // Create a card
    EXPECT_TRUE(bank.makeCard("TestUser", "1234"));
    EXPECT_FALSE(bank.makeCard("TestUser", "1234"));    // Duplicate card
    EXPECT_TRUE(bank.makeCard("AnotherUser", "5678"));  // Another card

    // Verify the bank name
    EXPECT_EQ(bank.name(), "TestBank");
}

TEST(BankTest, VerifyPin) {
    BearATM::Bank bank("TestBank");

    // Create a card
    EXPECT_TRUE(bank.makeCard("TestUser", "1234"));

    // Verify PIN
    EXPECT_TRUE(bank.verifyPin("1234"));
    EXPECT_FALSE(bank.verifyPin("5678"));  // Incorrect PIN
}