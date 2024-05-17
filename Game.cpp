#include "Game.h"
#include "Tank.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Wall.h"
#include <QGraphicsScene>
#include <QGraphicsItem>

Game::Game(QWidget *parent): QGraphicsView(parent) {
    // Configura la escena aquí
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    // Crea y añade el tanque del jugador
    playerTank = new Tank();
    playerTank->setPos(scene->width()/2, scene->height() - playerTank->rect().height());
    scene->addItem(playerTank);

    // Haz que el tanque del jugador sea el objeto activo para recibir eventos de teclado
    playerTank->setFlag(QGraphicsItem::ItemIsFocusable);
    playerTank->setFocus();

    // Añadir enemigos o paredes como sea necesario
}
