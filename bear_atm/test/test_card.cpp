#include <gtest/gtest.h>

#include "bear_atm/account.hpp"
#include "bear_atm/card.hpp"

// Test for Card class
TEST(CardTest, AddAndRemoveAccount) {
    BearATM::Card card("TestBank", "TestUser", "1234");

    auto account1 = std::make_shared<BearATM::Account>("TestBank", "TestUser", "123456789", 1000);
    auto account2 = std::make_shared<BearATM::Account>("TestBank", "TestUser", "987654321", 2000);

    // Test adding accounts
    EXPECT_TRUE(card.addAccount(account1));
    EXPECT_TRUE(card.addAccount(account2));
    EXPECT_FALSE(card.addAccount(account1));  // Duplicate account

    // Test retrieving accounts
    auto retrievedAccount = card.getAccount("123456789");
    ASSERT_NE(retrievedAccount, nullptr);
    EXPECT_EQ(retrievedAccount->balance(), 1000);

    // Test removing accounts
    EXPECT_TRUE(card.removeAccount("123456789"));
    EXPECT_FALSE(card.removeAccount("123456789"));  // Already removed
    EXPECT_EQ(card.getAccount("123456789"), nullptr);
}