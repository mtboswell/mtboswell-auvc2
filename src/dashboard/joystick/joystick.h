#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QThread>

/**
 *  @author Carlo del Mundo
 *  Joystick interface for immediate feedback for AUVT Control Systems; uses SDL library.
 *      INSTALLING SDL:
 *          1.) Change directory to ../$AUVT_SRC/SDL/
 *          2.) # ./configure
 *          3.) # make
 *          4.) # make install
 */
class joystick  : public QThread
{
    Q_OBJECT
public:
    double forwardSpeed;
    double depth;
    double strafe;
    double heading;
    bool but_2;
    bool but_3;

    joystick();

private:
    void init();
    void run();
};

#endif // JOYSTICK_H
