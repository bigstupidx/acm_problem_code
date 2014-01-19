/*
不是简简单单的进制转换，具体见change();
*/
#include<stdio.h>
#include<string.h>
char map[26]="ZABCDEFGHIJKLMNOPQRSTUVWXY";
__int64 r,c;
char str[7];
void change()
{
	int i=0,len,j=0;
	char temp[7];
	strcpy(temp,"");strcpy(str,"");
	while(c>0){//a*26*26*26+b*26*26+c*26+d
		int flag=1;
		temp[i++]=map[c%26];
		if(c>26&&c%26<=25&&c%26>=1)
			flag=0;
		c/=26;
		if(flag)c--;
	}
	len=i;
	for(i=len-1;i>=0;i--)
		str[j++]=temp[i];
	str[j]='\0';
	return ;
}
int main()
{
	char x,y;
	while(scanf("%c%I64d%c%I64d",&x,&r,&y,&c),r||c){
		getchar();
		change();
		printf("%s%I64d\n",str,r);
	}
	return 0;
}