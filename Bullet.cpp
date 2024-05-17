#include "Bullet.h"
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsScene>

Bullet::Bullet(QGraphicsItem *parent): QGraphicsEllipseItem(parent) {
    // Inicializa el proyectil aquí
    setRect(0,0,5,20);
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move() {
    // Mueve el proyectil hacia arriba
    setPos(x(), y() - 10);
    if (pos().y() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
