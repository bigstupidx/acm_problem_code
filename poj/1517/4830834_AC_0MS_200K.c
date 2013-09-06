#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,num[10];
	double sum[10];
	num[0]=1;
	for(i=2,num[1]=1;i<10;i++)
		num[i]=num[i-1]*i;
	for(i=1,sum[0]=1;i<10;i++)
		sum[i]=sum[i-1]+(double)1/num[i];
	printf("n e\n- -----------\n");
	printf("0 1\n");
		printf("1 2\n");

			printf("2 2.5\n");

	for(i=3;i<10;i++)
		printf("%d %.9lf\n",i,sum[i]);
	return 0;
}
	