#include "Tank.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"

Tank::Tank(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    QPixmap tankPixmap(":/images/Tanque.png");
    tankPixmap = tankPixmap.scaled(50, 50, Qt::KeepAspectRatio); // Escalar la imagen
    setPixmap(tankPixmap);
}

void Tank::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0)
            setPos(x() - 10, y());
    } else if (event->key() == Qt::Key_Right) {
        if (pos().x() + pixmap().width() < scene()->width())
            setPos(x() + 10, y());
    } else if (event->key() == Qt::Key_Space) {
        shoot();
    }
}

void Tank::shoot() {
    Bullet *bullet = new Bullet();
    bullet->setPos(x() + pixmap().width()/2 - bullet->pixmap().width()/2, y());
    scene()->addItem(bullet);
}
