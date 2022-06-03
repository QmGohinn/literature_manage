#include "referadd.h"
#include "ui_referadd.h"

#include <_BK/Global/exeGlobal.h>

#include <QMessageBox>

ReferAdd::ReferAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReferAdd)
{
    ui->setupUi(this);
}

ReferAdd::~ReferAdd()
{
    delete ui;
}

void ReferAdd::clearThis()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
}

void ReferAdd::on_pushButton_2_clicked()
{
    QDialog::reject();
}

void ReferAdd::on_pushButton_clicked()
{
    if(ui->lineEdit->text() == ""
            || ui->lineEdit_2->text() == ""
            || ui->lineEdit_3->text() == ""
            || ui->lineEdit_4->text() == ""
            || ui->lineEdit_5->text() == ""
            || ui->lineEdit_6->text() == "")
    {
        QMessageBox::warning(this, "提 示", "信息不能有空项!", "知道了");
        return;
    }

    for(auto & _it : PRMS::g_referenceList){
        if(_it.getDOI().compare(ui->lineEdit->text()) == 0){
            QMessageBox::warning(this, "提 示", "已存在的DoI!", "知道了");
            return;
        }
    }

    Reference* _tmp = new Reference(ui->lineEdit->text(),
                                    ui->lineEdit_2->text(),
                                    ui->lineEdit_3->text(),
                                    ui->lineEdit_4->text(),
                                    ui->lineEdit_5->text(),
                                    ui->lineEdit_6->text());

    PRMS::g_referenceList.push_back(*_tmp);
    QDialog::accept();
}
