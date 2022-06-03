#ifndef MAINUIFORM_H
#define MAINUIFORM_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <_APL/addRef/referadd.h>

QT_BEGIN_NAMESPACE
namespace Ui { class mainUIForm; }
QT_END_NAMESPACE

class mainUIForm : public QMainWindow
{
    Q_OBJECT

public:
    mainUIForm(QWidget *parent = nullptr);
    ~mainUIForm();

    void fillTable();

    ReferAdd* m_refadd = nullptr;

    void TableToJson(QString _file);

private slots:
    void on_lineEdit_textChanged(const QString &arg1);
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);
    void on_action_O_triggered();
    void on_action_N_triggered();
    void on_action_S_triggered();

private:
    Ui::mainUIForm *ui;
};
#endif // MAINUIFORM_H
