#include<iostream>
using std::cout;
using std::ostream;

class BankAccount {
    private:
        int accountNumber;
        float balance;
    public:
        BankAccount() : accountNumber(0), balance(0) {};
        BankAccount(int a, float b) : accountNumber(a), balance(b) {};
        int getAccountNumber() const {return accountNumber;}
        float getBalance() const {return balance;}
        void withdraw(float amount) {balance -= amount;}
        void deposit(float amount) {balance += amount;}
        friend ostream& operator << (ostream& outs, const BankAccount& account);
};

ostream& operator << (ostream& outs, const BankAccount& account) {
    outs << "The balance for the account: " << account.accountNumber << " is: " << account.balance << ". \n";
    return outs;
}

int main() {
    BankAccount test(12345, 100);
    cout << test;
    test.deposit(1234.45);
    cout << test;
    return 0;
}