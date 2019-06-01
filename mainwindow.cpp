#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "particula.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    timer = new QTimer(this);
    ui->setupUi(this);
    this->resize(600,720);
    this->setFixedSize(600,720);

    escena = new QGraphicsScene();
    ui->fondo->setScene(escena);

    escena->setSceneRect(-20,-20,540,540);

    particle = new Particula(100,300,15,10,17);  //Declarando un objeto grafico de la clase Part
    escena->addItem(particle); //Agregando el objeto grafico a la escena

    //darle color a el recuadro
   QPen mypen= QPen(Qt::red);


    //para que la parcula este dentro del recuadro que crea.
    QLineF TopLine(escena->sceneRect().topLeft(),escena->sceneRect().topRight());
    QLineF LeftLine(escena->sceneRect().topLeft(),escena->sceneRect().bottomLeft());
    QLineF RightLine(escena->sceneRect().topRight(),escena->sceneRect().bottomRight());
    QLineF BottomLine(escena->sceneRect().bottomLeft(),escena->sceneRect().bottomRight());

    escena->addLine(TopLine,mypen);
    escena->addLine(LeftLine,mypen);
    escena->addLine(RightLine,mypen);
    escena->addLine(BottomLine,mypen);

    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizarEscena()));

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizarEscena(void)
{
   particle->moverParticula(0.8,560);
   particle->colisionParticula(560,560);
}


void MainWindow::on_START_clicked()
{
    timer->start(50);
}
