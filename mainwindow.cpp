#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vector>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    s.generateSimulation();
    ui->setupUi(this);
    ui->info->setDisabled(true);
    ui->Simulate->setDisabled(true);
    std::vector<QTreeWidgetItem*> users;
    for(auto i :s.users){
        users.push_back(new QTreeWidgetItem());
        users[users.size()-1]->setText(0,QString::fromStdString(i->getName()));
        for(auto j:i->used_program){
            QTreeWidgetItem * temp = new QTreeWidgetItem();
            temp->setText(0,QString::fromStdString(j.first->getName()));
            users[users.size()-1]->addChild(temp);
        }
    }
    for(auto i:users){
        ui->treeWidget->addTopLevelItem(i);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::ViewUserInform(int user){
    ui->Items->clear();
    ui->Name->setText(QString::fromStdString(s.users[user]->getName()));
    std::map<Program*,int>::iterator it = s.users[user]->used_program.begin();
     for(int i=0;i<s.users[user]->used_program.size();i++){
       ui->Items->addItem(QString::fromStdString(it->first->getName()));
       std::advance( it,  1);
    }
}
void MainWindow::ViewProgramInform(int prog,std::string user){
    ui->Items->clear();
    for(auto i :s.users){
        if(i->getName()==user){
            std::map<Program*,int>::iterator it = i->used_program.begin();
            std::advance( it,  prog);
            ui->Name->setText(QString::fromStdString(it->first->getName()));
            for(auto j:it->first->errors){
                ui->Items->addItem(QString::fromStdString(j->error_type));
            }
        }

    }
}
void MainWindow::AddToSimulation(int user){
    for(auto i:users_to_simulate){
        if(i==s.users[user]) return;
    }
    users_to_simulate.push_back(s.users[user]);
    ui->simulation_list->addItem(QString::fromStdString (s.users[user]->getName()));
    return;
}
void MainWindow::on_info_clicked(){
    if(ui->treeWidget->currentItem()->childCount()==0){
        ViewProgramInform(ui->treeWidget->currentIndex().row(),ui->treeWidget->currentItem()->parent()->text(0).toStdString());
    }
    else{
        ViewUserInform(ui->treeWidget->currentIndex().row());
    }
}
void MainWindow::on_pushButton_clicked(){

}
void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column){
    ui->info->setDisabled(false);
    ui->Simulate->setDisabled(false);
}

void MainWindow::on_Simulate_clicked(){
    if(ui->treeWidget->currentItem()->childCount()!=0){
        AddToSimulation(ui->treeWidget->currentIndex().row());
    }
}

void MainWindow::on_start_sim_clicked(){
    ui->all_errors->clear();
    Simulation new_sim;
    for(auto i:users_to_simulate){
        new_sim.addUser(i);
    }
    std::pair<std::vector<Error*>,int> result = new_sim.work(ui->time->value()) ;
    for(auto i:result.first){
        ui->all_errors->addItem(QString::fromStdString(i->error_type));
    }
    ui->error_time->setNum(result.second);
}

void MainWindow::on_clear_clicked()
{
    ui->simulation_list->clear();
    users_to_simulate.clear();
}
