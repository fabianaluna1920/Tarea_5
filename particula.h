#ifndef PARTICULA_H
#define PARTICULA_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <iostream>
#include <math.h>

using namespace std;

class Particula : public QGraphicsItem
{
public:
    Particula(float x, float y, float velx, float vely, float r);
    void moverParticula(float dt, float vertlim);
    void colisionParticula(float horzlim, float vertlim);
    ~Particula();

protected:
    float px;  //Variable para la posicion en x de la particula
    float py;  //Variable para la posicion en y de la particula
    float vx;  //Variable para la velocidad en x de la particula
    float vy;  //Variable para la velocidad en y de la particula
    float rad; //Variable para el radio de la particula

                                //Estos metodos: boundingRect y paint se deben implementar, ya que son metodos virtuales puros en la clase QGraphicsItem
    QRectF boundingRect() const; //Este metodo debe implementarse para encerrar la figura en un rectangulo

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //Se implementa para dar formato a la figura

};

#endif // PARTICULA_H
