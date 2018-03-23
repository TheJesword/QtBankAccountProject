#include "window.h"

Window::Window(QWidget *parent) : QMainWindow(parent)
{

    QString userName = "Heck Yeah";
   // unsigned int accountNumber = 0;
   // double balance = 0;

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

    userNameDisplay = new QLabel(this);
    userNameDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    userNameDisplay->setText(userName);
    userNameDisplay->setGeometry(480,70,100,30);

    accountNumberDisplay = new QLabel(this);
    accountNumberDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    accountNumberDisplay->setText(QString::number(user.getCheckingAccountNumber()));
    accountNumberDisplay->setGeometry(480,100,100,30);


    //----------- Push buttons objects on Main Window ------------------
    savingsButton = new QPushButton("Savings Account", this);
    savingsButton->setGeometry(75,300,120,30);
    connect(savingsButton, SIGNAL (pressed()), this, SLOT (savingsButtonWindow()));

    checkingsButton = new QPushButton("Checkings Account", this);
    checkingsButton->setGeometry(75,350,120,30);
    connect(checkingsButton, SIGNAL (pressed()), this, SLOT (checkingsButtonWindow()));

    transferButton = new QPushButton("Transfer", this);
    transferButton->setGeometry(75,400,120,30);
    connect(transferButton, SIGNAL (pressed()), this, SLOT (transferButtonWindow()));

    depositButton = new QPushButton("Deposit", this);
    depositButton->setGeometry(800,350,120,30);
    connect(depositButton, SIGNAL (pressed()), this, SLOT (depositButtonWindow()));

    historyButton = new QPushButton("Transaction History", this);
    historyButton->setGeometry(800,400,120,30);
    connect(historyButton, SIGNAL (pressed()), this, SLOT (historyButtonWindow()));

    okButton = new QPushButton("Quit", this);
    okButton->setGeometry(450,400,60,30);
    connect(okButton, SIGNAL (pressed()), this, SLOT (close()));

    withdrawButton = new QPushButton("Withdraw", this);
    withdrawButton->setGeometry(800,300,120,30);
    connect(withdrawButton, SIGNAL (pressed()), this, SLOT (withdrawButtonWindow()));


}

void Window::savingsButtonWindow()
{
    // Creating the new window
  QWidget * savingsWindow = new QWidget;
  savingsWindow->setFixedSize(1000,500);

  balanceLabel = new QLabel(savingsWindow);
  balanceLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
  balanceLabel->setText("Balance:");
  balanceLabel->setGeometry(375,130,100,30);


  balanceDisplay = new QLabel(savingsWindow);
  balanceDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
  balanceDisplay->setText("$$$");
  balanceDisplay->setGeometry(490,130,100,30);


  // have to fix the display balance later
  //balanceDisplay->setText(QString::number(balance));

  okButton = new QPushButton("OK", savingsWindow);
  okButton->setGeometry(450,400,60,30);
  connect(okButton, SIGNAL (pressed()), savingsWindow, SLOT (close()));

  // display info

  savingsWindow->show();
}

void Window::checkingsButtonWindow()
{
    // Creating the new window
  QWidget * checkingsWindow = new QWidget;
  checkingsWindow->setFixedSize(1000,500);

  okButton = new QPushButton("OK", checkingsWindow);
  okButton->setGeometry(450,400,60,30);
  connect(okButton, SIGNAL (pressed()), checkingsWindow, SLOT (close()));

  checkingsWindow->show();

}

void Window::depositButtonWindow()
{
    // Creating the new window
  QWidget * depositWindow = new QWidget;
  depositWindow->setFixedSize(1000,500);

  depositMessageLabel = new QLabel(depositWindow);
  depositMessageLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
  depositMessageLabel->setText("Which account would you like to deposit money into?");
  depositMessageLabel->setGeometry(350,150,270,30);

  depositSavingsButton = new QPushButton("Savings", depositWindow);
  depositSavingsButton->setGeometry(75,300,120,30);
  connect(depositSavingsButton, SIGNAL (pressed()), this, SLOT (depositSavingsButtonWindow()));

  depositCheckingsButton = new QPushButton("Checkings", depositWindow);
  depositCheckingsButton->setGeometry(800,300,120,30);
  connect(depositCheckingsButton, SIGNAL (pressed()), this, SLOT (depositCheckingsButtonWindow()));

  okButton = new QPushButton("OK", depositWindow);
  okButton->setGeometry(450,400,60,30);
  connect(okButton, SIGNAL (pressed()), depositWindow, SLOT (close()));

  depositWindow->show();
}

