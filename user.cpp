#include "user.h"

User::User()
{
    checkingAccountNumber = 12345;
}

unsigned int User::getCheckingAccountNumber()
{
    return checkingAccountNumber;
}

User::~User()
{

}
