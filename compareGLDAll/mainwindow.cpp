#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    m_pQTableView = new QTableView(this);
    m_pModel = new QStandardItemModel(this);
    loadData();//֮��Ų��model��
    m_pQTableView->setModel(m_pModel);
}

MainWindow::~MainWindow()
{

}

void MainWindow::loadData()
{
    //���첿������
    for (int i = 0; i < 10; ++i)
    {
        QList<QStandardItem*> empt;
        QStandardItem *IDItem = new QStandardItem("00" + intToStr(i));
        empt.append(IDItem);
        QStandardItem *nameItem = new QStandardItem(TRANS_STRING("����������"));
        empt.append(nameItem);
        QStandardItem *sexItem = new QStandardItem();
        sexItem->setData(QVariant(QVariant::Bool), Qt::EditRole);
        empt.append(sexItem);

        //����Ա��zhangsk����
        QList<QStandardItem*> pEmployeeZhangskColumn;
        pEmployeeZhangskColumn.append(new QStandardItem(intToStr(i)));
        pEmployeeZhangskColumn.append(new QStandardItem(TRANS_STRING("������")));

        //Sex
        QStandardItem *pZhangskSex = new QStandardItem();
        pZhangskSex->setData(true, Qt::EditRole);
        pEmployeeZhangskColumn.append(pZhangskSex);

        //Age
        QStandardItem *pZhangskAge = new QStandardItem();
        pZhangskAge->setData(30, Qt::EditRole);
        pEmployeeZhangskColumn.append(pZhangskAge);

        //���ӵ������б���
        IDItem->appendRow(pEmployeeZhangskColumn);
        m_model->appendRow(empt);
    }
    m_model->setHeaderData(0, Qt::Horizontal, TRANS_STRING("���"));
    m_model->setHeaderData(1, Qt::Horizontal, TRANS_STRING("����"));
    m_model->setHeaderData(2, Qt::Horizontal, TRANS_STRING("�Ա�"));
}

void MainWindow::doLayout()
{

}
