#include "game.h" 
#include <QDebug>

Game::Game(){ 
	setupUi(this); 
	//this->setAttribute(Qt::WA_KeyCompression);
	setFocusPolicy(Qt::StrongFocus);
	mapHeight = 100;
	mapWidth = 50;
	mapBorder = 10;
	scene = new QGraphicsScene(0,0,ft(mapWidth),ft(mapHeight),this); 
	backgroundTexture = new QImage("images/water.png");
	background = new QBrush(*backgroundTexture);
	//background = new QBrush(Qt::cyan);
	scene->setBackgroundBrush(*background);

	// Add AUV
	QPixmap srcauvimg("images/auv.png");
	QPixmap auvimg(srcauvimg.scaledToHeight(ft(2),Qt::SmoothTransformation));
	int auvWidth = auvimg.width();
	int auvLength = auvimg.height();
	//auv = new QGraphicsEllipseItem(-1*ft(auvWidth/2.0),-1*ft(auvLength/2.0),ft(auvWidth),ft(auvLength));
	auv = new QGraphicsPixmapItem(auvimg);
	//auv->setBrush(QBrush(Qt::gray));
	scene->addItem(auv);
	auv->setZValue(2);
	auv->setOffset(-1*(auvWidth/2), -1*(auvLength/2));
	//auv->setTransformOriginPoint(auvWidth/2,auvLength/2);
	//auvTransform.translate(ft(25),ft(42));
	//auv->setTransform(auvTransform);
	auv->setPos(ft(25),ft(85));
	// test position at end of course
	//auv->setPos(ft(25),ft(45));


	graphicsView->setScene(scene);
	graphicsView->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
	rotation = 0;

	// setup course
	// wall
	wall = scene->addRect(0,0,ft(mapWidth - 2*mapBorder),ft(mapHeight - 2*mapBorder));
	QTransform wallTransform;
	wallTransform.translate(ft(mapBorder), ft(mapBorder));
	wall->setTransform(wallTransform);
	
	// validation gate
	double gateWidth = 10;
	double gateHeight = 0.333;
	validationGate = scene->addRect(-1*ft(gateWidth/2.0),-1*ft(gateHeight/2.0),ft(gateWidth),ft(gateHeight),QPen(),QBrush(Qt::white));
	validationGate->setZValue(3);
	validationGate->setPos(ft(25), ft(70));

	// paths
	double pathWidth = 0.333;
	double pathLength = 4;
	pathA = scene->addRect(-1*ft(pathWidth/2.0),-1*ft(pathLength/2.0),ft(pathWidth),ft(pathLength),QPen(),QBrush(Qt::red));
	pathA->setPos(ft(27), ft(66));
	pathA->setRotation(15);
	pathA->setZValue(1);

	// buoys
	double buoySize = 0.75;
	redBuoy = scene->addEllipse(-1*ft(buoySize/2.0),-1*ft(buoySize/2.0),ft(buoySize),ft(buoySize),QPen(),QBrush(Qt::red));
	redBuoy->setZValue(2);
	redBuoy->setPos(ft(29), ft(55));
	redBuoyHit = false;

	greenBuoy = scene->addEllipse(-1*ft(buoySize/2.0),-1*ft(buoySize/2.0),ft(buoySize),ft(buoySize),QPen(),QBrush(Qt::green));
	greenBuoy->setZValue(2);
	greenBuoy->setPos(ft(27), ft(53));
	greenBuoyHit = false;

	yellowBuoy = scene->addEllipse(-1*ft(buoySize/2.0),-1*ft(buoySize/2.0),ft(buoySize),ft(buoySize),QPen(),QBrush(Qt::yellow));
	yellowBuoy->setZValue(2);
	yellowBuoy->setPos(ft(31), ft(57));
	yellowBuoyHit = false;

	
	pathB = scene->addRect(-1*ft(pathWidth/2.0),-1*ft(pathLength/2.0),ft(pathWidth),ft(pathLength),QPen(),QBrush(Qt::red));
	pathB->setPos(ft(29), ft(50));
	pathB->setRotation(-15);
	pathB->setZValue(1);

	//hedge
	double hedgeWidth = 6;
	double hedgeHeight = 0.333/2.0;
	hedgeA = scene->addRect(-1*ft(hedgeWidth/2.0),-1*ft(hedgeHeight/2.0),ft(hedgeWidth),ft(hedgeHeight),QPen(),QBrush(Qt::green));
	hedgeA->setZValue(1);
	hedgeA->setPos(ft(25), ft(40));
	hedgeA->setRotation(-20);



	graphicsView->centerOn(auv);
	moveForward();

	score = 0;

	keyTimer = new QTimer(this);
	connect(keyTimer, SIGNAL(timeout()), this, SLOT(handleKeys()));
	keyTimer->start(10);
}

void Game::rotateLeft(bool reaction){
	rotation = (rotation - 5)%360;
	auv->setRotation(rotation);
	//auvTransform.rotate(-5);
	//viewTransform.rotate(-5);
	//graphicsView->setTransform(viewTransform);
	//auv->setTransform(auvTransform);
	//graphicsView->setTransform(graphicsView->viewportTransform().rotate(5));
	graphicsView->rotate(5);
	if(checkForCollisions() && !reaction){
		rotateRight(true);
	}
	else if(checkForCollisions() && reaction){
		rotateLeft(true);
	}
}

