//#define UNICODE
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <conio.h>
#include <windows.h>
#include <Shlwapi.h>
//#include <vector>
#include <forward_list>
#include <string>
#include <gdiplus/gdiplus.h>

#define DEBUG
#include "log.h"
LOGVAR;

using namespace Gdiplus;
using namespace std;

//#define IMG_STR "png tiff bmp tga"
//#define ANI_STR "mp4 skm avi 3gp asf dv flv gif mkv mov m4v mpg ogv rm swf webm wmv divx xvid amv"
//#define INPUT_STR ""
#define OUTPUT_STR "txt jpg k3g"

BOOL GetEncCLSID(WCHAR *mime, CLSID *pClsid);
void SaveJpg(LPCTSTR Path,ULONG Quality);
void RenameRecursive(TCHAR *path);
void HandleError();
void SetUp();
void Rename();
void Finalize();

forward_list<string> vfiles;
forward_list<string>::iterator iter;

char cmd[256];
int del;
char MyDrive;
//char MyPath[MAX_PATH];

int main(int argc, char *argv[])
{
	if(argc>1){
		strncpy(cmd,argv[1],255);
		puts(cmd);
	}
	TCHAR dirt[MAX_PATH];
	TCHAR dir[MAX_PATH];
	LOGINIT;
	GetCurrentDirectory(MAX_PATH,dir);
	//MessageBox(0,MyPath,"OK",MB_OK);
	MyDrive=dir[0];
	ULONG_PTR gpToken;

    GdiplusStartupInput gpsi;

    if (GdiplusStartup(&gpToken,&gpsi,NULL) != Ok) {
          MessageBox(NULL,"GDI+ ���̺귯���� �ʱ�ȭ�� �� �����ϴ�.","�˸�",MB_OK);
          return 0;
     }	

    printf("file renamer\n\n");
    puts("enter folder name");
/*
    OPENFILENAME OFN;
    memset(&OFN, 0, sizeof(OPENFILENAME));
	OFN.lStructSize = sizeof(OPENFILENAME);
	OFN.hwndOwner=NULL;
	OFN.lpstrFilter=TEXT("��� ����(*.*)\0*.*\0");
	OFN.lpstrFile=lpstrFile;
	OFN.nMaxFile=MAX_PATH;
	if (GetOpenFileName(&OFN)!=0) {
		wsprintf(str,TEXT("%s ������ �����߽��ϴ�."),OFN.lpstrFile);
		//MessageBox(hWnd,str,TEXT("���� ���� ����"),MB_OK);
	}
*/
    //fgets(dirt,MAX_PATH,stdin);
    gets(dirt);
    puts(dirt);
    memset(dir,0,MAX_PATH);
    int len=lstrlen(dirt);
    int j=0;
    for(int i=0;i<len;++i)
    {
    	if(dirt[i]!='\"')
    	{
    		dir[j]=dirt[i];
    		++j;
    		VAROUT("i",i);
    		VAROUT("j",j);
    		LOGOUT(dir);
    		LOGOUT(dirt);
		}
	}
    //if(MessageBox(0,dir,dirt,MB_YESNO)!=MB_OK)
    //	exit(-1);
    SetUp();
    RenameRecursive(dir);
    Rename();
    Finalize();
    LOGEND;
    system("PAUSE");	
    return 0;
}

string getExt(string pathName)
{
	return pathName.substr(pathName.find_last_of(".")+1);
}

TCHAR * ToText;
TCHAR * ToK3g;
TCHAR * ToJpg;
void RenameRecursive(TCHAR *path)
{
	HANDLE hSrch;
	WIN32_FIND_DATA wfd;
	TCHAR fname[MAX_PATH];
	BOOL bResult=TRUE;
	TCHAR drive[_MAX_DRIVE];
	TCHAR dir[MAX_PATH];
	TCHAR newpath[MAX_PATH];
	LOGOUT(path);
	//TCHAR ext[_MAX_EXT];
	//puts(path);
	GetLastError();
	hSrch=FindFirstFile(path,&wfd);
	if (hSrch==INVALID_HANDLE_VALUE)
	{
		puts("error to acquire findfilehandle");
		HandleError();
	 	return;
	}
	GetLastError();
	
		_splitpath(path,drive,dir,NULL,NULL);
		//lstrcat(ext,".txt");
		while (bResult) {
			if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
				if (lstrcmp(wfd.cFileName,".") && lstrcmp(wfd.cFileName,"..")) {
					//PathCombine(newpath,path,"\\*.*");
					wsprintf(newpath,"%s%s%s\\*.*",drive,dir,wfd.cFileName);
					RenameRecursive(newpath);
				}
			} else {
				TCHAR buf[MAX_PATH+50];
				wsprintf(buf,"%s%s%s",drive,dir,wfd.cFileName);
				string sext=getExt(wfd.cFileName);
				char ext[20];
				memset(ext,0,20);
				ext[0]='.';
				strncpy(ext+1,sext.c_str(),19);
				strlwr(ext);
				if(strstr(OUTPUT_STR,ext)==NULL)
				{
					/*
					if(strstr(ToJpg,ext))
					{
						SaveJpg(buf,100);
					} else if(ext=="3gp")
					{
						wsprintf(fname,"%s.k3g",buf);
						if(MoveFile(buf,fname)==0)
						{
							puts("fail to rename 3gp to k3g");
							HandleError();
						}
					}else if(strstr(ToK3g,ext))
					{
						wsprintf(buf,"%c:\\TOOL\\prism.exe -convert \"%s\" -format .3gp MPEG4 128 256 320 240 AMR 10 -hide",MyDrive,buf);
					}else{
						wsprintf(fname,"%s.txt",buf);
						//puts(fname);
						if(MoveFile(buf,fname)==0)
						{
							puts("fail to rename to txt");
						    HandleError();
						}
	
					}
					*/
					iter = vfiles.insert_after( iter, string(buf) );
				}
			}
			bResult=FindNextFile(hSrch,&wfd);
		}
	//}
	//catch(...)
	//{
	//	HandleError();
	//} 
	
	FindClose(hSrch);
}

