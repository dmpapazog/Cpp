#include "BankAccount.h"

BankAccount::BankAccount()
{
    balance = 0;
}

BankAccount::BankAccount(const float &amaount)
{
    balance = amaount;
}

void BankAccount::deposit(const float &amount)
{
    balance += amount;
}

float BankAccount::withdraw(const float &amount)
{
    if (amount <= balance)
    {
        balance -= amount;
        return amount;
    }
    else
    {
        return -1;
    }
}

float BankAccount::getBalance() const
{
    return balance;
}