//
// Created by newcoderlife on 17-9-20.
//

#ifndef QTTETRIX_USERINFO_H
#define QTTETRIX_USERINFO_H

#include <QtCore/QString>
#include <QtCore/QVector>

class QJsonObject;

class UserInfo {
private:
    QString username, password;
    int level, score, maxScore;

public:
    UserInfo();

    explicit UserInfo(const QJsonObject &userObject);

    UserInfo(const QString &signUpTime, const QString &username, const QString &password, int level, int score);

    const QString &getUsername() const;

    const QString &getPassword() const;

    int getLevel() const;

    void setLevel(int level);

    int getScore() const;

    void setScore(int score);

    int getMaxScore() const;

    void setMaxScore(int maxScore);

    const QJsonObject &toQJsonObject() const;

    bool operator<(const UserInfo &rhs) const;

    QVector<QString> signInTimes;
    QVector<QString> signOutTimes;
};

#endif //QTTETRIX_USERINFO_H
