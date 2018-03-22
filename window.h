#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QPUshButton>
#include <QLabel>
#include <QString>


class QPushButton;
class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

private:

    // PushButton objects
    QPushButton * savingsButton;
    QPushButton * checkingsButton;
    QPushButton * transferButton;
    QPushButton * depositButton;
    QPushButton * withdrawButton;
    QPushButton * historyButton;
    QPushButton * okButton;

    // QLabel objects
    QLabel * userNameLabel;
    QLabel * accountNumberLabel;
    QLabel * balanceLabel;
    QLabel * userNameDisplay;
    QLabel * accountNumberDisplay;
   // QLabel * balanceDisplay;
    QLabel * messageLabel;


private slots:
    void savingsButtonWindow();
    void checkingsWindow();
    void depositWindow();
    void depositSavingsWindow();
    void depositCheckingsWindow();
    void withdrawWindow();
    void withdrawCheckingsWindow();
    void withdrawSavingsWindow();
    void transferWindow();
    void historyWindow();

};

#endif // WINDOW_H
