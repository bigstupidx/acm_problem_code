#include<stdio.h>
int main()
{
	int n,j;
	while(scanf("%d",&n)==1){
		printf("%d\n",n-1);
		for(j=n-1;j>0;j--)
			printf("1 1 %d\n",j);
	}
	return 0;
}
