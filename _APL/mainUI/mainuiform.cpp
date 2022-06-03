#include "mainuiform.h"
#include "ui_mainuiform.h"

#include <_BK/Global/exeGlobal.h>

mainUIForm::mainUIForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainUIForm)
{
    ui->setupUi(this);
    if(PRMS::g_currentRole){
        ui->statusbar->showMessage("您现在是管理员权限!");
    }
    else{
        ui->statusbar->showMessage("您现在是普通权限!");
    }
    this->showMaximized();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int i = 0;
    for(auto& _it : PRMS::g_referenceList){
        ui->tableWidget->insertRow(i);

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(_it.getDOI()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(_it.getAuthor()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(_it.getTitle()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(_it.getJournal()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(_it.getYear()));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(_it.getType()));
        ++i;
    }
}

mainUIForm::~mainUIForm()
{
    delete ui;
}


void mainUIForm::on_lineEdit_textChanged(const QString &arg1)
{
    while (ui->tableWidget->rowCount()) {
        ui->tableWidget->removeRow(0);
    }

    for(auto & _it : PRMS::g_referenceList){
        if(_it.getDOI().contains(arg1) == true){
            int i = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(i);

            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(_it.getDOI()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(_it.getAuthor()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(_it.getTitle()));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(_it.getJournal()));
            ui->tableWidget->setItem(i, 4, new QTableWidgetItem(_it.getYear()));
            ui->tableWidget->setItem(i, 5, new QTableWidgetItem(_it.getType()));
        }
    }
}
