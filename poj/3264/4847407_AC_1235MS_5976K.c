

#include<stdio.h>

long n,query;
long min[18][50001],max[18][50001];
long left,right;

void initial_rmq()
{
	long t=1,j=1,i;
	while(t*=2,j++,t<=n)
		for(i=t;i<=n;i++){
			min[j][i]=min[j-1][i]<min[j-1][i-t/2]?min[j-1][i]:min[j-1][i-t/2];
			max[j][i]=max[j-1][i]>max[j-1][i-t/2]?max[j-1][i]:max[j-1][i-t/2];
		}
}

long rmq_check()
{
	long l=right-left+1,t=1,i=1;
	while(t*2<=l){
		i++;t*=2;
	}
	return (max[i][right]>max[i][left+t-1]?max[i][right]:max[i][left+t-1])
		-(min[i][right]<min[i][left+t-1]?min[i][right]:min[i][left+t-1]);
}
int main()
{
	long i;
	scanf("%ld%ld",&n,&query);
	for(i=1;i<=n;i++){
		scanf("%ld",&min[1][i]);
		max[1][i]=min[1][i];
	}
	initial_rmq();
	for(i=0;i<query;i++){
		scanf("%ld%ld",&left,&right);
		printf("%ld\n",rmq_check());
	}
	return 0;
}

