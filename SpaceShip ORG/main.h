//Main.h

#ifndef _MAIN_H
#define _MAIN_H
#include  "spaceship.h"

extern POINT MousePt;
extern POINT prevMousePt;
extern bool        isClicked;
extern bool        isRClicked; 
extern bool 		isMMoved;
extern Keys 		*keys;
extern GL_Window 	*window;
extern PlayerController playerController;
extern AudioManager audioManager;
extern FPSCounter fpsCounter;
extern PhysicsManager physicsManager;
#endif
