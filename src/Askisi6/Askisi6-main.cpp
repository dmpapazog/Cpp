#include <iostream>
#include "BankAccount/BankAccount.h"
#include "SavingAccount/SavingAccount.h"

using namespace std;

int main() {
    BankAccount A;
    BankAccount B(150);

    SavingAccount C(75, 2.85);

    A.deposit(50);
    B.deposit(60);

    if (A.withdraw(70) == -1) {
        cout << "Bank account A doesn't have 70 euros in its balance." << endl;
    } else
    {
        cout << "The withdrawal of 70 euros from bank account A was successful." << endl;
    }
    if (B.withdraw(70) == -1) {
        cout << "Bank account B doesn't have 70 euros in its balance." << endl;
    } else
    {
        cout << "The withdrawal of 70 euros from bank account B was successful." << endl;
    }
    
    cout << "The balance of bank account A is: " << A.getBalance() << " euros" << endl;
    cout << "The balance of bank account B is: " << B.getBalance() << " euros" << endl << endl;

    if (C.withdraw(30) == -1) {
        cout << "Bank account C doesn't have 70 euros in its balance." << endl;
    } else
    {
        cout << "The withdrawal of 70 euros from bank account C was successful." << endl;
    }    
    cout << "The balance of bank account C is: " << C.getBalance() << " euros" << endl;
    cout << "After 10 years the balance of account C will be " << C.finalAmount(10) << " euros" << endl;

    return 0;
}