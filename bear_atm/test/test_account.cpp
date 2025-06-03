#include <gtest/gtest.h>

#include "bear_atm/account.hpp"
#include "bear_atm/bank.hpp"
#include "bear_atm/bear_atm.hpp"
#include "bear_atm/card.hpp"

// Test for Account class
TEST(AccountTest, DepositTest) {
    BearATM::Account account("TestBank", "TestUser", "123456789", 1000);

    // Test successful deposit
    EXPECT_TRUE(account.deposit(500));
    EXPECT_EQ(account.balance(), 1500);

    // Test deposit overflow
    EXPECT_FALSE(account.deposit(std::numeric_limits<uint64_t>::max()));
    EXPECT_EQ(account.balance(), 1500);  // Balance should remain unchanged
}

TEST(AccountTest, WithdrawTest) {
    BearATM::Account account("TestBank", "TestUser", "123456789", 1000);

    // Test successful withdrawal
    EXPECT_TRUE(account.withdraw(500));
    EXPECT_EQ(account.balance(), 500);

    // Test withdrawal exceeding balance
    EXPECT_FALSE(account.withdraw(1000));
    EXPECT_EQ(account.balance(), 500);  // Balance should remain unchanged
}
