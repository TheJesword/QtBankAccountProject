#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QPUshButton>
#include <QLabel>
#include <QString>
#include "user.h"


class QPushButton;
class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

private:

    // PushButton objects
    QPushButton * checkingsButton;
    QPushButton * depositButton;
    QPushButton * depositSavingsButton;
    QPushButton * depositCheckingsButton;
    QPushButton * historyButton;
    QPushButton * okButton;
    QPushButton * savingsButton;
    QPushButton * transferButton;
    QPushButton * withdrawButton;
    QPushButton * withdrawSavingsButton;
    QPushButton * withdrawCheckingsButton;

    // QLabel objects
    QLabel * accountNumberLabel;
    QLabel * accountNumberDisplay;
    QLabel * balanceLabel;
    QLabel * balanceDisplay;
    QLabel * depositMessageLabel;
    QLabel * userNameDisplay;
    QLabel * userNameLabel;
    QLabel * withdrawMessageLabel;

    User user;


private slots:
    void savingsButtonWindow();
    void checkingsButtonWindow();
    void depositButtonWindow();
    void depositSavingsButtonWindow();
    void depositCheckingsButtonWindow();
    void withdrawButtonWindow();
    void withdrawCheckingsButtonWindow();
    void withdrawSavingsButtonWindow();
    void transferButtonWindow();
    void historyButtonWindow();

};

#endif // WINDOW_H
