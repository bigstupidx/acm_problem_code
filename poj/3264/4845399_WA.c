#include<stdio.h>
#include<math.h>

long n,query;
long arr[50000];
long min[30][50000],max[30][50000];
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
	long j,temp1,temp2,i=0;
	long t=1,l=right-left+1;
	while(t*2<=l){
		t*=2;i++;}
	for(j=left+1,temp1=max[i][left],temp2=min[i][left];j<=right-t+1;j++){
		if(temp1<max[i][j])temp1=max[i][j];
		if(temp2>min[i][j])temp2=max[i][j];
	}
	return temp1-temp2;
}


int main()
{
	long i;
	scanf("%ld%ld",&n,&query);
	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		min[0][i]=max[0][i]=arr[i];
	}
	initial_rmq();
	for(i=0;i<query;i++){
		scanf("%ld%ld",&left,&right);
		printf("%ld\n",rmq());
	}
	return 0;
}
