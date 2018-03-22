#include "user.h"

User::User(QObject *parent) : QObject(parent)
{
    checkingAccountNumber = 12345;
    savingAccountNumber = 54321;
}


void User::setCheckingAccountNumber(int checkingAccountNumber)
{
    this->checkingAccountNumber = checkingAccountNumber;
}

int User::getCheckingAccountNumber()
{
    return checkingAccountNumber;
}
