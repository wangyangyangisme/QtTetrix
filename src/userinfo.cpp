//
// Created by newcoderlife on 17-9-20.
//

#include "userinfo.h"

#include <QtCore/QJsonObject>

int UserInfo::getLevel() const {
    return level;
}

void UserInfo::setLevel(int level) {
    UserInfo::level = level;
}

int UserInfo::getScore() const {
    return score;
}

void UserInfo::setScore(int score) {
    UserInfo::score = score;
}

const QString &UserInfo::getSignUpTime() const {
    return signUpTime;
}

void UserInfo::setSignUpTime(const QString &signUpTime) {
    UserInfo::signUpTime = signUpTime;
}

const QString &UserInfo::getUsername() const {
    return username;
}

void UserInfo::setUsername(const QString &username) {
    UserInfo::username = username;
}

const QString &UserInfo::getPassword() const {
    return password;
}

void UserInfo::setPassword(const QString &password) {
    UserInfo::password = password;
}

UserInfo::UserInfo(const QString &signUpTime, const QString &username, const QString &password, int level,
                   int score) : signUpTime(signUpTime), username(username), password(password),
                                level(level), score(score) {}

const QJsonObject &UserInfo::toQJsonObject() const {
    QJsonObject *result = new QJsonObject;
    (*result)["username"] = username;
    (*result)["password"] = password;
    (*result)["signUpTime"] = signUpTime;
    (*result)["level"] = level;
    (*result)["score"] = score;
    return *result;
}

UserInfo::UserInfo(const QJsonObject &userObject) {
    signUpTime = userObject["signUpTime"].toString();
    username = userObject["username"].toString();
    password = userObject["password"].toString();
    level = userObject["level"].toInt();
    score = userObject["score"].toInt();
}

bool UserInfo::operator<(const UserInfo &rhs) const {
    return !score < rhs.score;
}

UserInfo::UserInfo() = default;