void Rename()
{
	char fname[MAX_PATH];
    for( iter = vfiles.begin(); iter != vfiles.end(); ++iter )
    {
        const char * name= iter->c_str();
   		string sext=getExt(*iter);
		char ext[20];
		memset(ext,0,20);
		ext[0]='.';
		strncpy(ext+1,sext.c_str(),19);
		strlwr(ext);
		if(strstr(ToJpg,ext))
		{
			SaveJpg(name,100);
		} else if(ext=="3gp")
		{
			wsprintf(fname,"%s.k3g",name);
			if(MoveFile(name,fname)==0)
			{
				puts("fail to rename 3gp to k3g");
				HandleError();
			}
		}else if(strstr(ToK3g,ext))
		{
			wsprintf(fname,"%c:\\TOOL\\prism.exe -convert \"%s\" -format .3gp MPEG4 128 256 320 240 AMR 10 -hide",MyDrive,name);
		}else{
			wsprintf(fname,"%s.txt",name);
			if(MoveFile(name,fname)==0)
			{
				puts("fail to rename to txt");
				HandleError();
			}
	
		}
	}
}

#include <fstream>
using namespace std;
void SetUp()
{
	string TxtStr,K3gStr,JpgStr;
	ifstream read("ini.ini");
    getline(read,TxtStr);
    getline(read,K3gStr);
    getline(read,JpgStr);
    ToText=strdup(TxtStr.c_str());
    ToK3g=strdup(K3gStr.c_str());
    ToJpg=strdup(JpgStr.c_str());
    iter=vfiles.before_begin();
}

void Finalize()
{
	free(ToText);
	free(ToK3g);
	free(ToJpg);
}
void HandleError()
{
	TCHAR errMes[1024];
	TCHAR str[1024];
	int err;
	err=GetLastError();
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,NULL,err,	0,errMes,1024,NULL);
	wsprintf(str,"�����ڵ�=%d, �޽���=%s",err,errMes);
	MessageBox(0,str,"����",MB_OK);
	GetLastError();
}


TCHAR BmpPath[MAX_PATH];
BOOL GetEncCLSID(WCHAR *mime, CLSID *pClsid)

{

     UINT num,size,i;

     ImageCodecInfo *arCod;

     BOOL bFound=FALSE;

 

     GetImageEncodersSize(&num,&size);

     arCod=(ImageCodecInfo *)malloc(size);

     GetImageEncoders(num,size,arCod);

 

     for (i=0;i<num;i++) {

          if(wcscmp(arCod[i].MimeType,mime)==0) {

               *pClsid=arCod[i].Clsid;

               bFound=TRUE;

               break;

          }    

     }

     free(arCod);

     return bFound;

}


void SaveJpg(LPCTSTR Path,ULONG Quality)

{

     WCHAR ImagePath[MAX_PATH];

     TCHAR NewName[MAX_PATH];

     Image *pI;

     CLSID Clsid;

     TCHAR drive[_MAX_DRIVE];

     TCHAR dir[_MAX_DIR];

     TCHAR fname[_MAX_FNAME];

     TCHAR ext[_MAX_EXT];

     EncoderParameters Para;

     MultiByteToWideChar(CP_ACP, 0, Path, -1, ImagePath, MAX_PATH);

     pI=Image::FromFile(ImagePath);
     
     GetEncCLSID(L"image/jpeg",&Clsid);
     
     _splitpath(Path,drive,dir,fname,ext);

     wsprintf(NewName,"%s%s%s.jpg",drive,dir,fname);

     MultiByteToWideChar(CP_ACP, 0, NewName, -1, ImagePath, MAX_PATH);

     Para.Count=1;

     Para.Parameter[0].Guid=EncoderQuality;

     Para.Parameter[0].Type=EncoderParameterValueTypeLong;

     Para.Parameter[0].NumberOfValues=1;

     Para.Parameter[0].Value=&Quality;

     pI->Save(ImagePath,&Clsid,&Para);

     delete pI;

}


/*
int main()

{

           forward_list< int > flist;

 

 

           cout << "flist�� �߰��� ��ҵ� ���" << endl;

           // �߰��ϱ�

           auto iter = flist.before_begin();

           for( int i = 0; i < 5; ++i )

           {

                     iter = flist.insert_after( iter, i );

           }

                    

           // ��ȸ

           for( iter = flist.begin(); iter != flist.end(); ++iter )

           {

                     cout << *iter << endl;

           }

 

           cout << endl;

           cout << "flist�� ��ҵ� �� �Ϻθ� ������ �� ���� ��ҵ� ���" << endl;

           // ��ȸ �ϸ鼭 �Ϻ� ��� ����

           auto prev_iter = flist.before_begin();

           iter = flist.begin();

           while( iter != flist.end() )

           {

                     if( 3 == *iter )

                     {

                                iter = flist.erase_after( prev_iter );

                                continue;

                     }

                     ++prev_iter;

                     ++iter;

           }

 

           // ��ȸ

           for( iter = flist.begin(); iter != flist.end(); ++iter )

           {

                     cout << *iter << endl;

           }

 

           return 0;

}
*/
