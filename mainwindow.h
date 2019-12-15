#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "simulation.h"
#include <QMainWindow>
#include <QTreeWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_info_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_Simulate_clicked();

    void on_start_sim_clicked();

private:
    std::vector<User*> users_to_simulate;
    Simulation s;
    void AddToSimulation(int user);
    void ViewUserInform(int user);
    void ViewProgramInform(int prog,std::string user);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
