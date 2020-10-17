//name: playercontroller.cpp

#ifndef _SPACESHIP_H
#define _SPACESHIP_H
class PlayerController
{
	public:
		//should BE VOID
		PlayerController();
		~PlayerController();
		
		//Actual Init
		BOOL Initialize();
		BOOL DeInitialize();
		void Update(DWORD milliseconds);
		void GetView();
	private:
		Camera camera;		
};
#endif
