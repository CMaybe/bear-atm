#include <gtest/gtest.h>

#include "bear_atm/account.hpp"
#include "bear_atm/bank.hpp"
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

// Test for Bank class
TEST(BankTest, AddAndRemoveAccount) {
    BearATM::Bank bank("TestBank");

    // Create a card
    EXPECT_TRUE(bank.makeCard("TestUser", 1234));
    EXPECT_FALSE(bank.makeCard("TestUser", 1234));  // Duplicate card

    // Add accounts to the card
    EXPECT_TRUE(bank.addAccount("TestUser", "123456789", 1000));
    EXPECT_TRUE(bank.addAccount("TestUser", "987654321", 2000));
    EXPECT_FALSE(bank.addAccount("NonExistentUser", "111111111", 500));  // No card for this user

    // Remove accounts from the card
    EXPECT_TRUE(bank.removeAccount("TestUser", "123456789"));
    EXPECT_FALSE(bank.removeAccount("TestUser", "123456789"));         // Already removed
    EXPECT_FALSE(bank.removeAccount("NonExistentUser", "111111111"));  // No card for this user
}