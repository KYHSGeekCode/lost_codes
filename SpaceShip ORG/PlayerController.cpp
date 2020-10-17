//name: playercontroller.cpp

#include "spaceship.h"
PlayerController::PlayerController()
{
	;
}
PlayerController::~PlayerController()
{
	;
}
		
//Actual Init
BOOL PlayerController::Initialize()
{
	camera.Initialize();
}
BOOL PlayerController::DeInitialize()
{
	
}

extern POINT 	   MousePt;
extern POINT 	   prevMousePt;

extern int scrnResX,scrnResY;
extern bool        isClicked;                                           //*NEW* Clicking the mouse?
extern bool        isRClicked;                                          //*NEW* Clicking the right mouse button?
extern bool 	   isMMoved;
extern Keys        *keys;
extern GL_Window   *window;
void PlayerController::GetView()
{
	camera.GetView();
}

void PlayerController::Update(DWORD milliseconds)
{
	//#define HANDLE_KEY_ONCE(X,Y) \
		if(keys->keyDown[X]==TRUE)\
		if(GetAsyncKeyState())\
		{\
			keys->keyDown[X]=FALSE;\
			Y;\
		}else {}
	#define HANDLE_KEY_ONCE(X,Y)\
		if(GetKeyState(X)<0)\
		{\
			Y;\
		}
	HANDLE_KEY_ONCE('W',{camera.Walk(STEPS*milliseconds/1000);})
	HANDLE_KEY_ONCE('A',{camera.Strafe(-STEPS*milliseconds/1000);})
	HANDLE_KEY_ONCE('S',{camera.Walk(-STEPS*milliseconds/1000);})
	HANDLE_KEY_ONCE('D',{camera.Strafe(STEPS*milliseconds/1000);})
	HANDLE_KEY_ONCE(VK_SPACE,{camera.Fly(STEPS*milliseconds/1000);})
	HANDLE_KEY_ONCE(VK_SHIFT,{camera.Fly(-STEPS*milliseconds/1000);})
	#undef HANDLE_KEY_ONCE
	//Now Handle Mouse.
	if(isMMoved)
	{
		isMMoved=false;
		bool Mout=false;
		int dx=MousePt.x-prevMousePt.x;
		int dy=MousePt.y-prevMousePt.y;
		int newX=0, newY=0;
		camera.Pitch((float)-dy/1000);
		camera.Yaw((float)-dx/1000);
	//	if(window->init.isFullScreen)
	//	{
	//		if((MousePt.x>scrnResX-20||MousePt.x<20)||(MousePt.y>scrnResY-20||MousePt.y<20))
		//	{
		//		newX=scrnResX/2;
		//		newY=scrnResY/2;
		//		Mout=true;
		//	}
		//} else 
		{
			RECT crt;
			GetClientRect(window->hWnd,&crt);
			ScreenToClient(window->hWnd,&MousePt);
			if((MousePt.x>crt.right-20||MousePt.x<crt.left+20)||(MousePt.y>crt.bottom-20||MousePt.y<crt.top+20))
			{
				newX=(crt.right+crt.left)/2;
				newY=(crt.top+crt.bottom)/2;
				Mout=true;
			}
		}
		if(Mout)
		{
			Mout=false;
			POINT pt;
			pt.x=newX;
			pt.y=newY;
			//ClientToScreen(window->hWnd,&pt);
			SetCursorPos(pt.x,pt.y);
			prevMousePt.x=newX;
			prevMousePt.y=newY;
			MousePt=prevMousePt;
		}
	}
//		isMMoved=false;
//		static int prevx=0,prevy=0;
//		int dx=0,dy=0;
//		int x=MousePt.x;
//		int	y=MousePt.y;
//		bool isMout=false;
//		dx=x-prevx;
//		dy=y-prevy;
//		if(x>window->init.width-20||(x<20)){
//			x=window->init.width/2;
//			isMout=true;	
//		}
//		if(y>window->init.height-20||(y<20))
//		{
//			y=window->init.height/2;	
//			isMout=true;
//		}
//		if(isMout)
//		{
//			SetCursorPos(x,y);
//		}
//		prevy=y;
//		prevx=x;
//		camera.Pitch(-float(dy)/1000);
//		camera.Yaw(-float(dx)/1000);
//	}
}

