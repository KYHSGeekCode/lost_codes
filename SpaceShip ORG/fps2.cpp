//fpscounter.cpp

#include "spaceship.h"

void FPSCounter::Update(DWORD mills)
{
	elapsed+=mills;
	fpscount++;
	if(elapsed>=1000)
	{
		fps=(float)fpscount/elapsed*1000;
		fpscount=0;
		elapsed=0;
	}
}
void FPSCounter::Draw()
{
	glPushMatrix();
	glScalef(0.2,0.2,1);
	glTranslatef(0.7,-0.7,0);
	glColor4ub(255,255,255,255);
	glPrint("%3.2f",fps);
	glPopMatrix();
}
FPSCounter::FPSCounter()
{
	fpscount=0;
	fps=30.0f;
	elapsed=0;
}
