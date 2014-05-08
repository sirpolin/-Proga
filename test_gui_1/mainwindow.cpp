#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(press_button_1()));
}

void MainWindow::press_button_1()
{
    QPixmap pic (2, 2);
    QFile file("yourFile.png");
    file.open(QIODevice::WriteOnly);
    pic.save(&file, "PNG");
    return;
}

MainWindow::~MainWindow()
{
    delete ui;
}
