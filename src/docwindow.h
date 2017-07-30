#ifndef DOCWINDOW_H
#define DOCWINDOW_H

#pragma once
#include <QMainWindow>
#include <QTextEdit>
#include <QTextDocument>

class DocWindow : public QTextEdit
{
    Q_OBJECT
public:
    explicit DocWindow(QWidget *parent = nullptr);

    QTextDocument* text;
private:
    QString strFileName;
signals:
    void changeWindowTitle(const QString&);
public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotPrint();
    void slotUndo();
    void slotRedo();
    void slotCut();
    void slotCopy();
    void slotPaste();
};

#endif // DOCWINDOW_H
