#ifndef TANK_H
#define TANK_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Tank : public QGraphicsPixmapItem {
public:
    Tank(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
    void shoot();
};

#endif // TANK_H
