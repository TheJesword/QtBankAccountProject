
//#include <QTextEdit>

#include "window.h"
#include "login.h"

int main (int argc, char **argv)
{
    QApplication app(argc, argv);
    QString userName;
    QString password;

    Login loginScreen;
    loginScreen.show();

    // while loop ?
   // Window window;
   // window.show();
   // loginScreen.close();

    return app.exec();
    }

/*
     *Using later to accept text input from user*

    QTextEdit *txt = new QTextEdit(&window);
     txt->setText("Hello, world!");
     txt->append("Appending some text…");

*/
