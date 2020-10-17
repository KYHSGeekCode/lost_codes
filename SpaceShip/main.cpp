//Name
#include "spaceship.h"
#include "playercontroller.h"
#include "audiomanager.h"
#include "fps2.h"
#include "GLutil.h"
#include "terrain/terrain.h"
#include "PhysicsManager.h"


POINT MousePt;
POINT prevMousePt;
bool        isClicked;
bool        isRClicked; 
bool 		isMMoved;
Keys 		*keys;
GL_Window 	*window;
bool 		mouseRelease;

PlayerController playerController;
AudioManager audioManager;
FPSCounter fpsCounter;
Terrain *theTerrain;
PhysicsManager physicsManager;

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
		MessageBox(0,"Failed to init opengl","",0);
		return false;
	}
	audioManager.Initialize();
	physicsManager.Initialize();
	playerController.Initialize();
	
	theTerrain=new Terrain( "Terrain/coastMountain64.raw", 64, 64, 10, 0.5f);
	return true;	
}

void Deinitialize (void)
{
//	ALFWShutdownOpenAL();
//	ALFWShutdown();
	DeInitGL();
	physicsManager.Finalize();
	audioManager.DeInitialize();
	delete theTerrain;
}

void Update (DWORD milliseconds)				// Perform Motion Updates
{
	#define _DEBUG
	#ifdef _DEBUG
		if(keys->keyDown[VK_ESCAPE]==true)
		{
			keys->keyDown[VK_ESCAPE]=false;
			mouseRelease=!mouseRelease;
			ClipCursor(NULL);
		}
	#endif
	playerController.Update(milliseconds);
	fpsCounter.Update(milliseconds);
}