void Game::rotateRight(bool reaction){
	rotation = (rotation + 5)%360;
	auv->setRotation(rotation);
	//auvTransform.rotate(5);
	//auv->setTransform(auvTransform);
	//graphicsView->rotate(5);
	//viewTransform.rotate(5);
	//graphicsView->setTransform(viewTransform);
	//graphicsView->setTransform(graphicsView->viewportTransform().rotate(-5));
	graphicsView->rotate(-5);
	if(checkForCollisions() && !reaction){
		rotateLeft(true);
	}
	else if(checkForCollisions() && reaction){
		rotateRight(true);
	}
}

void Game::moveForward(bool reaction){
	// find center point of view
	QSize viewSize = graphicsView->size();
	int centerX = viewSize.width()/2;
	int centerY = viewSize.height()/2;
	//qDebug() << "Center of screen is:" << centerX << centerY;
	// find point 10px ahead
	centerY -= 5;
	// map point to scene
	QPointF scenePt = graphicsView->mapToScene(centerX, centerY);
	// move AUV to scene point
	//qDebug() << "Moving AUV to: " << scenePt;
	auv->setPos(scenePt);
	if(checkForCollisions() && !reaction){
		//qDebug() << "Hit something, moving back" << endl;
		moveBackward(true);
	}
	else if(checkForCollisions() && reaction){
		//qDebug() << "Hit something again, moving forward" << endl;
		moveForward(true);
	}
}
void Game::moveBackward(bool reaction){
	// find center point of view
	QSize viewSize = graphicsView->size();
	int centerX = viewSize.width()/2;
	int centerY = viewSize.height()/2;
	//qDebug() << "Center of screen is:" << centerX << centerY;
	// find point 10px behind
	centerY += 5;
	// map point to scene
	QPointF scenePt = graphicsView->mapToScene(centerX, centerY);
	// move AUV to scene point
	//qDebug() << "Moving AUV to: " << scenePt;
	auv->setPos(scenePt);
	if(checkForCollisions() && !reaction){
		//qDebug() << "Hit something, moving forward" << endl;
		moveForward(true);
	}
	else if(checkForCollisions() && reaction){
		//qDebug() << "Hit something again, moving backward" << endl;
		moveBackward(true);
	}
}

void Game::moveLeft(bool reaction){
	// find center point of view
	QSize viewSize = graphicsView->size();
	int centerX = viewSize.width()/2;
	int centerY = viewSize.height()/2;
	//qDebug() << "Center of screen is:" << centerX << centerY;
	// find point 10px behind
	centerX -= 5;
	// map point to scene
	QPointF scenePt = graphicsView->mapToScene(centerX, centerY);
	// move AUV to scene point
	//qDebug() << "Moving AUV to: " << scenePt;
	auv->setPos(scenePt);
	if(checkForCollisions() && !reaction){
		//qDebug() << "Hit something, moving forward" << endl;
		moveRight(true);
	}
	else if(checkForCollisions() && reaction){
		//qDebug() << "Hit something again, moving backward" << endl;
		moveLeft(true);
	}
}

void Game::moveRight(bool reaction){
	// find center point of view
	QSize viewSize = graphicsView->size();
	int centerX = viewSize.width()/2;
	int centerY = viewSize.height()/2;
	//qDebug() << "Center of screen is:" << centerX << centerY;
	// find point 10px behind
	centerX += 5;
	// map point to scene
	QPointF scenePt = graphicsView->mapToScene(centerX, centerY);
	// move AUV to scene point
	//qDebug() << "Moving AUV to: " << scenePt;
	auv->setPos(scenePt);
	if(checkForCollisions() && !reaction){
		//qDebug() << "Hit something, moving forward" << endl;
		moveLeft(true);
	}
	else if(checkForCollisions() && reaction){
		//qDebug() << "Hit something again, moving backward" << endl;
		moveRight(true);
	}
}

bool Game::checkForCollisions(){
	bool hitobject = false;
	qreal auvX = auv->scenePos().x();
	qreal auvY = auv->scenePos().y();


	// check for wall collisions
	if(auvX < ft(mapBorder)){ 
		auv->setPos(ft(mapBorder), auvY);
	}else if(auvX > ft(mapWidth - mapBorder)){
		auv->setPos(ft(mapWidth - mapBorder),auvY);
	}
	if(auvY < ft(mapBorder)){ 
		auv->setPos(auvX,ft(mapBorder));
	}else if(auvY > ft(mapHeight - mapBorder)){
		auv->setPos(auvX,ft(mapHeight - mapBorder));
	}

	// check for object collisions
	foreach(QGraphicsItem* hit, auv->collidingItems()){
		if(hit == validationGate) hitValidationGate();
		else if(hit == pathA) hitPathA();
		else if(hit == pathB) hitPathB();
		else if(hit == hedgeA) hitHedgeA();
		else if(hit == redBuoy) {
			hitRedBuoy();
			hitobject = true;
		}
		else if(hit == greenBuoy) {
			hitGreenBuoy();
			hitobject = true;
		}
		else if(hit == yellowBuoy) {
			hitYellowBuoy();
			hitobject = true;
		}
	}
	graphicsView->centerOn(auv);
	return hitobject;
}

