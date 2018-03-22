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

    // QLabel objects
    QLabel * userNameLabel;
    QLabel * accountNumberLabel;
    QLabel * balanceLabel;
    QLabel * userNameDisplay;
    QLabel * accountNumberDisplay;
    QLabel * balanceDisplay;

    // Windows
    void NewSavingsWindow();


private slots:
    void savingsButtonSlot();
};

#endif // WINDOW_H
