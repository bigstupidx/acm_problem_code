/*
打了个表
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 108

double arrey[MAX][MAX];

void pre_done()
{
	int i,j;
	for(i=1;i<=100;i++)
		arrey[i][0]=arrey[i][i]=1;
	arrey[1][1]=1;
	for(i=2;i<=100;i++)
		for(j=1;j<i;j++)
			arrey[i][j]=arrey[i-1][j-1]+arrey[i-1][j];
	return 0;
}

int main()
{
	int n,k;
	pre_done();
	while(scanf("%d%d",&n,&k),n||k)
		printf("%d things taken %d at a time is %.0lf exactly.\n",n,k,arrey[n][k]);
	system("pause");
	return 0;
}