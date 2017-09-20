//
// Created by newcoderlife on 17-9-17.
//

#ifndef QTTETRIX_TETRIXBOARD_H
#define QTTETRIX_TETRIXBOARD_H

#include "tetrixpiece.h"

#include <QtCore/QBasicTimer>
#include <QtWidgets/QFrame>
#include <QtCore/QPointer>

class QLabel;

class TetrixBoard : public QFrame {
Q_OBJECT

public:
    explicit TetrixBoard(QWidget *parent = nullptr);

    void setNextPieceLabel(QLabel *label);

    QSize sizeHint() const override;

    QSize minimumSizeHint() const override;

    void setScore(int score);

    void setLevel(int level);

public slots:

    void start();

    void pause();

    void goOn();

signals:

    void scoreChanged(int score);

    void levelChanged(int level);

    void linesRemovedChanged(int numLines);

protected:
    void paintEvent(QPaintEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

    void timerEvent(QTimerEvent *event) override;

private:
    enum {
        BoardWidth = 10, BoardHeight = 22
    };

    TetrixShape &shapeAt(int x, int y) { return board[(y * BoardWidth) + x]; }

    int timeoutTime() { return 1000 / (1 + level); }

    int squareWidth() { return contentsRect().width() / BoardWidth; }

    int squareHeight() { return contentsRect().height() / BoardHeight; }

    void clearBoard();

    void dropDown();

    void oneLineDown();

    void pieceDropped(int dropHeight);

    void removeFullLines();

    void newPiece();

    void showNextPiece();

    bool tryMove(const TetrixPiece &newPiece, int newX, int newY);

    void drawSquare(QPainter &painter, int x, int y, TetrixShape shape);

    QBasicTimer timer;
    QPointer<QLabel> nextPieceLabel;
    bool isStarted, isPaused, isWaitingAfterLine;
    TetrixPiece curPiece, nextPiece;
    int curX, curY, numLinesRemoved, numPiecesDropped, score, level;
    TetrixShape board[BoardWidth * BoardHeight];
};

#endif //QTTETRIX_TETRIXBOARD_H
