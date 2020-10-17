//Name
#include "spaceship.h"
POINT MousePt;
POINT prevMousePt;
bool        isClicked;
bool        isRClicked; 
bool 		isMMoved;
Keys 		*keys;
GL_Window 	*window;

PlayerController playerController;
AudioManager audioManager;
FPSCounter fpsCounter;

BOOL Initialize (GL_Window* _window, Keys* _keys)
{
	window=_window;
	keys=_keys;
	isClicked=false;
	isRClicked=false;
	isMMoved=false;
	srand(time(NULL));
	//Init OpenAL fREAmeWork
		//ALFWInit();
	//init OpenAL
	//if(ALFWInitOpenAL()==AL_FALSE);
	//	return FALSE;
	if(InitGL()==FALSE)
	{
		return false;
	}
	audioManager.Initialize();
	playerController.Initialize();
	return true;	
}

void Deinitialize (void)
{
//	ALFWShutdownOpenAL();
//	ALFWShutdown();
	DeInitGL();
	audioManager.DeInitialize();
}

void Update (DWORD milliseconds)				// Perform Motion Updates
{
	playerController.Update(milliseconds);
	fpsCounter.Update(milliseconds);
}

