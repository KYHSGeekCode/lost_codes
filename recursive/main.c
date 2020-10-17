#include <stdio.h>
#include <stdlib.h>
#include <io.h>
int del;

char cmd[256];

void find()
{
  struct _finddata_t file;// file검색을 위한 구조체 정의
  int flag=-1;
  int handle=-1;              // 검색 결과 보관 핸들
  system(cmd);
  handle=_findfirst("*.*",&file);
  if (!handle) {        // file이 하나도 없을 경우
     printf("file Not found !!\n");
     goto end;
  }
  do {        // 더이상 없을 때까지 계속 찾음
        //printf("found %s\n",file.name); 
        if((file.attrib&_A_SUBDIR)){      //dir이라면
                                 if(file.name[0]!='.'){
                                                       chdir(file.name);
                                                       printf(">>directory %s\n",file.name);
                                                       find();
                                 }
        }  
        flag=_findnext(handle,&file);     // 다음 file을 찾음
  }while (flag!=-1);
  end:
      printf("return\n");
      _findclose(handle);
      chdir(".."); 
}

int main(int argc, char *argv[])
{
	if(argc>1){
		strncpy(cmd,argv[1],255);
		puts(cmd);
	}
		
    del=0;
    int ans;
    printf("delete?");
    scanf("%c",&ans);
    if((char)ans=='y'||(char)ans=='Y')del=1;
    printf("recursive\n\n");
    puts("enter command:");
    fgets(stdin,cmd,255);
    find();
    system("PAUSE");	
    return 0;
}
