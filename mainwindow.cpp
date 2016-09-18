#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("RRT - simulator");
    this->setFixedSize(1000,750);

    connect(ui->loadMapButton,SIGNAL(pressed()),ui->graphicsView,SLOT(loadMap()));
    connect(ui->startButton,SIGNAL(pressed()),ui->graphicsView,SLOT(startRRT()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape){
        this->close();
    }
}
