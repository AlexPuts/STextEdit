#include "forms/mainwindow.h"
#include <QApplication>
#include "printer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    w.setWindowTitle("Text editor");
    w.resize(500, 700);
    w.show();


    return a.exec();
}
