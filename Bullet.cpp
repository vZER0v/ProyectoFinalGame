#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Tank.h"
#include "Enemy.h"
#include "Game.h"
#include <QDebug>

extern Game *game; // Enlace externo a la instancia del juego

Bullet::Bullet(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    QPixmap bulletPixmap(":/images/Proyectil_Tanque.png");
    bulletPixmap = bulletPixmap.scaled(10, 30, Qt::KeepAspectRatio); // Escalar la imagen
    setPixmap(bulletPixmap);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move() {
    int step = 10;
    if (rotation() == 180) {
        setPos(x(), y() + step);
        if (pos().y() > scene()->height()) {
            if (scene() != nullptr) {
                scene()->removeItem(this);
            }
            delete this;
            return;
        }

        QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
        for (QGraphicsItem *item : collidingItems) {
            if (dynamic_cast<Tank *>(item)) {
                game->displayGameOver();
                if (scene() != nullptr) {
                    scene()->removeItem(item);
                    delete item;
                }
                if (scene() != nullptr) {
                    scene()->removeItem(this);
                }
                delete this;
                return;
            }
        }
    } else {
        setPos(x(), y() - step);
        if (pos().y() < 0) {
            if (scene() != nullptr) {
                scene()->removeItem(this);
            }
            delete this;
            return;
        }

        QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
        for (QGraphicsItem *item : collidingItems) {
            if (dynamic_cast<Enemy *>(item)) {
                QGraphicsPixmapItem *explosion = new QGraphicsPixmapItem(QPixmap(":/images/Explosion_Tanque.png").scaled(50, 50));
                explosion->setPos(item->pos());
                if (scene() != nullptr) {
                    scene()->addItem(explosion);
                }

                QTimer::singleShot(2000, [explosion, this]() {
                    if (explosion->scene() != nullptr) {
                        explosion->scene()->removeItem(explosion);
                    }
                    delete explosion;
                });

                if (scene() != nullptr) {
                    scene()->removeItem(item);
                }
                delete item;
                if (scene() != nullptr) {
                    scene()->removeItem(this);
                }
                delete this;
                return;
            }
        }
    }
}
