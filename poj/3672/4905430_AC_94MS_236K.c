#include<stdio.h>
int main()
{
	int m,i,t,u,f,d,sum=0,x=0;
	int flag=1;
	scanf("%d%d%d%d%d",&m,&t,&u,&f,&d);
	for(i=0;i<t;i++)
	{
		char s[2],c;
		scanf("%s",s);
		if(flag){
			c=s[0];
			switch(c){
			case 'u':{
				if(sum+u+d<=m){
					sum+=u+d;x++;}
				else flag=0;
				break;}
			case 'f':{
				if(sum+2*f<=m){
					sum+=2*f;x++;}
				else flag=0;
				break;}
			case 'd':{
				if(sum+u+f<=m){
					sum+=u+d;x++;}
				else flag=0;
				break;}
			}
		}
	}
	printf("%d\n",x);
	system("pause");
	return 0;
}
