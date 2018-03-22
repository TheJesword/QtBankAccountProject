
//#include <QTextEdit>

#include "window.h"

int main (int argc, char **argv)
{
    QApplication app(argc, argv);

    Window window;
    window.show();

    return app.exec();
    }

/*
     *Using later to accept text input from user*

    QTextEdit *txt = new QTextEdit(&window);
     txt->setText("Hello, world!");
     txt->append("Appending some text…");

*/
