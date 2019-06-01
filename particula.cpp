#include "Particula.h"


Particula::Particula(float x, float y, float velx, float vely, float r) : QGraphicsItem()  //Un constructor por defecto, que invoca al constructor de la clase base
{
    px = x;
    py = y;
    vx = velx;
    vy = vely;
    rad = r;
}

Particula::~Particula()  //Un destructor por defecto
{

}

QRectF Particula::boundingRect() const  //Implementacion del metodo boundingRect
{
    return QRectF(-1*rad,-1*rad,2*rad,2*rad);   // Creando el area rectangular para delimitar la Particula (es una particula circular)
}

void Particula::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)    //Implementacion del metodo paint
{
        painter->setBrush(Qt::blue);     // Color de relleno de la Particula
        painter->drawEllipse(boundingRect());// Dibujando la Particula con el metodo drawEllipse y aprovechando las propiedades del rectangulo delimitador
}

// Metodo para actualizar posicion particula
void Particula::moverParticula(float dt, float vertlim)//Metodo para actualizar la posicion de la particula.
{
    px += vx*dt;
    py += vy*dt;

    setPos(px,py);
}

//Metodo para verificar que sucedio colision
void Particula::colisionParticula(float horzlim, float vertlim)
{
    //Si la colision es con una barrera en sentido de avance horizontal (adelante o atras)
    if((px < rad) || (px > 500 - rad))
        vx = -1*vx;

    //Si la colision es con una barrera en sentido de avance vertical (arriba o abajo)
    if((py < rad) || (py > 500 - rad))
        vy = -1*vy;
}

