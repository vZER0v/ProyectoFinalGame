#ifndef WALL_H
#define WALL_H

#include <QGraphicsItem>

class Wall : public QGraphicsRectItem {
public:
    Wall(QGraphicsItem *parent=0);
    // Puedes añadir métodos específicos de pared aquí si son necesarios
};

#endif // WALL_H
