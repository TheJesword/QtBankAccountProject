#include "window.h"

Window::Window(QWidget *parent) : QMainWindow(parent)
{
    QString userName = "Heck Yeah";
    unsigned int accountNumber = 0;
    double balance = 0;

    setFixedSize(1000,500);

     //----------- Labels objects ----------------------

    userNameLabel = new QLabel(this);
    userNameLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    userNameLabel->setText("User Name:");
    userNameLabel->setGeometry(375,70,100,30);

    accountNumberLabel = new QLabel(this);
    accountNumberLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    accountNumberLabel->setText("Account Number:");
    accountNumberLabel->setGeometry(375,100,100,30);

    balanceLabel = new QLabel(this);
    balanceLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    balanceLabel->setText("Balance:");
    balanceLabel->setGeometry(375,130,100,30);

    userNameDisplay = new QLabel(this);
    userNameDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    userNameDisplay->setText(userName);
    userNameDisplay->setGeometry(480,70,100,30);

    accountNumberDisplay = new QLabel(this);
    accountNumberDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    accountNumberDisplay->setText(QString::number(accountNumber));
    accountNumberDisplay->setGeometry(480,100,100,30);

    balanceDisplay = new QLabel(this);
    balanceDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    balanceDisplay->setText(QString::number(balance));
    balanceDisplay->setGeometry(480,130,100,30);


    //----------- Push buttons objects ------------------
    savingsButton = new QPushButton("Savings Account", this);
    savingsButton->setGeometry(75,300,120,30);

    checkingsButton = new QPushButton("Checkings Account", this);
    checkingsButton->setGeometry(75,350,120,30);

    transferButton = new QPushButton("Transfer", this);
    transferButton->setGeometry(75,400,120,30);

    depositButton = new QPushButton("Deposit", this);
    depositButton->setGeometry(800,350,120,30);

    withdrawButton = new QPushButton("Withdraw", this);
    withdrawButton->setGeometry(800,300,120,30);

    historyButton = new QPushButton("Transaction History", this);
    historyButton->setGeometry(800,400,120,30);
}
