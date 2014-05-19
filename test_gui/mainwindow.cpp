#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Add_Text()));
}

void MainWindow::Add_Text()
{
//    ui->textEdit->append(QString("ololo"));
    int a;
    QString str("321");
    a = str.toInt();
    ui->textEdit->append(str);
    ui->textEdit_2->append(ui->textEdit->toPlainText());

}

MainWindow::~MainWindow()
{
    delete ui;
}
