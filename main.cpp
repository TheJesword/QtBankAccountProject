#include <QApplication>
#include <QPushButton>
#include <QLabel>
//#include <QTextEdit>
#include <QWidget>
#include <QString>

int main (int argc, char **argv)
{
    QApplication app(argc, argv);

    unsigned int accountNumber = 0;
    double balance = 0;
    QString userName = "Heck Yeah";

    // Creating the window object along with the
    // size of the window
    QWidget window;
    window.setFixedSize(1000,500);

    // These are the label objects used to create the
    // user name, balance and account number texts

    QLabel *userNameLabel = new QLabel(&window);
    userNameLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    userNameLabel->setText("User Name:");
    userNameLabel->setGeometry(375,70,100,30);

    QLabel *accountNumberLabel = new QLabel(&window);
    accountNumberLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    accountNumberLabel->setText("Account Number:");
    accountNumberLabel->setGeometry(375,100,100,30);

    QLabel *balanceLabel = new QLabel(&window);
    balanceLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    balanceLabel->setText("Balance:");
    balanceLabel->setGeometry(375,130,100,30);

    // These next labels are for displaying the actual
    // variables onto the screen
    QLabel *userNameDisplay = new QLabel(&window);
    userNameDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    userNameDisplay->setText(userName);
    userNameDisplay->setGeometry(480,70,100,30);

    // We have to use QString::number to convert the number into
    // a string to be displayed onto the window
    QLabel *accountNumberDisplay = new QLabel(&window);
    accountNumberDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    accountNumberDisplay->setText(QString::number(accountNumber));
    accountNumberDisplay->setGeometry(480,100,100,30);

    QLabel *balanceDisplay = new QLabel(&window);
    balanceDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    balanceDisplay->setText(QString::number(balance));
    balanceDisplay->setGeometry(480,130,100,30);

    /*
     *Using later to accept text input from user*

    QTextEdit *txt = new QTextEdit(&window);
     txt->setText("Hello, world!");
     txt->append("Appending some text…");
    */

    // These are the button objects used to create all of the buttons
    // that will perform actions when pushed

        QPushButton * savingsButton = new QPushButton("Savings Account", &window);
    savingsButton->setGeometry(75,300,120,30);

      QPushButton * checkingsButton = new QPushButton("Checkings Account", &window);
    checkingsButton->setGeometry(75,350,120,30);

      QPushButton * transferButton = new QPushButton("Transfer", &window);
    transferButton->setGeometry(75,400,120,30);

      QPushButton * depositButton = new QPushButton("Deposit", &window);
    depositButton->setGeometry(800,350,120,30);

      QPushButton * withdrawButton = new QPushButton("Withdraw", &window);
    withdrawButton->setGeometry(800,300,120,30);

      QPushButton * historyButton = new QPushButton("Transaction History", &window);
    historyButton->setGeometry(800,400,120,30);

    // Displaying the window to the screen
    window.show();

    return app.exec();
    }

