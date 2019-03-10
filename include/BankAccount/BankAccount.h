#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount
{
  protected:
    float balance;

  public:
    BankAccount();
    BankAccount(const float &amount);

    void deposit(const float &amount);

    // returns -1 if the amount is greater than the account's balance
    float withdraw(const float &amount);
    float getBalance() const;
};

#endif // BANKACCOUNT_H