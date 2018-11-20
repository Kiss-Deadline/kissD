#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void loadData();
    void doLayout();

private:
    QTableView *m_pQTableView;
    QStandardItemModel *m_pModel;

};

#endif // MAINWINDOW_H
