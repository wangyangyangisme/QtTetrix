//
// Created by newcoderlife on 17-9-20.
//

#include "userinfo.h"

#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>

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

int UserInfo::getMaxScore() const {
    return maxScore;
}

void UserInfo::setMaxScore(int maxScore) {
    if (UserInfo::maxScore < maxScore)
        UserInfo::maxScore = maxScore;
}

const QString &UserInfo::getUsername() const {
    return username;
}

const QString &UserInfo::getPassword() const {
    return password;
}

UserInfo::UserInfo(const QString &signUpTime, const QString &username, const QString &password, int level,
                   int score) : username(username), password(password),
                                level(level), score(score), maxScore(0) {}

const QJsonObject &UserInfo::toQJsonObject() const {
    QJsonObject *result = new QJsonObject;
    (*result)["username"] = username;
    (*result)["password"] = password;
    (*result)["level"] = level;
    (*result)["score"] = score;
    (*result)["maxScore"] = maxScore;
    QJsonArray signInArray, signOutArray;
    for (const QString &singleSignInTime : signInTimes)
        signInArray.append(QJsonValue(singleSignInTime));
    for (const QString &singleSignOutTime : signOutTimes)
        signOutArray.append(QJsonValue(singleSignOutTime));
    (*result)["signInTimes"] = signInArray;
    (*result)["signOutTimes"] = signOutArray;
    return *result;
}

UserInfo::UserInfo(const QJsonObject &userObject) {
    for (QJsonValueRef singleUserTimeRef : userObject["signInTimes"].toArray())
        signInTimes.push_back(singleUserTimeRef.toString());
    for (QJsonValueRef singleUserValueRef : userObject["signOutTimes"].toArray())
        signOutTimes.push_back(singleUserValueRef.toString());
    username = userObject["username"].toString();
    password = userObject["password"].toString();
    level = userObject["level"].toInt();
    score = userObject["score"].toInt();
    maxScore = userObject["maxScore"].toInt();
}

bool UserInfo::operator<(const UserInfo &rhs) const {
    return maxScore >= rhs.maxScore;
}

UserInfo::UserInfo() = default;
