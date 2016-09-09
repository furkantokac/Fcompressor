#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSelectFolder_clicked()
{
    targetPath = QFileDialog::getExistingDirectory(this, "Select a Folder");
    ui->lneSelectedFolder->setText(targetPath);
}

void MainWindow::on_btnCompress_clicked()
{
    savePath = dirDesktop+ui->lneFileName->text();//QFileDialog::getExistingDirectory(this, "Select Save Path");
    targetPath = ui->lneSelectedFolder->text();
    compressor.compressFolder(targetPath, savePath);
    ui->statusBar->showMessage("Successfully compressed.", 3000);
}

void MainWindow::on_btnSelectFile_clicked()
{
    targetPath = QFileDialog::getOpenFileName(this, "Select a Folder");
    ui->lneSelectedFolder->setText(targetPath);
}

void MainWindow::on_btnExtract_clicked()
{
    savePath = dirDesktop+ui->lneFileName->text();
    targetPath = ui->lneSelectedFolder->text();
    compressor.decompressFolder(targetPath, savePath);
    ui->statusBar->showMessage("Successfully extracted.", 3000);
}
