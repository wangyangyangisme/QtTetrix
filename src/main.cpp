//
// Created by newcoderlife on 17-9-17.
//

#include "tetrixwindow.h"

#include <QtWidgets/QApplication>
#include <QtCore/QTime>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    TetrixWindow window;
    window.show();
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    return app.exec();
}