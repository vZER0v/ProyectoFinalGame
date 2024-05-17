#include "Game.h"
#include "Tank.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Wall.h"
#include <QGraphicsScene>
#include <QGraphicsItem>

Game::Game(QWidget *parent): QGraphicsView(parent) {
    // Aca se configura la escena
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    // Se crea y añade el tanque del jugador
    playerTank = new Tank();
    playerTank->setPos(scene->width()/2, scene->height() - playerTank->rect().height());
    scene->addItem(playerTank);

    // Aca el tanque del jugador sea el objeto activo para recibir eventos de teclado
    playerTank->setFlag(QGraphicsItem::ItemIsFocusable);
    playerTank->setFocus();

    // Aca se añade enemigos o paredes como sea necesario
}
