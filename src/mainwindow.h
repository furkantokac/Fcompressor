#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <foldercompressor.h>
#include <QFileDialog>
#include <QDebug>
#include <QDir>
#include <QFileInfo>

#include <QStandardPaths>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnCompress_clicked();

    void on_btnExtract_clicked();

    void on_btnSelectFolder_clicked();

    void on_btnSelectFile_clicked();

private:
    Ui::MainWindow *ui;
    FolderCompressor compressor;
    QString targetPath;
    QString savePath;

    QString dirDesktop = QStandardPaths::writableLocation( QStandardPaths::DesktopLocation )+"/";
};

#endif // MAINWINDOW_H
