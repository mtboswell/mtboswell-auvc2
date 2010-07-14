#ifndef GAME_H
#define GAME_H

#include "ui_game.h"
#include "../dashboard/controlboard/controlboard.h"
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsBlurEffect>

class Game : public QMainWindow, private Ui::AUVGame
{
	Q_OBJECT
	public:
		Game();

	public slots:
		void joystickInput(joystickPos pos);
		// Keyboard Event Handler
		void keyPressEvent(QKeyEvent* event);
		void keyReleaseEvent(QKeyEvent* event);

		void gameOver();


	private slots:
		void handleKeys();

		// routine stuff
		void hitValidationGate();
		void hitPathA();
		void hitRedBuoy();
		void hitGreenBuoy();
		void hitYellowBuoy();
		void hitPathB();
		void hitHedgeA();

		// motions
		void rotateLeft(bool reaction = false);
		void rotateRight(bool reaction = false);
		void moveForward(bool reaction = false);
		void moveBackward(bool reaction = false);
		void moveLeft(bool reaction = false);
		void moveRight(bool reaction = false);
//		void moveUp();
//		void moveDown();
//		void moveLeft();
//		void moveRight();

		// other actions
//		void fire();

		void addToScore(int add);

	private:
		bool checkForCollisions();
		QHash<QChar, bool> keys;
		QHash<QChar, bool> joys;
		QTimer* keyTimer;
		int ft(double feet);
		QGraphicsPixmapItem* auv;
		QGraphicsScene* scene;
		int rotation;
		QBrush* background;
		QImage* backgroundTexture;
		QTransform viewTransform;
		QTransform auvTransform;

		QGraphicsRectItem* wall;
		QGraphicsRectItem* validationGate;
		QGraphicsRectItem* pathA;
		QGraphicsRectItem* pathB;
		QGraphicsRectItem* hedgeA;
		QGraphicsEllipseItem* redBuoy;
		QGraphicsEllipseItem* greenBuoy;
		QGraphicsEllipseItem* yellowBuoy;

		double mapHeight, mapWidth, mapBorder;
		
		joystickPos joyPos;

		int score;

		bool redBuoyHit;
		bool greenBuoyHit;
		bool yellowBuoyHit;


};
#endif
