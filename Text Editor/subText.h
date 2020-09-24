#ifndef SUBTEXT_H
#define SUBTEXT_H

#include <QWidget>
#include <QTextEdit>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QCloseEvent>


class subText : public QTextEdit
{
    Q_OBJECT
public:
    explicit subText(QWidget *parent = 0);
    void NewFile();//新建窗口
    void OpenFile();//打开文件
    void setCodeName(const QString codename);
    int SaveFile();
    void SaveAsFile();

signals:
protected:
    void closeEvent(QCloseEvent *);

private slots:
    void contentsChange();
private:
    QString filename;
    QFile *myFile;
    QString codeName;
    bool isEdit;

};

#endif // SUBTEXT_H
