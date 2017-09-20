//
// Created by newcoderlife on 17-9-19.
//

#include "usermanager.h"
#include "userinfo.h"

#include <QtCore/QFile>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonObject>
#include <QtCore/QDateTime>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QTableWidgetItem>

void UserManager::auth(const QString &username, const QString &password) {
    for (UserInfo &user : userVector) {
        if (user.getUsername() == username && user.getPassword() == password) {
            currentUser = &user;
            showLogInSuccess(tr("登录"));
            emit scoreChanged(currentUser->getScore());
            emit levelChanged(currentUser->getLevel());
            return;
        }
    }
    QMessageBox::warning(nullptr, tr("警告"), tr("用户名不存在或密码错误！"));
}

void UserManager::newUser(const QString &username, const QString &password) {
    for (UserInfo &user : userVector) {
        if (user.getUsername() == username) {
            QMessageBox::warning(nullptr, tr("警告"), tr("该用户已存在！"));
            return;
        }
    }
    userVector.append(UserInfo(QDateTime::currentDateTime().toString(), username, password, 0, 0));
    currentUser = &userVector.back();
    handleRankTable(0);
    showLogInSuccess(tr("注册"));
}

UserManager::UserManager(QObject *parent) : currentUser(), QObject(parent) {
    QFile userFile("user.dat");
    userFile.open(QIODevice::ReadOnly);
    QJsonArray userArray(QJsonDocument::fromJson(userFile.readAll()).object()["users"].toArray());
    for (size_t i = 0; i < userArray.size(); i++) {
        UserInfo user(userArray[i].toObject());
        userVector.push_back(user);
    }
    userFile.close();

    connect(this, &UserManager::scoreChanged, this, &UserManager::handleRankTable);
}

UserManager::~UserManager() {
    QFile userFile("user.dat");
    userFile.open(QIODevice::WriteOnly);
    QJsonObject saveDoc;
    QJsonArray userArray;
    for (UserInfo &user : userVector)
        userArray.append(user.toQJsonObject());
    saveDoc["users"] = userArray;
    userFile.write(QJsonDocument(saveDoc).toJson());
    userFile.close();
}

const QVector<UserInfo> &UserManager::getUserVector() const {
    return userVector;
}

const UserInfo &UserManager::getCurrentUser() const {
    return *currentUser;
}

void UserManager::setCurrentScore(int currentScore) {
    currentUser->setScore(currentScore);
}

void UserManager::setCurrentLevel(int currentLevel) {
    currentUser->setLevel(currentLevel);
}

void UserManager::showLogInSuccess(const QString &text) {
    QMessageBox::information(nullptr, text, tr("%1成功！").arg(text));
    emit logInSuccess(false);
}

void UserManager::handleRankTable(int) {
    QVector<UserInfo> rankList(userVector);
    std::sort(rankList.begin(), rankList.end());
    for (int i = 0; i < rankList.size(); i++) {
        emit rankListAddUser(i, 0, new QTableWidgetItem(rankList[i].getUsername()));
        emit rankListAddUser(i, 1, new QTableWidgetItem(tr("%1").arg(rankList[i].getScore())));
    }
}
