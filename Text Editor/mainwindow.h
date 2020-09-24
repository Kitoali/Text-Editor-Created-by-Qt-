#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "subText.h"

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
    void on_action_New_triggered(bool checked);

    void on_action_Open_triggered(bool checked);

    void on_actionUFT_8_triggered(bool checked);

    void on_actionGB2312_triggered(bool checked);

    void on_action_Save_triggered(bool checked);

    void on_action_SaveAs_triggered(bool checked);

    void on_action_Exit_triggered(bool checked);

    void on_action_Close_triggered(bool checked);

    void on_action_CloseAll_triggered(bool checked);

    void on_action_Put_triggered(bool checked);

    void on_action_Cover_triggered(bool checked);

    void on_action_Up_triggered(bool checked);

    void on_action_Next_triggered(bool checked);

    void on_action_About_triggered(bool checked);

    void on_action_Qt_Q_triggered(bool checked);

    void on_action_Redo_triggered(bool checked);

    void on_action_Undo_triggered(bool checked);

    void on_action_Cut_triggered(bool checked);

    void on_action_Copy_triggered(bool checked);

    void on_action_Paste_triggered(bool checked);

private:
    Ui::MainWindow *ui;
    QString codeName;
    void Init();
    subText *getActiveChildForm();

};
#endif // MAINWINDOW_H
