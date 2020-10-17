#ifndef _TOOLS_H
#define _TOOLS_H


class ITool
{
		TCHAR name[MAX_NAME];
		uint flags;
		bool bHeld;
		Player *player;
		enum TexID texture;
		virtual ITool(LPCTSTR n)
		{
			tstrncpy(name,n,MAX_NAME);
			flags=0;
			player=NULL;
		}
		virtual bool OnButtonDown(enum MBUTTON btn) {}
		virtual bool OnButtonUpdate(enum MBUTTON btn,DWORD mills) {};
		virtual bool OnButtonUp(enum MBUTON btn) {};
		virtual bool OnHeldUpdate(DWORD mills) {};
		virtual bool OnUpdate(DWORD mills) {};
		virtual bool OnHeld() {};
		virtual bool OnUnHeld() {};
		virtual void OnDraw()
		{
			glBegin(GL_QUADS);
			glBindTexture(Textures[texture]);
			glTexCoord2f(0,0);
			glVertex2f(0,-1);
			glTexCoord2f(1,0);
			glVertex2f(1,-1);
			glTexCoord2f(1,1);
			glVertex2f(1,0);
			glTexCoord2f(0,1);

			glVertex2f(0,0);
			glEnd();
		}
};

class Hand:public ITool
{
		Hand(LPCTSTR n):ITool(n)
		{
			texID=TX_HAND;
		}
		bool OnButtonDown(enum MBUTTON btn)
		{
			vec point=dCollide(player->camera->pos,player->caera->look,terrain);
			if(!point)return false;
			AddTerrainHeght(pos,1.0f);
			return true;
		}
};


#endif
