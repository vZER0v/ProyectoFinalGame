#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include "Tank.h"

class Enemy : public QObject, public Tank {
    Q_OBJECT
public:
    Enemy(QGraphicsItem *parent=0);

public slots:
    void autoMove();
};

#endif // ENEMY_H
