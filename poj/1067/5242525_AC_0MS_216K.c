#include<stdio.h>
const double d=1.6180339887498948482045;
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		int k;
		if(a==b){
			printf("1\n");
			continue;
		}
		if(a>b)k=a-b,a=b;
		else
			k=b-a;
		if(a==(int)(k*d))
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}
