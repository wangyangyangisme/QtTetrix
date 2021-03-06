//
// Created by newcoderlife on 17-9-19.
//

#ifndef QTTETRIX_USERMANAGER_H
#define QTTETRIX_USERMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QVector>

class UserInfo;

class UserManager : public QObject {
Q_OBJECT

public:
    explicit UserManager(QObject *parent = nullptr);

    ~UserManager() override;

    void auth(const QString &username, const QString &password);

    void newUser(const QString &username, const QString &password);

    const QVector<UserInfo> &getUserVector() const;

    const UserInfo &getCurrentUser() const;

    void setCurrentScore(int currentScore);

    void setCurrentLevel(int currentLevel);

    void showLogInSuccess(const QString &text);

signals:

    void scoreChanged(int score);

    void levelChanged(int level);

    void logInSuccess(bool inAvailable);

private:
    QVector<UserInfo> userVector;
    UserInfo *currentUser;
};

#endif //QTTETRIX_USERMANAGER_H
