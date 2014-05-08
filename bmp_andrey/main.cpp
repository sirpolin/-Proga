#include <QCoreApplication>

#include <QPixmap>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QPixmap pic (2, 2);
    QFile file("yourFile.png");
    file.open(QIODevice::WriteOnly);
    pic.save(&file, "PNG");
    return a.exec();
}
