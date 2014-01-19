/*
从原数据中观察规律
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100000

double arrey[MAX];

void pre_done()
{
	int i;
	arrey[1]=0.5;
	for(i=2;i<MAX;i++)
		arrey[i]=arrey[i-1]+1.0/(i*2);
	return ;
}
int main()
{
	int n;
	pre_done();
	printf("Cards  Overhang\n");
	while(scanf("%d",&n)!=EOF)
		printf("%5d     %.3lf\n",n,arrey[n]);
	system("pause");
	return 0;
}