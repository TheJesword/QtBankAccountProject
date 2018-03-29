#include "login.h"

Login::Login(QWidget *parent) : QWidget(parent)
{
    setFixedSize(1000,500);

    QLabel * getInfo = new QLabel(this);
    getInfo->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    getInfo->setText("Enter username and Password");
    getInfo->setGeometry(400,100,175,30);

    QPushButton * infoButton = new QPushButton("Login", this);
    infoButton->setGeometry(430,300,120,30);
    connect(infoButton, SIGNAL (pressed()), this, SLOT (getInfoSlot()));
}

void Login::setUserName(QString userName)
{
    this->userName = userName;
}
QString Login::getUserName()
{
    return userName;
}
void Login::setPassword(QString password)
{
    this->password = password;
}
QString Login::getPassword()
{
    return password;
}
void Login::getInfoSlot()
{
    bool ok;
       QString userName = QInputDialog::getText(this, tr("Login"),
                                            tr("User name:"), QLineEdit::Normal,
                                            QDir::home().dirName(), &ok);
       if (ok && !userName.isEmpty())
       {
           setUserName(userName);
           QString password = QInputDialog::getText(this, tr("Login"),
                                                tr("Password:"), QLineEdit::Normal,
                                                QDir::home().dirName(), &ok);
           if (ok && !password.isEmpty())
           {
               setPassword(password);
           }

       }

       checkUserNameAndPassword(userName, password);
}
bool Login::checkUserNameAndPassword(QString userName, QString password)
{
    if (userName == "Heck" && password == "Yeah")
    {
        return true;
    }
    else
    {
        QWidget * errorWindow = new QWidget;
        errorWindow->setFixedSize(300,250);

        QLabel * errorMessage = new QLabel(errorWindow);
        errorMessage->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        errorMessage->setText("Username = Heck\nPassword = Yeah");
        errorMessage->setGeometry(50,80,210,30);

        QPushButton * okButton = new QPushButton("OK", errorWindow);
        okButton->setGeometry(110,180,60,30);
        connect(okButton, SIGNAL (pressed()), errorWindow, SLOT (close()));
        errorWindow->show();
        return false;
    }
}


