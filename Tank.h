#ifndef TANK_H
#define TANK_H

#include <QGraphicsItem>
#include <QKeyEvent>

class Tank : public QGraphicsRectItem {
public:
    Tank(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
    void shoot();
};

#endif // TANK_H
