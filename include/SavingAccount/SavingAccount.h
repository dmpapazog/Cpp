#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include "../BankAccount/BankAccount.h"

class SavingAccount : public BankAccount
{
  private:
    float interest;

  public:
    SavingAccount(const float &amount, const float &interest);

    // time: the time (in years) of the balance being closed
    float finalAmount(const float &timeDue) const;
};

#endif // SAVINGACCOUNT_H