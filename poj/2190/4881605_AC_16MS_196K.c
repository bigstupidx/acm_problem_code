
#include<stdio.h>
char str[12];
int main()
{
	int i,t=-1,flag=0,sum=0;
	scanf("%s",str);
	for(i=0;i<9;i++){
		if(str[i]=='?'){
			t=i;continue;
		}
		sum+=(10-i)*(str[i]-'0');
	}
	if(t!=-1&&t!=9){
		if(str[9]=='X')
		  sum+=10;
		else
		  sum+=str[9]-'0';
	}
	if(t==-1)t=1;
	else t=10-t;
	for(i=0;i<=9;i++){
		if(!((sum+t*i)%11)){
			flag=1;break;
		}
	}
	if(t==1)//出现在最后一位
		if(!((sum+10)%11)){
			printf("X\n");
			return 0;
	}
	if(flag)
		printf("%d\n",i);
	else
		printf("-1\n");
	return 0;
}



















