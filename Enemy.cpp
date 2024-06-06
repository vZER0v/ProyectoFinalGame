#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {
    QPixmap enemyPixmap(":/images/Tanque_Enemigo.png");
    if (enemyPixmap.isNull()) {
        qDebug() << "Error: No se pudo cargar la imagen del enemigo.";
    }
    enemyPixmap = enemyPixmap.scaled(50, 50, Qt::KeepAspectRatio); // Escalar la imagen
    setPixmap(enemyPixmap);
    qDebug() << "Enemigo creado en posición: " << pos();

    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(autoMove()));
    moveTimer->start(1000);

    QTimer *shootTimer = new QTimer(this);
    connect(shootTimer, SIGNAL(timeout()), this, SLOT(shoot()));
    shootTimer->start(2000); // Disparar cada 2 segundos
}

void Enemy::autoMove() {
    if (scene() == nullptr) return; // Verificar si la escena es nula
    setPos(x(), y() + 10);
    if (pos().y() > scene()->height()) {
        if (scene() != nullptr) {
            scene()->removeItem(this);
        }
        delete this;
    }
}

void Enemy::shoot() {
    if (scene() == nullptr) return; // Verificar si la escena es nula
    Bullet *bullet = new Bullet();
    bullet->setPos(x() + pixmap().width()/2 - bullet->pixmap().width()/2, y() + pixmap().height());
    bullet->setRotation(180);
    scene()->addItem(bullet);
    qDebug() << "Enemigo disparó desde posición: " << pos();
}
