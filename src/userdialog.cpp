//
// Created by newcoderlife on 17-9-19.
//

#include "userdialog.h"

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFormLayout>

UserDialog::UserDialog(QWidget *parent) : QDialog(parent) {
    QPalette *palette = new QPalette;
    palette->setBrush(QPalette::Background,
                      QBrush(QPixmap(":/images/background/1").scaled(size(), Qt::IgnoreAspectRatio,
                                                                     Qt::SmoothTransformation)));
    setAutoFillBackground(true);
    setPalette(*palette);

    usernameLineEdit = new QLineEdit(tr("请输入用户名"), this);
    passwordLineEdit = new QLineEdit(tr("请输入密码"), this);
    usernameLineEdit->setMaxLength(20);
    passwordLineEdit->setMaxLength(20);
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    pushButton = new QPushButton(this);

    QFormLayout *layout = new QFormLayout(this);
    layout->addRow(new QLabel(tr("")));
    layout->addRow(tr("账号"), usernameLineEdit);
    layout->addRow(new QLabel(tr("")));
    layout->addRow(tr("密码"), passwordLineEdit);
    layout->addRow(new QLabel(tr("")));
    layout->addRow(pushButton);
    setLayout(layout);

    connect(pushButton, &QPushButton::clicked, this, &UserDialog::onPushButtonClicked);
}

void UserDialog::signIn() {
    setWindowTitle(tr("登录"));
    pushButton->setText(tr("登录"));
    exec();
}

void UserDialog::signUp() {
    setWindowTitle(tr("注册"));
    pushButton->setText(tr("注册"));
    exec();
}

void UserDialog::onPushButtonClicked() {
    if (pushButton->text() == tr("注册")) {
        emit sendSignUpInfo(usernameLineEdit->text(), passwordLineEdit->text());
    } else {
        emit sendSignInInfo(usernameLineEdit->text(), passwordLineEdit->text());
    }
    this->close();
}
