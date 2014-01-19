#include<stdio.h>

void feikai(long x,int *a)
{
	int i=0;
	while(x){
		a[i++]=x%10;
		x/=10;
	}
	return ;
}
		
int main()
{
	long a,b,sum=0;
	int i,j,answer[2][10];
	while(scanf("%ld%ld",&a,&b)==2){
		memset(answer[0],0,sizeof(answer[0]));
		memset(answer[1],0,sizeof(answer[1]));
		feikai(a,answer[0]);
		feikai(b,answer[1]);
		for(i=0;i<10;i++)
			for(j=0;j<10;j++)
				sum+=answer[0][i]*answer[1][j];
		printf("%ld\n",sum);
	}
	return 0;
}
		



		
