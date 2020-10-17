#include <iostream>
#include <fstream>

#include <sstream>
#include <string>
using namespace std;
#include <windows.h>

int Html2Txt(string inf,string outf)
{
	string strbuf;
	bool intag=false;
	bool inpre;
	ifstream infile;
	ofstream outfile;
	infile.open(inf.c_str(),ios::in);
	outfile.open(outf.c_str(),ios::out);
	if(!infile.is_open()||!outfile.is_open())return -1;
	while(getline(infile,strbuf))
	{
		LPTSTR buf=strdup(strbuf.c_str());
		while(*buf!=TEXT('\0'))
		{
			if(*buf==TEXT('<'))
			{
				if(!inpre)
				{
					intag=true;
					++buf;
					if(strncmp(buf,"pre>",4)==0)
					{
						buf+=4;
						inpre=true;
						intag=false;
						continue;
					}
					else if(strncmp(buf,"/pre>",5)==0)
					{
						inpre=false;
						intag=false;
						buf+=5;
						continue;
					}
				}
				else
				{
					++buf;
					continue;
				}
			}
			else if(*buf==TEXT('>'))
			{
				intag=false;
			}
			if(intag)
			{
				++buf;
				continue;
			}
			if(strncmp(buf,"<",4)==0)
			{
				strbuf+='<';
				buf+=4;
				continue;
			}
			if(strncmp(buf,">",4)==0)
			{
				strbuf+='>';
				buf+=4;
				continue;
			}
			strbuf+=*buf;
			++buf;
		}
		free(buf);
		strbuf+=TEXT('\n');
		outfile<<strbuf;
	}
	outfile.close();
	infile.close();
	return 0;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	return 0;
}
