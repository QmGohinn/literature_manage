#include "mainuiform.h"
#include "ui_mainuiform.h"

#include <_BK/Global/exeGlobal.h>
#include <QMessageBox>
#include <QFileDialog>

mainUIForm::mainUIForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainUIForm)
{
    ui->setupUi(this);

    if(PRMS::g_currentRole){
        ui->statusbar->showMessage("您现在是管理员权限!");
    }
    else{
        ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
        ui->statusbar->showMessage("您现在是普通权限!");
    }

    this->showMaximized();

    ui->tableWidget->setColumnWidth(0, 400);
    ui->tableWidget->setColumnWidth(1, 300);
    ui->tableWidget->setColumnWidth(2, 700);
    ui->tableWidget->setColumnWidth(3, 200);
    ui->tableWidget->setColumnWidth(4, 150);

    fillTable();
}

mainUIForm::~mainUIForm()
{
    delete ui;
}

void mainUIForm::fillTable()
{
    while (ui->tableWidget->rowCount()) {
        ui->tableWidget->removeRow(0);
    }

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

void mainUIForm::TableToJson(QString _file)
{
    /// table 传入json文件
    QFile file(_file);
    file.open(QIODevice::ReadWrite);
    QByteArray data = file.readAll();

    file.resize(0);

    QJsonArray _array;
    QJsonObject _root;

    for(int i = 0; i < ui->tableWidget->rowCount(); ++i){

        QJsonObject _leaf;

        _leaf.insert("doi", ui->tableWidget->item(i, 0)->text());
        _leaf.insert("author", ui->tableWidget->item(i, 1)->text());
        _leaf.insert("title", ui->tableWidget->item(i, 2)->text());
        _leaf.insert("journal", ui->tableWidget->item(i, 3)->text());
        _leaf.insert("year", ui->tableWidget->item(i, 4)->text());
        _leaf.insert("type", ui->tableWidget->item(i, 5)->text());

        _array.append(_leaf);
    }

    _root.insert("Reference", _array);

    //初始化JsonDocument
    QJsonDocument jsonDocument;
    jsonDocument.setObject(_root);

    //JsonDocument转为ByteArray
    QByteArray byteArray = jsonDocument.toJson(QJsonDocument::Indented);
    QString _jsonStr(byteArray.data());
    file.write(_jsonStr.toUtf8());
    file.close();
}

void mainUIForm::on_lineEdit_textChanged(const QString &arg1)
{
    while (ui->tableWidget->rowCount()) {
        ui->tableWidget->removeRow(0);
    }

    for(auto & _it : PRMS::g_referenceList){
        if(_it.getDOI().contains(arg1) || _it.getAuthor().contains(arg1)
                || _it.getTitle().contains(arg1) || _it.getJournal().contains(arg1)
                || _it.getYear().contains(arg1) || _it.getType().contains(arg1)){
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

void mainUIForm::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    if(PRMS::g_currentRole == 0){
        return;
    }

    if(QMessageBox::information(this, "提 示", "请选择删除还是维护该条信息!", "维护信息", "删除") == 0){
        return;
    }
    else{
        QString _doi = ui->tableWidget->item(item->row(), 0)->text();
        ui->tableWidget->removeRow(item->row());
        for(int i = 0; i < PRMS::g_referenceList.size(); ++i){
            if(PRMS::g_referenceList.at(i).getDOI().compare(_doi) == 0){
                PRMS::g_referenceList.removeAt(i);
            }
        }
        return;
    }
}

void mainUIForm::on_action_O_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("选择导入文件"), tr("..\\json"), QStringLiteral("*.json"));
    if(filePath.isEmpty())
    {
        return;
    }

    PRMS::readReferenceFromJson(filePath);
    fillTable();
}

void mainUIForm::on_action_N_triggered()
{
    if(m_refadd == nullptr){
        m_refadd = new ReferAdd;
    }

    m_refadd->clearThis();
    m_refadd->setWindowTitle("文献添加");

    if(m_refadd->exec() == QDialog::Accepted){
        fillTable();
    }
}

void mainUIForm::on_action_S_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("选择保存路径"), tr("..\\json"), QStringLiteral("*.json"));
    if(filePath.isEmpty())
    {
        return;
    }

    this->TableToJson(filePath);
}
