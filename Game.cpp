#include "Game.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>
#include <QGraphicsTextItem>
#include <QFont>
#include <QPushButton>
#include <QApplication>
#include <QGraphicsProxyWidget>

Game::Game(QWidget *parent): QGraphicsView(parent) {
    // Configurar la escena
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);
    setScene(scene);

    // Agregar fondo
    QPixmap background(":/images/Fondo_Tanque.png");
    scene->setBackgroundBrush(background.scaled(800, 600));

    // Crear y añadir el tanque del jugador
    playerTank = new Tank();
    playerTank->setPos(scene->width()/2, scene->height() - playerTank->boundingRect().height());
    scene->addItem(playerTank);

    // Hacer que el tanque del jugador sea el objeto activo para recibir eventos de teclado
    playerTank->setFlag(QGraphicsItem::ItemIsFocusable);
    playerTank->setFocus();

    // Crear un temporizador para generar enemigos
    QTimer *enemyTimer = new QTimer(this);
    connect(enemyTimer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    enemyTimer->start(2000); // Generar un enemigo cada 2 segundos
}

void Game::spawnEnemy() {
    Enemy *enemy = new Enemy();
    int randomX = rand() % int(scene->width() - enemy->boundingRect().width());
    enemy->setPos(randomX, 0);
    scene->addItem(enemy);
    enemies.append(enemy);
}

void Game::displayGameOver() {
    QGraphicsPixmapItem* gameOverText = new QGraphicsPixmapItem(QPixmap(":/images/GameOver_Tanque.png"));
    int xPos = scene->width() / 2 - gameOverText->boundingRect().width() / 2;
    int yPos = scene->height() / 2 - gameOverText->boundingRect().height() / 2;
    gameOverText->setPos(xPos, yPos);
    scene->addItem(gameOverText);

    QPushButton *restartButton = new QPushButton("Restart");
    restartButton->setGeometry(xPos, yPos + 100, 100, 50);
    QGraphicsProxyWidget *proxy = scene->addWidget(restartButton);
    connect(restartButton, &QPushButton::clicked, this, &Game::restartGame);
}

void Game::restartGame() {
    // Detener y eliminar el temporizador de enemigos si existe
    if (enemyTimer) {
        enemyTimer->stop();
        enemyTimer->deleteLater();
        enemyTimer = nullptr;
    }

    // Eliminar todos los elementos de la escena, incluyendo los widgets
    QList<QGraphicsItem *> items = scene->items();
    foreach(QGraphicsItem *item, items) {
        if (dynamic_cast<QGraphicsPixmapItem *>(item) ||
            dynamic_cast<QGraphicsRectItem *>(item) ||
            dynamic_cast<QGraphicsTextItem *>(item) ||
            dynamic_cast<QGraphicsProxyWidget *>(item)) {
            scene->removeItem(item);
            delete item;
        }
    }

    // Inicializar el tanque del jugador
    playerTank = new Tank();
    playerTank->setPos(scene->width()/2, scene->height() - playerTank->boundingRect().height());
    scene->addItem(playerTank);
    playerTank->setFlag(QGraphicsItem::ItemIsFocusable);
    playerTank->setFocus();

    // Limpiar listas de enemigos y balas
    enemies.clear();
    bullets.clear();

    // Crear un nuevo temporizador para los enemigos
    enemyTimer = new QTimer(this);
    connect(enemyTimer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    enemyTimer->start(2000);
}
