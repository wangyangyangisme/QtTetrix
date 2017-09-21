//
// Created by newcoderlife on 17-9-19.
//

#ifndef QTTETRIX_USERMANAGER_H
#define QTTETRIX_USERMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QVector>

class UserInfo;

class QTableWidgetItem;

class UserManager : public QObject {
Q_OBJECT

public:
    explicit UserManager(QObject *parent = nullptr);

    ~UserManager() override;

    void auth(const QString &username, const QString &password);

    void newUser(const QString &username, const QString &password);

    void setCurrentScore(int currentScore);

    void setCurrentLevel(int currentLevel);

    void showLogInSuccess(const QString &text);

    void handleRankTable(int);

signals:

    void scoreChanged(int score);

    void levelChanged(int level);

    void logInSuccess(bool inAvailable);

    void rankListAddUser(int, int, QTableWidgetItem *);

private:
    QVector<UserInfo> userVector;
    UserInfo *currentUser;
};

#endif //QTTETRIX_USERMANAGER_H
