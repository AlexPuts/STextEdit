#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMenu>
#pragma once
#include <src/docwindow.h>
#include <QApplication>
#include<QMenuBar>
#include<QStatusBar>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0):QMainWindow(parent)
    {

    QMenu* pmnuFile = new QMenu("&File");
    QMenu* pmnuEdit = new QMenu("&Edit");
    QMenu* pmnuHelp = new QMenu("&Help");
    DocWindow* pdoc = new DocWindow;

    pmnuFile->addAction("&Open...",
                        pdoc,
                        SLOT(slotLoad()),
                        QKeySequence("CTRL+O")
                        );
    pmnuFile->addAction("&Save...",
                        pdoc,
                        SLOT(slotSave()),
                        QKeySequence("CTRL+S")
                        );
    pmnuFile->addAction("&Print...",
                        pdoc,
                        SLOT(slotPrint()),
                        QKeySequence("CTRL+P")
                        );

    pmnuFile->addSeparator();
    pmnuFile->addAction("&Quit",
                        qApp,
                        SLOT(quit()),
                        QKeySequence("CTRL+Q")
                        );
    pmnuHelp->addAction("&About",
                        this,
                        SLOT(slotAbout()),
                        Qt::Key_F1
                        );
    pmnuEdit->addAction("&Undo...",
                        pdoc,
                        SLOT(slotUndo()),
                        QKeySequence("CTRL+Z")
                        );
    pmnuEdit->addAction("&Redo...",
                        pdoc,
                        SLOT(slotRedo()),
                        QKeySequence("CTRL+Y")
                        );
    pmnuEdit->addSeparator();
    pmnuEdit->addAction("&Cut...",
                        pdoc,
                        SLOT(slotCut()),
                        QKeySequence("CTRL+X")
                        );
    pmnuEdit->addAction("&Copy...",
                        pdoc,
                        SLOT(slotCopy()),
                        QKeySequence("CTRL+C")
                        );
    pmnuEdit->addAction("&Paste...",
                        pdoc,
                        SLOT(slotPaste()),
                        QKeySequence("CTRL+V")
                        );
    menuBar()->addMenu(pmnuFile); 

    menuBar()->addMenu(pmnuEdit);
    menuBar()->addMenu(pmnuHelp);
    setCentralWidget(pdoc);
    connect(pdoc,
            SIGNAL(changeWindowTitle(const QString&)),
            SLOT(slotChangeWindowTitle(const QString&))
            );
    statusBar()->showMessage("Ready",2000);
}

public slots:
    void slotAbout()
    {
        QMessageBox::about(this, "Text editor", "Text editor");
    }

    void slotChangeWindowTitle(const QString& str)
    {
        setWindowTitle(str);
    }


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
