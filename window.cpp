#include "window.h"

Window::Window(QWidget *parent) : QMainWindow(parent)
{

    QString userName = "Heck Yeah";

    setFixedSize(1000,500);

     //----------- Labels objects ----------------------

    userNameLabel = new QLabel(this);
    userNameLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    userNameLabel->setText("User Name:");
    userNameLabel->setGeometry(375,100,100,30);

    userNameDisplay = new QLabel(this);
    userNameDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    userNameDisplay->setText(userName);
    userNameDisplay->setGeometry(480,100,100,30);

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

  savingsAccountLabel = new QLabel(savingsWindow);
  savingsAccountLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
  savingsAccountLabel->setText("Savings Account Number:");
  savingsAccountLabel->setGeometry(350,100,140,30);

  savingsBalanceLabel = new QLabel(savingsWindow);
  savingsBalanceLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
  savingsBalanceLabel->setText("Balance:");
  savingsBalanceLabel->setGeometry(375,130,100,30);

  savingsAccountDisplay = new QLabel(savingsWindow);
  savingsAccountDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
  savingsAccountDisplay->setText(QString::number(user.getSavingsAccountNumber()));
  savingsAccountDisplay->setGeometry(500,100,100,30);

  savingsBalanceDisplay = new QLabel(savingsWindow);
  savingsBalanceDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
  savingsBalanceDisplay->setText(QString::number(savings.getSavingsBalance()));
  savingsBalanceDisplay->setGeometry(490,130,100,30);

  okButton = new QPushButton("OK", savingsWindow);
  okButton->setGeometry(450,400,60,30);
  connect(okButton, SIGNAL (pressed()), savingsWindow, SLOT (close()));

  savingsWindow->show();
}

void Window::checkingsButtonWindow()
{
    // Creating the new window
  QWidget * checkingsWindow = new QWidget;
  checkingsWindow->setFixedSize(1000,500);

  checkingAccountNumberLabel = new QLabel(checkingsWindow);
  checkingAccountNumberLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
  checkingAccountNumberLabel->setText("Checking Account Number:");
  checkingAccountNumberLabel->setGeometry(350,100,140,30);

  checkingBalanceLabel = new QLabel(checkingsWindow);
  checkingBalanceLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
  checkingBalanceLabel->setText("Balance:");
  checkingBalanceLabel->setGeometry(375,150,100,30);

  checkingAccountNumberDisplay = new QLabel(checkingsWindow);
  checkingAccountNumberDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
  checkingAccountNumberDisplay->setText(QString::number(user.getCheckingAccountNumber()));
  checkingAccountNumberDisplay->setGeometry(500,100,100,30);

  checkingBalanceDisplay = new QLabel(checkingsWindow);
  checkingBalanceDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
  checkingBalanceDisplay->setText(QString::number(checkings.getCheckingBalance()));
  checkingBalanceDisplay->setGeometry(490,150,100,30);

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
  connect(depositSavingsButton, SIGNAL (pressed()), this, SLOT (depositIntoSavings()));
  connect(depositSavingsButton, SIGNAL (pressed()), depositWindow, SLOT (close()));

  depositCheckingsButton = new QPushButton("Checkings", depositWindow);
  depositCheckingsButton->setGeometry(800,300,120,30);
  connect(depositCheckingsButton, SIGNAL (pressed()), this, SLOT (depositIntoCheckings()));
  connect(depositCheckingsButton, SIGNAL (pressed()), depositWindow, SLOT (close()));

  okButton = new QPushButton("OK", depositWindow);
  okButton->setGeometry(450,400,60,30);
  connect(okButton, SIGNAL (pressed()), depositWindow, SLOT (close()));

  depositWindow->show();
}

void Window::depositIntoSavings()
{
    // bool ok is for the window that opens up to get the user input
    // once pressed okay it will save the data and go through the functions
    bool ok;
      double userInput = QInputDialog::getDouble(this, tr("Enter Deposit Amount"),
                                         tr("Amount:"), 0.0, -1000000, 1000000, 2, &ok);
      if (ok)
      {
          // setting the amount be dosposited to be saving the amounts entered
          // into the savings vector for history
          savings.setDeposit(userInput);
          savings.saveTransaction(savingsTransaction,userInput);
      }
}

void Window::depositIntoCheckings()
{
    // bool ok is for the window that opens up to get the user input
    // once pressed okay it will save the data and go through the functions
    bool ok;
      double userInput = QInputDialog::getDouble(this, tr("Enter Deposit Amount"),
                                         tr("Amount:"), 0.0, -1000000, 1000000, 2, &ok);
      if (ok)
      {
          // setting the amount be dosposited to be saving the amounts entered
          // into the checkings vector for history
          checkings.setDeposit(userInput);
          checkings.saveTransaction(checkingsTransaction,userInput);
      }
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
    connect(withdrawSavingsButton, SIGNAL (pressed()), this, SLOT (withdrawFromSavings()));
    connect(withdrawSavingsButton, SIGNAL (pressed()), withdrawWindow, SLOT (close()));

    withdrawCheckingsButton = new QPushButton("Checkings", withdrawWindow);
    withdrawCheckingsButton->setGeometry(800,300,120,30);
    connect(withdrawCheckingsButton, SIGNAL (pressed()), this, SLOT (withdrawFromCheckings()));
    connect(withdrawCheckingsButton, SIGNAL (pressed()), withdrawWindow, SLOT (close()));

    okButton = new QPushButton("OK", withdrawWindow);
    okButton->setGeometry(450,400,60,30);
    connect(okButton, SIGNAL (pressed()), withdrawWindow, SLOT (close()));

    withdrawWindow->show();
}

