#include <iostream>
#include "ParserDom.h"
#include "utils.h"
#include "wincstring.h"
#include<fstream>
using namespace htmlcxx;
using namespace std;
#include<string>

void ToPlainText(string &source,ostream &stream);


int main(int argc, char** argv)
{
	string name,buf;
	getline(cin,name);
	ifstream in(name);
	if(!in.is_open())
	{
		cerr<<"파일열기 에러"<<name<<endl;
		return -1;
	}
	ofstream out(name+".txt");
	while(1)
	{
		getline(in,buf);
		//cout<<buf;
		ToPlainText(buf,out);
		if(in.eof())
			break;
		out<<endl;
	}
	return 0;
}



void walk_tree(tree<HTML::Node> const &root,tree<HTML::Node>::iterator it,ostream& stream);
void convertClose(bool &pre,tree<HTML::Node>::iterator it,ostream &stream);
void convertOpen(bool &pre,tree<HTML::Node>::iterator it,ostream &stream);
const char* TagToText(string s);

void ToPlainText(string &source,ostream &stream)
{
	HTML::ParserDom parser;
	tree<HTML::Node> tr=parser.parseTree(source);
	walk_tree(tr,tr.begin(),stream);
//return ostream;
}
void walk_tree(tree<HTML::Node> const &root,tree<HTML::Node>::iterator it,ostream& stream)
{
	bool pre=false;
	convertOpen(pre,it,stream);
	for(tree<HTML::Node>::sibling_iterator childit=root.begin(it); childit!=root.end(it); ++childit)
	{
		walk_tree(root,childit,stream);
	}
	convertClose(pre,it,stream);
}
void convertOpen(bool &pre,tree<HTML::Node>::iterator it,ostream &stream)
{
	string out;
	if(it->isTag())
	{
		if(stricmp(it->tagName().c_str(),"pre")==0)
		{
			pre=true;
			return;
		}
		if(pre)
		{
			out=it->text();
		}
		else
		{
			out=TagToText(it->tagName());
		}
	}
	else if(it->isComment())
	{
		
	}
	else
	{
		out=it->text();
	}
	stream<<HTML::decode_entities(out);
}
void convertClose(bool &pre,tree<HTML::Node>::iterator it,ostream &stream)
{
	string out;
	if(it->isTag())
	{
		if(stricmp(it->tagName().c_str(),"pre")==0)
		{
			pre=false;
			return;
		}
		if(pre)
		{
			out=it->closingText();
		}
		else
		{
			out=TagToText(it->tagName());
		}
	}
	else if(it->isComment())
	{
		
	}
	else
	{
		out=it->closingText();
	}
	stream<<HTML::decode_entities(out);
}
#include<unordered_map>
#include<algorithm>
const unordered_map<const char*,const char*> Table= {{"br","\n"},{"p","\n "},{"li","\n -"},{"",""}};
const char* TagToText(string s)
{
	transform(s.begin(),s.end(),s.begin(),::tolower);
	if(Table.find(s.c_str())==Table.end())return "";
	return Table.at(s.c_str());
}
