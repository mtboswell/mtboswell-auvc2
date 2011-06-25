#include "joystick.h"
#include <QDebug>
#include <SDL/SDL.h>
#include <iostream>

const int UPDATES_PER_SECOND = 20;
const int MAXIMUM_AXIS_VALUE = 32767;
const int MINIMUM_AXIS_VALUE = -32767;
const int MAX_SPEED_FWD_BWD = 15;
const int MAX_SPEED_LEFT_RIGHT = 15;
const int MAX_DEPTH = 10;
const int MAX_INCREMENT_HEADING = 20;

joystick::joystick()
{
    forwardSpeed = 0;
    depth = 0;
    strafe = 0;
    heading = 0;
    but_2 = false;
    but_3 = false;
    this->init();
    this->start();
}

void joystick::init()
{
    if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK ) < 0)
    {
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    printf("%i joysticks were found.\n\n", SDL_NumJoysticks() );
    printf("The names of the joysticks are:\n");

    int i;
    for( i=0; i < SDL_NumJoysticks(); i++ )
    {
        printf("    %s\n", SDL_JoystickName(i));
    }
    fflush(stdout);
    SDL_Joystick *joystick;

    SDL_JoystickEventState(SDL_ENABLE);
    joystick = SDL_JoystickOpen(0);
}

/**
 *  ******** VERY IMPORTANT METHOD; UPDATES ARE HAPPENING HERE.
 *  ******** Dashboard simply queries the variables that are updated here.
 *  The Joystick inputs are parsed here.
 *  Post-condition:
 *      Variables: depth, strafe, forwardSpeed, heading are updated
 *          with values defined by the constants listed in this file.
 */
void joystick::run()
{
    SDL_Event event;

    while (1)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_KEYDOWN:
                std::cout << "KEY DOWN" << std::endl;
                /* handle keyboard stuff here */
                break;

                case SDL_QUIT:
                /* Set whatever flags are necessary to */
                /* end the main game loop here */
                break;


                case SDL_JOYAXISMOTION:  /* Handle Joystick Motion */
                if ( ( event.jaxis.value < -3200 ) || (event.jaxis.value > 3200 ) )
                {
                    if( event.jaxis.axis == 0) /* Left-right movement code goes here */
                    {
                        double percent = event.jaxis.value * 1.0 / MAXIMUM_AXIS_VALUE;
                        double speed = -percent * MAX_SPEED_LEFT_RIGHT;
                        strafe = speed;
                    }

                    if( event.jaxis.axis == 1) /* Up-Down movement code goes here */
                    {
                        double percent = event.jaxis.value * 1.0 / MAXIMUM_AXIS_VALUE;
                        double speed = -percent * MAX_SPEED_FWD_BWD;
                        forwardSpeed = speed;
                    }

                    if ( event.jaxis.axis == 2) /* Depth (Throttle) */
                    {
                        double percent = event.jaxis.value * 1.0 / MAXIMUM_AXIS_VALUE;
                        double value = percent * MAX_DEPTH;
                        depth = value;
                    }

                    if ( event.jaxis.axis == 3) /* Heading (Yaw) */
                    {
                        double percent = event.jaxis.value * 1.0 / MAXIMUM_AXIS_VALUE;
                        double increment = -percent * MAX_INCREMENT_HEADING;
                        heading = increment;
                    }
                }
                break;

                case SDL_JOYBUTTONDOWN:  /* Handle Joystick Button Presses */
                if ( event.jbutton.button == 0 )
                {
                    // main trigger
                }
                if ( event.jbutton.button == 2 )
                {
                    but_2 = true;
                }
                if ( event.jbutton.button == 3 )
                {
                    but_3 = true;
                }
                break;

                case SDL_JOYBALLMOTION:  /* Handle Joyball Motion */
                if( event.jball.ball == 0 )
                {
                  /* ball handling */
                }
                break;

            }
        }
        this->msleep(1000/UPDATES_PER_SECOND);
//        fflush(stdout);
    }
}
