//
// Created by newcoderlife on 17-9-17.
//

#ifndef QTTETRIX_TETRIXWINDOW_H
#define QTTETRIX_TETRIXWINDOW_H

#include <QtWidgets/QWidget>

class QLCDNumber;

class QLabel;

class QPushButton;

class QMenuBar;

class UserDialog;

class TetrixBoard;

class TetrixWindow : public QWidget {
Q_OBJECT

public:
    TetrixWindow();

    void onSaveActionTriggered();

    void onLoadActionTriggered();

private:
    QLabel *createLabel(const QString &text);

    TetrixBoard *board;
    UserDialog *userDialog;
    QLabel *nextPieceLabel;
    QLCDNumber *scoreLcd, *levelLcd, *linesLcd;
    QPushButton *startButton, *quitButton, *pauseButton;
    QMenuBar *menuBar;
    QAction *saveAction, *loadAction;
};

#endif //QTTETRIX_TETRIXWINDOW_H
