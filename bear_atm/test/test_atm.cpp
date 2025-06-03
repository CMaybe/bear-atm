#include <gtest/gtest.h>

#include "bear_atm/account.hpp"
#include "bear_atm/bank.hpp"
#include "bear_atm/bear_atm.hpp"
#include "bear_atm/card.hpp"

TEST(ATMTest, FullATMWorkflow) {
    auto bank = std::make_shared<BearATM::Bank>("TestBank");
    BearATM::BearATM atm;

    // Add the bank to the ATM
    EXPECT_TRUE(atm.addBank("TestBank", bank));

    auto card = std::make_shared<BearATM::Card>("TestBank", "TestUser", "1234");

    // Insert the card into the ATM
    EXPECT_TRUE(atm.insertCard(card));

    // Create a Account and add it to the card
    EXPECT_TRUE(atm.addAccount("123456789", 1000));
    // Verify the PIN
    EXPECT_FALSE(atm.verifyPin("1234"));
    EXPECT_FALSE(atm.verifyPin("5678"));  // Incorrect PIN

    // Select an account
    EXPECT_TRUE(atm.selectAccount("123456789"));
    EXPECT_FALSE(atm.selectAccount("987654321"));  // Non-existent account

    // Check the balance
    EXPECT_EQ(atm.getBalance(), 1000);

    // Deposit money
    EXPECT_TRUE(atm.deposit(500));
    EXPECT_EQ(atm.getBalance(), 1500);

    // Withdraw money
    EXPECT_TRUE(atm.withdraw(300));
    EXPECT_EQ(atm.getBalance(), 1200);

    // Attempt to withdraw more than the balance
    EXPECT_FALSE(atm.withdraw(2000));
    EXPECT_EQ(atm.getBalance(), 1200);

    // Eject the card
    EXPECT_TRUE(atm.ejectCard());
    EXPECT_FALSE(atm.ejectCard());  // No card to eject
}

TEST(ATMTest, InsertCardTwice) {
    BearATM::BearATM atm;

    auto card = std::make_shared<BearATM::Card>("TestBank", "TestUser", "1234");

    // Insert the card into the ATM
    EXPECT_TRUE(atm.insertCard(card));

    // Attempt to insert another card without ejecting the first one
    EXPECT_FALSE(atm.insertCard(card));

    // Eject the card
    EXPECT_TRUE(atm.ejectCard());
}

TEST(ATMTest, NoCardInserted) {
    BearATM::BearATM atm;

    // Attempt to verify PIN without a card
    EXPECT_FALSE(atm.verifyPin("1234"));

    // Attempt to select an account without a card
    EXPECT_FALSE(atm.selectAccount("123456789"));

    // Attempt to deposit money without a card
    EXPECT_FALSE(atm.deposit(500));

    // Attempt to withdraw money without a card
    EXPECT_FALSE(atm.withdraw(300));

    // Attempt to check balance without a card
    EXPECT_EQ(atm.getBalance(), 0);
}