void Window::depositSavingsButtonWindow()
{
    // Creating the new window
  QWidget * depositSavingsWindow = new QWidget;
  depositSavingsWindow->setFixedSize(1000,500);

  okButton = new QPushButton("OK", depositSavingsWindow);
  okButton->setGeometry(450,400,60,30);
  connect(okButton, SIGNAL (pressed()), depositSavingsWindow, SLOT (close()));

  depositSavingsWindow->show();
}

void Window::depositCheckingsButtonWindow()
{
    QWidget * depositCheckingsWindow = new QWidget;
    depositCheckingsWindow->setFixedSize(1000,500);

    okButton = new QPushButton("OK", depositCheckingsWindow);
    okButton->setGeometry(450,400,60,30);
    connect(okButton, SIGNAL (pressed()), depositCheckingsWindow, SLOT (close()));

    depositCheckingsWindow->show();
}

void Window::withdrawButtonWindow()
{
    QWidget * withdrawWindow = new QWidget;
    withdrawWindow->setFixedSize(1000,500);

    withdrawMessageLabel = new QLabel(withdrawWindow);
    withdrawMessageLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    withdrawMessageLabel->setText("Which account would you like to withdraw money from?");
    withdrawMessageLabel->setGeometry(350,150,270,30);

    withdrawSavingsButton = new QPushButton("Savings", withdrawWindow);
    withdrawSavingsButton->setGeometry(75,300,120,30);
    connect(withdrawSavingsButton, SIGNAL (pressed()), this, SLOT (withdrawSavingsButtonWindow()));

    withdrawCheckingsButton = new QPushButton("Checkings", withdrawWindow);
    withdrawCheckingsButton->setGeometry(800,300,120,30);
    connect(withdrawCheckingsButton, SIGNAL (pressed()), this, SLOT (withdrawCheckingsButtonWindow()));

    okButton = new QPushButton("OK", withdrawWindow);
    okButton->setGeometry(450,400,60,30);
    connect(okButton, SIGNAL (pressed()), withdrawWindow, SLOT (close()));

    withdrawWindow->show();
}

void Window::withdrawCheckingsButtonWindow()
{
    QWidget * withdrawCheckingsWindow = new QWidget;
    withdrawCheckingsWindow->setFixedSize(1000,500);

    okButton = new QPushButton("OK", withdrawCheckingsWindow);
    okButton->setGeometry(450,400,60,30);
    connect(okButton, SIGNAL (pressed()), withdrawCheckingsWindow, SLOT (close()));

    withdrawCheckingsWindow->show();
}

void Window::withdrawSavingsButtonWindow()
{
    QWidget * withdrawSavingsWindow = new QWidget;
    withdrawSavingsWindow->setFixedSize(1000,500);

    okButton = new QPushButton("OK", withdrawSavingsWindow);
    okButton->setGeometry(450,400,60,30);
    connect(okButton, SIGNAL (pressed()), withdrawSavingsWindow, SLOT (close()));

    withdrawSavingsWindow->show();
}

void Window::transferButtonWindow()
{
    QWidget * transferWindow = new QWidget;
    transferWindow->setFixedSize(1000,500);

    okButton = new QPushButton("OK", transferWindow);
    okButton->setGeometry(450,400,60,30);
    connect(okButton, SIGNAL (pressed()), transferWindow, SLOT (close()));

    transferWindow->show();
}

void Window::historyButtonWindow()
{
    QWidget * historyWindow = new QWidget;
    historyWindow->setFixedSize(1000,500);

    okButton = new QPushButton("OK", historyWindow);
    okButton->setGeometry(450,400,60,30);
    connect(okButton, SIGNAL (pressed()), historyWindow, SLOT (close()));

    historyWindow->show();
}
