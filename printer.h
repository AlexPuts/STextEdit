#ifndef PRINTER_H
#define PRINTER_H
#pragma once
#include <QWidget>
#include <docwindow.h>
class QPrinter;
class QPaintDevice;

class Printer : public QWidget
{
    Q_OBJECT
private:
    QPrinter *printer;

public:
    Printer(QWidget *parent = nullptr);
    DocWindow *window;
    virtual ~Printer();
protected:

    void draw(DocWindow *window);
signals:

public slots:
    void slotPrint();
};

#endif // PRINTER_H
