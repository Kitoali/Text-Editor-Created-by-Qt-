#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}


//fun
void MainWindow::Init(){

    codeName = "UTF-8";
//文件操作
    connect(ui->action_New,SIGNAL(triggered(bool)),this,SLOT(void on_action_New_triggered(bool checked)));

    connect(ui->action_Open,SIGNAL(triggered(bool)),this,SLOT(void on_action_Open_triggered(bool checked)));

    connect(ui->actionUFT_8,SIGNAL(triggered(bool)),this,SLOT(void on_actionUFT_8_triggered(bool checked)));

    connect(ui->actionGB2312,SIGNAL(triggered(bool)),this,SLOT(void on_actionGB2312_triggered(bool checked)));

    connect(ui->actionGB2312,SIGNAL(triggered(bool)),this,SLOT(void on_action_Save_triggered(bool checked)));

    connect(ui->actionGB2312,SIGNAL(triggered(bool)),this,SLOT(void on_action_SaveAs_triggered(bool checked)));

    connect(ui->actionGB2312,SIGNAL(triggered(bool)),this,SLOT(void on_action_Exit_triggered(bool checked)));

//窗口操作
    connect(ui->actionGB2312,SIGNAL(triggered(bool)),this,SLOT(void on_action_Close_triggered(bool checked)));

    connect(ui->actionGB2312,SIGNAL(triggered(bool)),this,SLOT(void on_action_CloseAll_triggered(bool checked)));

    connect(ui->actionGB2312,SIGNAL(triggered(bool)),this,SLOT(void on_action_Put_triggered(bool checked)));

    connect(ui->actionGB2312,SIGNAL(triggered(bool)),this,SLOT(void on_action_Cover_triggered(bool checked)));

    connect(ui->actionGB2312,SIGNAL(triggered(bool)),this,SLOT(void on_action_Up_triggered(bool checked)));
//关于

    connect(ui->actionGB2312,SIGNAL(triggered(bool)),this,SLOT(void on_action_Next_triggered(bool checked)));

    connect(ui->actionGB2312,SIGNAL(triggered(bool)),this,SLOT(void on_action_Qt_Q_triggered(bool checked)));

//编辑
     connect(ui->actionGB2312,SIGNAL(triggered(bool)),this,SLOT(void on_action_Redo_triggered(bool checked)));

     connect(ui->actionGB2312,SIGNAL(triggered(bool)),this,SLOT(void on_action_Undo_triggered(bool checked)));

     connect(ui->actionGB2312,SIGNAL(triggered(bool)),this,SLOT(void on_action_Cut_triggered(bool checked)));

     connect(ui->actionGB2312,SIGNAL(triggered(bool)),this,SLOT(void on_action_Copy_triggered(bool checked)));

     connect(ui->actionGB2312,SIGNAL(triggered(bool)),this,SLOT(void on_action_Paste_triggered(bool checked)));
}

subText *MainWindow::getActiveChildForm(){
    subText *sub =NULL;
    QMdiSubWindow *subWin = ui->mdiArea->activeSubWindow();
    if(subWin == NULL )return sub;
    QWidget *wid = subWin->widget();
    if(wid == NULL)return sub;
    sub = (subText *)wid;
    return sub;
}
//event

//slots

//文件
void MainWindow::on_action_New_triggered(bool checked){
    subText *sub = new subText();

    ui->mdiArea->addSubWindow(sub);
    sub->setCodeName(codeName);
    sub->NewFile();
    sub->show();

}

void MainWindow::on_action_Open_triggered(bool checked){
    subText *sub = new subText();
    ui->mdiArea->addSubWindow(sub);
    sub->setCodeName(codeName);
    sub->OpenFile();
    sub->show();
}

void MainWindow::on_actionUFT_8_triggered(bool checked)
{
    this->codeName = "UTF-8";
}

void MainWindow::on_actionGB2312_triggered(bool checked)
{
    this->codeName = "GB18030";
}

void MainWindow::on_action_Save_triggered(bool checked)
{
    QMdiSubWindow *subWin = ui->mdiArea->activeSubWindow();
    if(subWin == NULL)return;
    QWidget *wid = subWin->widget();
    if(wid == NULL)return;
    subText *sub = (subText *)wid;
    if(sub == NULL)return;
    sub->SaveFile();
}

void MainWindow::on_action_SaveAs_triggered(bool checked)
{
    QMdiSubWindow *subWin = ui->mdiArea->activeSubWindow();
    if(subWin == NULL)return;
    QWidget *wid = subWin->widget();
    if(wid == NULL)return;
    subText *sub = (subText *)wid;
    if(sub == NULL)return;
    sub->SaveAsFile();

}


void MainWindow::on_action_Exit_triggered(bool checked)
{
    this->close();
}
//窗口
void MainWindow::on_action_Close_triggered(bool checked)
{
    ui->mdiArea->closeActiveSubWindow();
}

void MainWindow::on_action_CloseAll_triggered(bool checked)
{
    ui->mdiArea->closeAllSubWindows();
}

void MainWindow::on_action_Put_triggered(bool checked)
{
    ui->mdiArea->tileSubWindows();
}

void MainWindow::on_action_Cover_triggered(bool checked)
{
    ui->mdiArea->cascadeSubWindows();
}

void MainWindow::on_action_Up_triggered(bool checked)
{
    ui->mdiArea->activatePreviousSubWindow();
}

void MainWindow::on_action_Next_triggered(bool checked)
{
    ui->mdiArea->activateNextSubWindow();
}
//关于
void MainWindow::on_action_About_triggered(bool checked)
{
    QMessageBox::about(this,"关于作者","owned by kito");
}

void MainWindow::on_action_Qt_Q_triggered(bool checked)
{
    QMessageBox::aboutQt(this,"关于Qt");
}
//编辑
void MainWindow::on_action_Redo_triggered(bool checked)
{
    subText *sub = getActiveChildForm();
    if(sub != NULL){
        sub->redo();
    }
}

void MainWindow::on_action_Undo_triggered(bool checked)
{
    subText *sub = getActiveChildForm();
    if(sub != NULL){
        sub->undo();
    }
}

void MainWindow::on_action_Cut_triggered(bool checked)
{
    subText *sub = getActiveChildForm();
    if(sub != NULL){
        sub->cut();
    }
}

void MainWindow::on_action_Copy_triggered(bool checked)
{
    subText *sub = getActiveChildForm();
    if(sub != NULL){
        sub->copy();
    }
}

void MainWindow::on_action_Paste_triggered(bool checked)
{
    subText *sub = getActiveChildForm();
    if(sub != NULL){
        sub->paste();
    }

}
