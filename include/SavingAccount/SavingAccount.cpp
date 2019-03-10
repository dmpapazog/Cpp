#include "SavingAccount.h"

SavingAccount::SavingAccount(const float &amount, const float &interest) : BankAccount(amount)
{
    this->interest = interest;
}

float SavingAccount::finalAmount(const float &timeDue) const
{
    return balance + balance * interest * timeDue;
}