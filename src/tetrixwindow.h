//
// Created by newcoderlife on 17-9-17.
//

#ifndef QTTETRIX_TETRIXWINDOW_H
#define QTTETRIX_TETRIXWINDOW_H

#include <QtWidgets/QWidget>

class QLCDNumber;

class QLabel;

class QPushButton;

class TetrixBoard;

class TetrixWindow : public QWidget {
Q_OBJECT

public:
    TetrixWindow();

private:
    QLabel *createLabel(const QString &text);

    TetrixBoard *board;
    QLabel *nextPieceLabel;
    QLCDNumber *scoreLcd, *levelLcd, *linesLcd;
    QPushButton *startButton, *quitButton, *pauseButton;
};

#endif //QTTETRIX_TETRIXWINDOW_H
