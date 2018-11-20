#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    m_pQTableView = new QTableView(this);
    m_pModel = new QStandardItemModel(this);
    loadData();//之后挪到model中
    m_pQTableView->setModel(m_pModel);
}

MainWindow::~MainWindow()
{

}

void MainWindow::loadData()
{
    //构造部门数据
    for (int i = 0; i < 10; ++i)
    {
        QList<QStandardItem*> empt;
        QStandardItem *IDItem = new QStandardItem("00" + intToStr(i));
        empt.append(IDItem);
        QStandardItem *nameItem = new QStandardItem(TRANS_STRING("技术开发部"));
        empt.append(nameItem);
        QStandardItem *sexItem = new QStandardItem();
        sexItem->setData(QVariant(QVariant::Bool), Qt::EditRole);
        empt.append(sexItem);

        //构造员工zhangsk数据
        QList<QStandardItem*> pEmployeeZhangskColumn;
        pEmployeeZhangskColumn.append(new QStandardItem(intToStr(i)));
        pEmployeeZhangskColumn.append(new QStandardItem(TRANS_STRING("张树坤")));

        //Sex
        QStandardItem *pZhangskSex = new QStandardItem();
        pZhangskSex->setData(true, Qt::EditRole);
        pEmployeeZhangskColumn.append(pZhangskSex);

        //Age
        QStandardItem *pZhangskAge = new QStandardItem();
        pZhangskAge->setData(30, Qt::EditRole);
        pEmployeeZhangskColumn.append(pZhangskAge);

        //增加到部门列表中
        IDItem->appendRow(pEmployeeZhangskColumn);
        m_model->appendRow(empt);
    }
    m_model->setHeaderData(0, Qt::Horizontal, TRANS_STRING("编号"));
    m_model->setHeaderData(1, Qt::Horizontal, TRANS_STRING("部门"));
    m_model->setHeaderData(2, Qt::Horizontal, TRANS_STRING("性别"));
}

void MainWindow::doLayout()
{

}
