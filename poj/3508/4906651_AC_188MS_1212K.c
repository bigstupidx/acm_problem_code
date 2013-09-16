
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000010

char digit[MAX];

void determine()
{
	int i,len;
	len=strlen(digit);
	if(len==1) return ;
	for(i=len-2;i>0;i--){
		if(digit[i]<digit[i+1]){
			digit[i-1]--;
			digit[i]=digit[i]+10-digit[i+1]+'0';
		}
		else
			digit[i]=digit[i]-digit[i+1]+'0';
	}
	if(digit[0]<digit[1])
		digit[0]=digit[0]+10-digit[1]+'0';
	
	else
		digit[0]=digit[0]-digit[1]+'0';
	if(digit[0]<='0')
		strcpy(digit,"IMPOSSIBLE");
	return ;
}
int main()
{
	int t=0;
	while(1){
		t++;
		scanf("%s",digit);
		if(digit[0]=='0')
			break;
		determine();
		printf("%d. %s\n",t,digit);
	}
	system("pause");
	return 0;
}