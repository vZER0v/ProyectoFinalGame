#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>


Enemy::Enemy(QGraphicsItem *parent): QObject(), Tank(parent) {
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(autoMove()));
    timer->start(1000);
}
void Enemy::autoMove() {
    // Aca se implementa movimientos automáticos y disparos del enemigo aquí
    // Esto es solo un ejemplo,
    setPos(x(), y() + 10);
    if (pos().y() > scene()->height()) {
        scene()->removeItem(this);
        delete this;
    }
}
