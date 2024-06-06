#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "Tank.h"
#include "Enemy.h"
#include "Wall.h"
#include "Bullet.h"

class Game : public QGraphicsView {
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    void displayGameOver();
    void restartGame();

private:
    QGraphicsScene *scene;
    Tank *playerTank;
    QList<Enemy*> enemies;
    QList<Bullet*> bullets;
    QTimer *enemyTimer;

public slots:
    void spawnEnemy(); // Declarar la función spawnEnemy como un slot
};

#endif // GAME_H
