#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

char str[1010], tem[20];
struct node{
	char str[20];
}nod[30];

int get_num(int i){
	if(strcmp(nod[i].str,"zero")==0)
		return 0;
	else if(strcmp(nod[i].str,"one")==0)
		return 1;
	else if(strcmp(nod[i].str,"two")==0)
		return 2;
	else if(strcmp(nod[i].str,"three")==0)
		return 3;
	else if(strcmp(nod[i].str,"four")==0)
		return 4;
	else if(strcmp(nod[i].str,"five")==0)
		return 5;
	else if(strcmp(nod[i].str,"six")==0)
		return 6;
	else if(strcmp(nod[i].str,"seven")==0)
		return 7;
	else if(strcmp(nod[i].str,"eight")==0)
		return 8;
	else if(strcmp(nod[i].str,"nine")==0)
		return 9;
	else if(strcmp(nod[i].str,"ten")==0)
		return 10;
	else if(strcmp(nod[i].str,"eleven")==0)
		return 11;
	else if(strcmp(nod[i].str,"twelve")==0)
		return 12;
	else if(strcmp(nod[i].str,"thirteen")==0)
		return 13;
	else if(strcmp(nod[i].str,"fourteen")==0)
		return 14;
	else if(strcmp(nod[i].str,"fifteen")==0)
		return 15;
	else if(strcmp(nod[i].str,"sixteen")==0)
		return 16;
	else if(strcmp(nod[i].str,"seventeen")==0)
		return 17;
	else if(strcmp(nod[i].str,"eighteen")==0)
		return 18;
	else if(strcmp(nod[i].str,"nineteen")==0)
		return 19;
	else if(strcmp(nod[i].str,"twenty")==0)
		return 20;
	else if(strcmp(nod[i].str,"thirty")==0)
		return 30;
	else if(strcmp(nod[i].str,"forty")==0)
		return 40;
	else if(strcmp(nod[i].str,"fifty")==0)
		return 50;
	else if(strcmp(nod[i].str,"sixty")==0)
		return 60;
	else if(strcmp(nod[i].str,"seventy")==0)
		return 70;
	else if(strcmp(nod[i].str,"eighty")==0)
		return 80;
	else if(strcmp(nod[i].str,"ninety")==0)
		return 90;
}

int main(){
	while(gets(str)){
		if(strcmp(str, "")==0)break;
		
		int len=strlen(str), i=0;

		str[len++]=' ';
		str[len]='\0';

		while(str[i]==' ')i++;
		int top=0;
		for(int j=i;j<len;j++){
			if(str[j]==' '){
				for(int k=i;k<j;k++){
					tem[k-i]=str[k];
				}
				tem[j-i]='\0';
				strcpy(nod[top].str, tem);
				while(str[j]==' ')j++;
				i=j;
				top++;
			}
		}
		//for(int i=0;i<top;i++){
		//	printf("%s ", nod[i].str);
		//}
		//puts("");
		
		
		int ans=0, flag=1, num=0;
		for(int i=0;i<top;i++){
			if(strcmp(nod[i].str, "negative")==0){
				flag=-1;
			}
			else if(strcmp(nod[i].str, "million")==0){
				ans=num*1000000;
				num=0;
			}
			else if(strcmp(nod[i].str, "thousand")==0){
				ans+=num*1000;
				num=0;
			}
			else if(strcmp(nod[i].str, "hundred")==0){
				num*=100;
			}
			else{
				num+=get_num(i);
			}
		}
		printf("%d\n", flag*(ans+num)); 
	}
	return 0;
}
