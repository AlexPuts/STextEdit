#include "src/printer.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include "src/docwindow.h"
Printer::Printer(QWidget *parent) : QWidget(parent)
{
    printer = new QPrinter;
}

Printer::~Printer()//implement virtual destrctor
{
    delete printer;
}

void Printer::slotPrint()
{
    QPrintDialog printDialog(printer, this);
    if(printDialog.exec()==QDialog::Accepted)
    {
        draw(window);
    }
}

void Printer::draw(DocWindow* window)
{
    QTextDocument doc(window->toPlainText(),nullptr);
    doc.print(printer);
}
