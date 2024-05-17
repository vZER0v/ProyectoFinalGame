#include "Wall.h"
#include <QGraphicsItem>

Wall::Wall(QGraphicsItem *parent): QGraphicsRectItem(parent) {
    // Inicializa la pared aquí
    setRect(0,0,50,50);
}
