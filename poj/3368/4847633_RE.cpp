
#include<stdio.h>
#include<math.h>
long n,q;
long sum[100010];
long query[100010];
long count;
long max[40][100010];

void initial_rmq()
{
	int i,j=0,fac;
	for(i=1;i<=n;i++)
		max[0][i]=sum[i];
	fac=1;
	while(fac*2<n){
		fac*=2;
		int m=n-fac+1;
		j++;
		for(i=1;i<=m;i++)
			max[j][i]=max[j-1][i]>max[j-1][i+fac/2]?max[j-1][i]:max[j-1][i+fac/2];
	}
}

long rmq_check(long left,long right)
{
	long l=right-left+1,t=1,i=0;
	while(t*2<=l){
		i++;t*=2;
	}
	return max[i][left]>max[i][right-t+1]?max[i][left]:max[i][right-t+1];
}

int main()
{
	while(scanf("%ld",&n),n){
		long i,j=1,a,b;
		count=1;query[0]=0;
		scanf("%ld",&q);
		scanf("%ld",&a);
		for(i=1;i<n;i++){
			scanf("%ld",&b);
			if(b==a){
				count++;continue;}
			sum[j]=count;
			query[j]=count+query[j-1];
			count=1;j++;
			a=b;
		}
		if(a==b){
			sum[j]=count;query[j]=count+query[j-1];
			n=j;
		}
		else
			n=j-1;
		initial_rmq();
		for(i=0;i<q;i++){
			long a1,b1,answer=0;
			scanf("%ld",&a1);
			for(i=1;;i++)
		       if(query[i]>=a1)break;
			scanf("%ld",&b1);
	        for(j=i;;j++)
		       if(query[j]>=b1)break;
			if(j-1>i)
				answer=rmq_check(i+1,j-1);
			if(answer<query[i]-a1+1)
				answer=query[i]-a1+1;
			if(answer<sum[j]-query[j]+b1)
				answer=sum[j]-query[j]+b1;
			printf("%ld\n",answer);
		}
	}
	return 0;
}