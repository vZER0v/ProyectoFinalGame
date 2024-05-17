#include "Tank.h"
#include "Bullet.h"
#include <QGraphicsScene>
#include <QGraphicsItem>

Tank::Tank(QGraphicsItem *parent): QGraphicsRectItem(parent) {
    // Inicializa el tanque aquí
    setRect(0,0,50,50);
}

void Tank::keyPressEvent(QKeyEvent *event) {
    int stepSize = 10;
    switch (event->key()) {
        case Qt::Key_Left:
            if (pos().x() > 0) setPos(x() - stepSize, y());
            break;
        case Qt::Key_Right:
            if (pos().x() + rect().width() < scene()->width()) setPos(x() + stepSize, y());
            break;
        case Qt::Key_Up:
            if (pos().y() > 0) setPos(x(), y() - stepSize);
            break;
        case Qt::Key_Down:
            if (pos().y() + rect().height() < scene()->height()) setPos(x(), y() + stepSize);
            break;
        case Qt::Key_Space:
            shoot();
            break;
    }
}

void Tank::shoot() {
    // Implementar disparo
    Bullet *bullet = new Bullet();
    bullet->setPos(x(), y());
    scene()->addItem(bullet);
}
