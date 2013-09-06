

#include<stdio.h>

long n,query;
long min[18][50001],max[18][50001];
long left,right;

void initial_rmq()
{
	long t,i,j=0,fac;
	fac=1;
	while(fac*2<=n){
		fac*=2;
		j++;
		t=n-fac+1;
		for(i=1;i<=t;i++){
			min[j][i]=min[j-1][i]<min[j-1][i+fac/2]?min[j-1][i]:min[j-1][i+fac/2];
			max[j][i]=max[j-1][i]>max[j-1][i+fac/2]?max[j-1][i]:max[j-1][i+fac/2];
		}
	}
}

long rmq()
{
	long i=0,t=1,l=right-left+1;
	while(t*2<=l){
		t*=2;i++;
	}
	return (max[i][left]>max[i][right-t+1]?max[i][left]:max[i][right-t+1])
		-(min[i][left]<min[i][right-t+1]?min[i][left]:min[i][right-t+1]);
}

int main()
{
	long i;
	scanf("%ld%ld",&n,&query);
	for(i=1;i<=n;i++){
		scanf("%d",&max[0][i]);
		min[0][i]=max[0][i];
	}
	initial_rmq();
	for(i=0;i<query;i++){
		scanf("%ld%ld",&left,&right);
		printf("%ld\n",rmq());
	}
	return 0;
}
