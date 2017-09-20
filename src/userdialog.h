//
// Created by newcoderlife on 17-9-19.
//

#ifndef QTTETRIX_USERDIALOG_H
#define QTTETRIX_USERDIALOG_H

#include <QtWidgets/QDialog>

class QLineEdit;

class UserManager;

class UserDialog : public QDialog {
Q_OBJECT

public:
    explicit UserDialog(QWidget *parent = nullptr);

    void signIn();

    void signUp();

    void onPushButtonClicked();

signals:

    void sendSignInInfo(const QString &username, const QString &password);

    void sendSignUpInfo(const QString &username, const QString &password);

private:
    QLineEdit *usernameLineEdit, *passwordLineEdit;
    QPushButton *pushButton;
};

#endif //QTTETRIX_USERDIALOG_H
