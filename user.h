#ifndef USER_H
#define USER_H

class User
{
private:
    unsigned int checkingAccountNumber;
public:
    User();
    unsigned int getCheckingAccountNumber();
    ~User();
};

#endif // USER_H
