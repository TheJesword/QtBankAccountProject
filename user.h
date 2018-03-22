#ifndef USER_H
#define USER_H

#include <QObject>
#include "window.h"

class User : public QObject
{
    Q_OBJECT

private:
    int checkingAccountNumber;
    int savingAccountNumber;

public:
    explicit User(QObject *parent = nullptr);
    void setCheckingAccountNumber(int checkingAccountNumber);
    int getCheckingAccountNumber();

signals:

public slots:
};

#endif // USER_H
