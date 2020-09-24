#include "subtext.h"

subText::subText(QWidget *parent) : QTextEdit(parent)
{
    isEdit = false;
    this->filename.clear();
    myFile = new QFile(this);

}
void subText::NewFile(){
    static int index = 1;
    QString title = QString ("未命名的文档[%1][*]").arg(index);
    this->setWindowTitle(title);
    index++;
     //启用编辑信号
    connect(this->document(),SIGNAL(contentsChanged()),this,SLOT(contentsChange()));

}
void subText::OpenFile(){
    QString filename = QFileDialog::getOpenFileName(this,"获取文本文件",".","Text(*.cpp *.h *.txt)");
    if(filename.isEmpty()){
        return;
    }

    //把文件路径保存，文件设置到窗体
    this->filename = filename;

    /*落伍
    QStringList list = filename.split("/");
    QString title = list.at(list.length()-1);
    this->setWindowTitle(title);
    */
    //第二种方法
    QFileInfo info(filename);
    QString title = QString ("[%1][*]").arg(info.fileName());
    this->setWindowTitle(title);
    //启用编辑信号
   connect(this->document(),SIGNAL(contentsChanged()),this,SLOT(contentsChange()));
    //对文件进行操作流方式
    myFile->setFileName(filename);
    bool ret = myFile->open(QIODevice::ReadOnly|QIODevice::Text);
    if(!ret){
        QMessageBox::warning(this,"文件失败","打开文件失败");
        return;
    }
    QTextStream stream(myFile);
    stream.setCodec(this->codeName.toLocal8Bit().data());
    while (!stream.atEnd()) {
        QString str = stream.readLine();
        this->append(str);
    }
    myFile->close();
}
int subText::SaveFile(){
    int ret = -1;
       if(!isEdit){
           return ret;
       }
       if(this->filename.isEmpty()){
           QString filename = QFileDialog::getSaveFileName(this,"保存提示",".","Text(*.cpp *.h *.txt)");
           if(filename.isEmpty()){
               return ret;
           }
       this->filename = filename;
       }
       myFile->setFileName(this->filename);
       bool result = myFile->open(QIODevice::WriteOnly|QIODevice::Text);
       if(!result){
           QMessageBox::warning(this,"失败提示","打开文件失败");
           return ret;
       }
       QTextStream stream(myFile);
       stream.setCodec(this->codeName.toLocal8Bit().data());
       stream<< this->toPlainText();
       stream.flush();
       myFile->close();
       this->setWindowModified(false);
       isEdit = false;
       QMessageBox::information(this,"提示成功","文件保存成功");
       ret = 0;
       return ret;
}
void subText::SaveAsFile(){
    bool isEdit = this->isEdit;
    this->isEdit = true;
    QString filename = this->filename;
    this->filename.clear();
    int ret = SaveFile();
    if(ret < 0){
        this->isEdit = isEdit;
        this->filename = filename;
    }
}

void subText::setCodeName(const QString codename){
    this->codeName = codename;
}
//slots
void subText::contentsChange(){
    isEdit = true;
    this->setWindowModified(true);
}
void subText::closeEvent(QCloseEvent *event){
    if(!isEdit){
        return;
    }
    QMessageBox::StandardButton ret = QMessageBox::information(this,"保存提示","你确定要保存？",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    if(ret == QMessageBox::Yes){
        SaveFile();
        event->accept();
    }
    else if(ret == QMessageBox::No){
        event->accept();
    }
    else{
        event->ignore();
    }
}
