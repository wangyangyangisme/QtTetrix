//
// Created by newcoderlife on 17-9-17.
//

#include "tetrixwindow.h"
#include "tetrixboard.h"
#include "userdialog.h"

#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMenuBar>
#include <QtCore/QCoreApplication>

TetrixWindow::TetrixWindow() {
    board = new TetrixBoard;

    nextPieceLabel = new QLabel;
    nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    nextPieceLabel->setAlignment(Qt::AlignCenter);
    board->setNextPieceLabel(nextPieceLabel);

    scoreLcd = new QLCDNumber(5);
    scoreLcd->setSegmentStyle(QLCDNumber::Filled);

    levelLcd = new QLCDNumber(2);
    levelLcd->setSegmentStyle(QLCDNumber::Filled);
    linesLcd = new QLCDNumber(5);
    linesLcd->setSegmentStyle(QLCDNumber::Filled);

    startButton = new QPushButton(tr("&Start"));
    startButton->setFocusPolicy(Qt::NoFocus);
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setFocusPolicy(Qt::NoFocus);
    pauseButton = new QPushButton(tr("&Pause"));
    pauseButton->setFocusPolicy(Qt::NoFocus);

    menuBar = new QMenuBar(this);
    saveAction = new QAction(tr("保存"), menuBar);
    loadAction = new QAction(tr("读取"), menuBar);
    menuBar->addAction(saveAction);
    menuBar->addAction(loadAction);

    userDialog = new UserDialog(this);

    connect(startButton, SIGNAL(clicked()), board, SLOT(start()));
    connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(pauseButton, SIGNAL(clicked()), board, SLOT(pause()));
    connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));
    connect(board, SIGNAL(levelChanged(int)), levelLcd, SLOT(display(int)));
    connect(board, SIGNAL(linesRemovedChanged(int)), linesLcd, SLOT(display(int)));
    connect(saveAction, &QAction::triggered, this, &TetrixWindow::onSaveActionTriggered);
    connect(loadAction, &QAction::triggered, this, &TetrixWindow::onSaveActionTriggered);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("下一块")), 0, 0);
    layout->addWidget(nextPieceLabel, 1, 0);
    layout->addWidget(createLabel(tr("等级")), 2, 0);
    layout->addWidget(levelLcd, 3, 0);
    layout->addWidget(startButton, 4, 0);
    layout->addWidget(board, 0, 1, 6, 1);
    layout->addWidget(createLabel(tr("分数")), 0, 2);
    layout->addWidget(scoreLcd, 1, 2);
    layout->addWidget(createLabel(tr("已移除的行数")), 2, 2);
    layout->addWidget(linesLcd, 3, 2);
    layout->addWidget(quitButton, 4, 2);
    layout->addWidget(pauseButton, 5, 2);
    layout->setMenuBar(menuBar);
    setLayout(layout);

    setWindowTitle(tr("俄罗斯方块"));
    resize(550, 370);
}

QLabel *TetrixWindow::createLabel(const QString &text) {
    QLabel *lbl = new QLabel(text);
    lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return lbl;
}

void TetrixWindow::onSaveActionTriggered() {
    UserDialog::save(this);
}

void TetrixWindow::onLoadActionTriggered() {
    UserDialog::load(this);
}
