//
// Created by newcoderlife on 17-9-17.
//

#include "tetrixwindow.h"
#include "tetrixboard.h"
#include "usermanager.h"
#include "userdialog.h"

#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMenuBar>
#include <QtCore/QCoreApplication>

TetrixWindow::TetrixWindow() {
    board = new TetrixBoard(this);
    userManager = new UserManager(this);
    userDialog = new UserDialog(this);

    nextPieceLabel = new QLabel(this);
    nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    nextPieceLabel->setAlignment(Qt::AlignCenter);
    board->setNextPieceLabel(nextPieceLabel);

    scoreLcd = new QLCDNumber(5, this);
    scoreLcd->setSegmentStyle(QLCDNumber::Filled);
    levelLcd = new QLCDNumber(2, this);
    levelLcd->setSegmentStyle(QLCDNumber::Filled);
    linesLcd = new QLCDNumber(5, this);
    linesLcd->setSegmentStyle(QLCDNumber::Filled);

    startButton = new QPushButton(tr("开始"), this);
    startButton->setFocusPolicy(Qt::NoFocus);
    quitButton = new QPushButton(tr("退出"), this);
    quitButton->setFocusPolicy(Qt::NoFocus);
    pauseButton = new QPushButton(tr("暂停"), this);
    pauseButton->setFocusPolicy(Qt::NoFocus);
    goOnButton = new QPushButton(tr("继续"), this);
    goOnButton->setFocusPolicy(Qt::NoFocus);
    goOnButton->setDisabled(true);

    menuBar = new QMenuBar(this);
    signInAction = new QAction(tr("登录"), menuBar);
    signUpAction = new QAction(tr("注册"), menuBar);
    menuBar->addAction(signInAction);
    menuBar->addAction(signUpAction);

    connect(startButton, SIGNAL(clicked()), board, SLOT(start()));
    connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(goOnButton, &QPushButton::clicked, board, &TetrixBoard::goOn);
    connect(pauseButton, SIGNAL(clicked()), board, SLOT(pause()));
    connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));
    connect(board, &TetrixBoard::scoreChanged, userManager, &UserManager::setCurrentScore);
    connect(userManager, &UserManager::scoreChanged, board, &TetrixBoard::setScore);
    connect(board, SIGNAL(levelChanged(int)), levelLcd, SLOT(display(int)));
    connect(board, &TetrixBoard::levelChanged, userManager, &UserManager::setCurrentLevel);
    connect(userManager, &UserManager::levelChanged, board, &TetrixBoard::setLevel);
    connect(board, SIGNAL(linesRemovedChanged(int)), linesLcd, SLOT(display(int)));
    connect(signInAction, &QAction::triggered, userDialog, &UserDialog::signIn);
    connect(signUpAction, &QAction::triggered, userDialog, &UserDialog::signUp);
    connect(userDialog, &UserDialog::sendSignInInfo, userManager, &UserManager::auth);
    connect(userDialog, &UserDialog::sendSignUpInfo, userManager, &UserManager::newUser);
    connect(userManager, &UserManager::logInSuccess, goOnButton, &QPushButton::setDisabled);
    // TODO: connect(this, &TetrixWindow::show, userDialog, &UserDialog::signIn);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("下一块")), 0, 0);
    layout->addWidget(nextPieceLabel, 1, 0);
    layout->addWidget(createLabel(tr("等级")), 2, 0);
    layout->addWidget(levelLcd, 3, 0);
    layout->addWidget(startButton, 4, 0);
    layout->addWidget(goOnButton, 5, 0);
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