void Window::withdrawFromCheckings()
{
    bool ok;
      double userInput = QInputDialog::getDouble(this, tr("Enter Deposit Amount"),
                                         tr("Amount:"), 0.0, -1000000, 1000000, 2, &ok);
      if (ok)
      {
          checkings.setWithdraw(userInput);

          // creating a temp variable to make the input negative so
          // it will be displayed as a negative number when in the history window
          double temp;
          temp = (userInput - userInput) - userInput;
          checkings.saveTransaction(checkingsTransaction,temp);
      }
}

void Window::withdrawFromSavings()
{
    bool ok;
      double userInput = QInputDialog::getDouble(this, tr("Enter Deposit Amount"),
                                         tr("Amount:"), 0.0, -1000000, 1000000, 2, &ok);
      if (ok)
      {
          savings.setWithdraw(userInput);

          // creating a temp variable to make the input negative so
          // it will be displayed as a negative number when in the history window
          double temp;
          temp = (userInput - userInput) - userInput;
          savings.saveTransaction(savingsTransaction,temp);
      }
}

void Window::transferButtonWindow()
{
    QWidget * transferWindow = new QWidget;
    transferWindow->setFixedSize(1000,500);

    transferLabel = new QLabel(transferWindow);
    transferLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    transferLabel->setText("Choose an Account to transfer from:");
    transferLabel->setGeometry(350,150,200,30);

    transferCheckingsToSavings = new QPushButton("Checkings to Savings", transferWindow);
    transferCheckingsToSavings->setGeometry(400,300,120,30);
    connect(transferCheckingsToSavings, SIGNAL (pressed()), this, SLOT (checkingsToSavingsTransfer()));
    connect(transferCheckingsToSavings, SIGNAL (pressed()), transferWindow, SLOT (close()));

    transferSavingsToCheckings = new QPushButton("Savings to Checkings", transferWindow);
    transferSavingsToCheckings->setGeometry(400,250,120,30);
    connect(transferSavingsToCheckings, SIGNAL (pressed()), this, SLOT (savingsToCheckingsTransfer()));
    connect(transferSavingsToCheckings, SIGNAL (pressed()), transferWindow, SLOT (close()));


    okButton = new QPushButton("OK", transferWindow);
    okButton->setGeometry(450,400,60,30);
    connect(okButton, SIGNAL (pressed()), transferWindow, SLOT (close()));

    transferWindow->show();
}

void Window::checkingsToSavingsTransfer()
{
    bool ok;
      double userInput = QInputDialog::getDouble(this, tr("Enter Deposit Amount"),
                                         tr("Amount:"), 0.0, -1000000, 1000000, 2, &ok);
      if (ok)
      {
          // for transfering funds we just call both of the opposite functions at the same
          // time. Using the amount entered for withdraw from one and deposit to another
          savings.setDeposit(userInput);
          savings.saveTransaction(savingsTransaction,userInput);

          double temp;
          temp = (userInput - userInput) - userInput;
          checkings.saveTransaction(checkingsTransaction,temp);
          checkings.setWithdraw(userInput);

      }
}

void Window::savingsToCheckingsTransfer()
{
    bool ok;
      double userInput = QInputDialog::getDouble(this, tr("Enter Deposit Amount"),
                                         tr("Amount:"), 0.0, -1000000, 1000000, 2, &ok);
      if (ok)
      {
          // for transfering funds we just call both of the opposite functions at the same
          // time. Using the amount entered for withdraw from one and deposit to another
            checkings.setDeposit(userInput);
            checkings.saveTransaction(checkingsTransaction,userInput);

            double temp;
            temp = (userInput - userInput) - userInput;
            savings.saveTransaction(savingsTransaction,temp);
            savings.setWithdraw(userInput);
      }
}

void Window::historyButtonWindow()
{
    QWidget * historyWindow = new QWidget;
    historyWindow->setFixedSize(1000,500);

    historyLabel = new QLabel(historyWindow);
    historyLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    historyLabel->setText("Transaction History: ");
    historyLabel->setGeometry(400,100,120,30);

    savingsHistoryLabel = new QLabel(historyWindow);
    savingsHistoryLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    savingsHistoryLabel->setText("Savings: ");
    savingsHistoryLabel->setGeometry(150,150,120,30);

    checkingsHistoryLabel = new QLabel(historyWindow);
    checkingsHistoryLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    checkingsHistoryLabel->setText("Checkings: ");
    checkingsHistoryLabel->setGeometry(750,150,120,30);

    // Creating a variable to move the label down in pixels
    // everytime it goes through the loop creating a new label
    int moveDownSavings = 200;
    for (int i = 0; i < savingsTransaction.size(); i++)
    {
        QLabel * savTransactionLabel = new QLabel(historyWindow);
        savTransactionLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        savTransactionLabel->setText(QString::number(savingsTransaction[i]));
        savTransactionLabel->setGeometry(150,moveDownSavings,120,30);
        moveDownSavings = moveDownSavings + 40;
    }

    // Creating a variable to move the label down in pixels
    // everytime it goes through the loop creating a new label
    int moveDownCheckings = 200;
    for (int i = 0; i < checkingsTransaction.size(); i++)
    {
        QLabel * checkTransactionLabel = new QLabel(historyWindow);
        checkTransactionLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        checkTransactionLabel->setText(QString::number(checkingsTransaction[i]));
        checkTransactionLabel->setGeometry(750,moveDownCheckings,120,30);
        moveDownCheckings = moveDownCheckings + 40;
    }

    okButton = new QPushButton("OK", historyWindow);
    okButton->setGeometry(450,400,60,30);
    connect(okButton, SIGNAL (pressed()), historyWindow, SLOT (close()));

    historyWindow->show();
}
