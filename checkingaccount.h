#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H


class CheckingAccount
{
private:
    double checkingBalance;
    double amount;
public:
    CheckingAccount();
    void setDeposit(double amount);
    double getDeposit();
    void setWithdraw(double amount);
    double getWithdraw();
    double getCheckingBalance();
    ~CheckingAccount();
};

#endif // CHECKINGACCOUNT_H
