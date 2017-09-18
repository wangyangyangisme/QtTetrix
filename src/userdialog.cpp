//
// Created by newcoderlife on 17-9-19.
//

#include "userdialog.h"

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFormLayout>

UserDialog::UserDialog(QWidget *parent) : QDialog(parent) {
    usernameLineEdit = new QLineEdit(tr("请输入用户名"), this);
    passwordLineEdit = new QLineEdit(tr("请输入密码"), this);
    pushButton = new QPushButton(this);

    QFormLayout *layout = new QFormLayout(this);
    layout->addRow(tr("账号"), usernameLineEdit);
    layout->addRow(tr("密码"), passwordLineEdit);
    layout->addRow(pushButton);

    setLayout(layout);
}

void UserDialog::save(QWidget *parent) {
    UserDialog userDialog(parent);
    userDialog.setWindowTitle(tr("保存"));
    if (QMessageBox::question(parent, tr("请选择"), tr("注册或登录"), tr("注册"), tr("登录"), 0, 1) == 0)
        userDialog.pushButton->setText(tr("注册"));
    else
        userDialog.pushButton->setText(tr("登录"));
    userDialog.exec();
}

void UserDialog::load(QWidget *parent) {
    UserDialog userDialog(parent);
    userDialog.setWindowTitle(tr("读取"));
    if (QMessageBox::question(parent, tr("请选择"), tr("注册或登录"), tr("注册"), tr("登录"), 0, 1) == 0)
        userDialog.pushButton->setText(tr("注册"));
    else
        userDialog.pushButton->setText(tr("登录"));
    userDialog.exec();
}
