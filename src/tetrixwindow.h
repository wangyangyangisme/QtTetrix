//
// Created by newcoderlife on 17-9-17.
//

#ifndef QTTETRIX_TETRIXWINDOW_H
#define QTTETRIX_TETRIXWINDOW_H

#include <QtWidgets/QWidget>

class QTableWidget;

class QLCDNumber;

class QLabel;

class QPushButton;

class QMenuBar;

class TetrixBoard;

class UserManager;

class UserDialog;

class TetrixWindow : public QWidget {
Q_OBJECT

public:
    TetrixWindow();

private:
    QLabel *createLabel(const QString &text);

    TetrixBoard *board;
    UserManager *userManager;
    UserDialog *userDialog;
    QLabel *nextPieceLabel;
    QLCDNumber *scoreLcd, *levelLcd, *linesLcd;
    QPushButton *startButton, *quitButton, *pauseButton, *goOnButton;
    QMenuBar *menuBar;
    QAction *signInAction, *signUpAction;
    QTableWidget *tableWidget;
};

#endif //QTTETRIX_TETRIXWINDOW_H
