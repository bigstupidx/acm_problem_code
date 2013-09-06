#include <cstdio>
#include <map>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	char title[82];
	char auther[82];
	int flag;
	bool operator <(const node &a)const{
		if(strcmp(a.auther, auther)==0){
			return strcmp(a.title, title) > 0;
		}
		return strcmp(a.auther, auther) > 0;
	}
}nod[10010];

char str[200];

int top;
map<string, int>mp;
map<int, string>tem;
map<int, string>::iterator p;

void my_input(){
	int len;
	while(gets(str), strcmp(str, "END")!=0){
		len=strlen(str);
		int i=0, j, x;
		while(str[i]!='"')i++;
		j=i+1;x=i+1;
		while(str[j]!='"')j++;
		for(i++;i<j;i++){
			nod[top].title[i-x]=str[i];
		}
		nod[top].title[j-x]='\0';
		while(str[j]!='b')j++;
		while(str[j]!='y')j++;
		j++;
		while(str[j]==' ')j++;
		for(i=j;j<len;j++){
			nod[top].auther[j-i]=str[j];
		}
		nod[top].flag=0;
		top++;
	}
	sort(nod, nod+top);
	for(int i=0;i<top;i++){
		mp[nod[i].title]=i;
		//printf("%s %s\n", nod[i].title, nod[i].auther);
	}
}

void solve(){
	for(p=tem.begin();p!=tem.end();p++){
		int i=mp.find(p->second)->second, j=i-1;
		while(j>=0&&nod[j].flag==1)j--;
		if(j==-1){
			cout<<"Put \""<<p->second<<"\" first";
		}
		else{
			cout<<"Put \""<<p->second<<"\" after ";
			printf("\"%s\"", nod[j].title);
		}
		nod[i].flag=0;
		puts("");
	}
	tem.clear();
	puts("END");
}

int main(){
	mp.clear();
	my_input();
	while(scanf("%s", str), strcmp(str, "END")!=0){
		if(strcmp(str, "RETURN")==0){
			getchar();
			getchar();
			gets(str);
			int len=strlen(str), i;
			str[len-1]='\0';
			i=mp.find(str)->second;
			tem[i]=str;
		}
		else if(strcmp(str, "BORROW")==0){
			getchar();
			getchar();
			gets(str);
			int len=strlen(str), i;
			str[len-1]='\0';
			i=mp.find(str)->second;
			nod[i].flag=1;
		}
		else{
			solve();
		}
	}
	system("pause");
	return 0;
}
