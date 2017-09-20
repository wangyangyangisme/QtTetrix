//
// Created by newcoderlife on 17-9-20.
//

#ifndef QTTETRIX_USERINFO_H
#define QTTETRIX_USERINFO_H

#include <QtCore/QString>

class QJsonObject;

class UserInfo {
private:
    QString signUpTime, username, password;
    int level, score;

public:
    UserInfo();

    explicit UserInfo(const QJsonObject &userObject);

    UserInfo(const QString &signUpTime, const QString &username, const QString &password, int level, int score);

    const QString &getSignUpTime() const;

    void setSignUpTime(const QString &signUpTime);

    const QString &getUsername() const;

    void setUsername(const QString &username);

    const QString &getPassword() const;

    void setPassword(const QString &password);

    int getLevel() const;

    void setLevel(int level);

    int getScore() const;

    void setScore(int score);

    const QJsonObject &toQJsonObject() const;

    bool operator<(const UserInfo &rhs) const;
};

#endif //QTTETRIX_USERINFO_H
