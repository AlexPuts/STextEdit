#include "src/docwindow.h"

#include <QFileDialog>
#include <QTextStream>
#include <QPlainTextEdit>
#include "src/printer.h"

DocWindow::DocWindow(QWidget *parent) : QTextEdit(parent)
{
    text = new QTextDocument;
    text->setPlainText(this->toPlainText());
}

void DocWindow::slotLoad()
{
    QString fileName = QFileDialog::getOpenFileName();
    if(fileName.isEmpty()) return;
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();
        strFileName = fileName;
        emit changeWindowTitle(strFileName);
    }
}


void DocWindow::slotSaveAs()
{
    QString fileName = QFileDialog::getSaveFileName(0,strFileName);
    if(!fileName.isEmpty())
    {
        strFileName = fileName;
        slotSave();
    }
}

void DocWindow::slotSave()
{
    if(strFileName.isEmpty())
    {
        slotSaveAs();
        return;
    }

    QFile file (strFileName);
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream(&file)<<toPlainText();
        file.close();
        emit changeWindowTitle(strFileName);
    }
}

void DocWindow::slotPrint()
{
    Printer* printer = new Printer;
    printer->window = this;
    printer->slotPrint();
}

void DocWindow::slotUndo()
{
    this->undo();
}
void DocWindow::slotRedo()
{
    this->redo();
}

void DocWindow::slotCut()
{
    this->cut();
}

void DocWindow::slotCopy()
{
    this->copy();
}

void DocWindow::slotPaste()
{
    this->paste();
}
