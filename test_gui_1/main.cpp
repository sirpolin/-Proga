#include "mainwindow.h"
#include <QApplication>

#include <QPixmap>
#include <QFile>
#include <QPicture>
#include <QPainter>
#include <QBrush>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pic (200, 200);
    QFile file("govno.png");
    file.open(QIODevice::WriteOnly);
    pic.save(&file, "PNG");
    return a.exec();
    return 0;
}