void Game::hitValidationGate(){
	static bool hitGate = false;
	if(hitGate) return;
	else{
		hitGate = true;
		validationGate->setPen(QPen(QBrush(Qt::blue),3));
		if(rotation == 0){
			addToScore(150);
			validationGate->setPen(QPen(QBrush(Qt::green),3));
		}
		else
			addToScore(100);
	}
}
void Game::hitPathA(){
	static bool hitPathA = false;
	if(hitPathA) return;
	else{
		if(rotation == pathA->rotation()){
			hitPathA = true;
			addToScore(50);
			pathA->setPen(QPen(QBrush(Qt::green),3));
		}
	}
}
void Game::hitPathB(){
	static bool hitPathB = false;
	if(hitPathB) return;
	else{
		if(rotation == pathB->rotation()){
			hitPathB = true;
			addToScore(50);
			pathB->setPen(QPen(QBrush(Qt::green),3));
		}
	}
}
void Game::hitRedBuoy(){
	if(redBuoyHit) return;
	else{
		redBuoyHit = true;
		redBuoy->setPen(QPen(QBrush(Qt::blue),3));
		if(greenBuoyHit && yellowBuoyHit){
			yellowBuoyHit = false;
		}else
			addToScore(500);
	}
}
void Game::hitGreenBuoy(){
	if(greenBuoyHit) return;
	else{
		greenBuoyHit = true;
		greenBuoy->setPen(QPen(QBrush(Qt::blue),3));
		if(redBuoyHit && yellowBuoyHit){
			redBuoyHit = false;	
		}else{
			addToScore(500);
		}
	}
}
void Game::hitYellowBuoy(){
	if(yellowBuoyHit) return;
	else{
		yellowBuoyHit = true;
		yellowBuoy->setPen(QPen(QBrush(Qt::blue),3));
		if(greenBuoyHit && !redBuoyHit) 
			addToScore(1500);
		else if(redBuoyHit && greenBuoyHit)
			greenBuoyHit = false;
		else
			addToScore(500);
	}
}
void Game::hitHedgeA(){
	static bool hitHedgeA = false;
	if(hitHedgeA) return;
	else{
		hitHedgeA = true;
		hedgeA->setPen(QPen(QBrush(Qt::blue),3));
		if(rotation == hedgeA->rotation()){
			addToScore(800);
			hedgeA->setPen(QPen(QBrush(Qt::green),3));
		}
		else
			addToScore(600);
		QTimer::singleShot(1000, this, SLOT(gameOver()));
	}
}


void Game::handleKeys(){
	setFocus(Qt::OtherFocusReason);
	if(keys['a'])
		rotateLeft();
	if(keys['d'])
		rotateRight();
	if(keys['w'])
		moveForward();
	if(keys['s'])
		moveBackward();
	if(keys['z'])
		moveLeft();
	if(keys['c'])
		moveRight();
	if(joyPos == UP) moveForward();
	else if(joyPos == DOWN) moveBackward();
	else if(joyPos == LEFT) rotateLeft();
	else if(joyPos == RIGHT) rotateRight();
	else if(joyPos == DOWNRIGHT) moveRight();
	else if(joyPos == DOWNLEFT) moveLeft();
	else if(joyPos == UPLEFT){
		moveForward();
		rotateLeft();
	}
	else if(joyPos == UPRIGHT){
		moveForward();
		rotateRight();
	}
}

void Game::keyPressEvent(QKeyEvent* event){
	foreach(QChar key, event->text()){
		keys[key] = true;
		//qDebug() << "Key pressed:" << key << endl;
	}
}
void Game::keyReleaseEvent(QKeyEvent* event){
	foreach(QChar key, event->text()){
		keys[key] = false;
		//qDebug() << "Key released:" << key << endl;
	}
}

int Game::ft(double feet){
	return (int) (feet*40.0);
}

void Game::joystickInput(joystickPos pos){
	//qDebug() << "Joystick moved:" << pos << endl;
	joyPos = pos;
}

void Game::addToScore(int add){
	score += add;
	scoreLabel->setText(QString::number(score));
}

void Game::gameOver(){
	keyTimer->stop();

	QGraphicsTextItem* gameOverText = scene->addText("Game Over!");
	gameOverText->setFont(QFont("Sans", 50, QFont::Bold));
	gameOverText->setDefaultTextColor(QColor("white"));
	gameOverText->setZValue(5);

	// find center point of view
	QSize viewSize = graphicsView->size();
	int centerX = viewSize.width()/2;
	int centerY = viewSize.height()/2;
	//qDebug() << "Center of screen is:" << centerX << centerY;
	centerX -= 225;
	centerY += centerY/2;
	// map point to scene
	QPointF scenePt = graphicsView->mapToScene(centerX, centerY);

	gameOverText->setRotation(rotation);
	gameOverText->setPos(scenePt);
}
