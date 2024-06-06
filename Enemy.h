#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "Bullet.h"

class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy(QGraphicsItem *parent=0);

public slots:
    void autoMove();
    void shoot();
};

#endif // ENEMY_H
