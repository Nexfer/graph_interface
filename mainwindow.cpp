#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cezar.h"
#include "vigenere.h"
#include "stegano.h"
#include "des.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->cezarButton, SIGNAL(clicked()), this, SLOT(cezarFunc()));
    QObject::connect(ui->vigenereButton, SIGNAL(clicked()), this, SLOT(vigenereFunc()));
    QObject::connect(ui->steganoButton, SIGNAL(clicked()), this, SLOT(steganoFunc()));
    QObject::connect(ui->desButton, SIGNAL(clicked()), this, SLOT(desFunc()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cezarFunc()
{
    cezar myCezar(this);
    myCezar.exec();
}

void MainWindow::vigenereFunc()
{
    vigenere myVigenere(this);
    myVigenere.exec();
}

void MainWindow::steganoFunc()
{
    stegano myStegano(this);
    myStegano.exec();
}

void MainWindow::desFunc()
{
    des myDes(this);
    myDes.exec();
}

