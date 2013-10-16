
#include<stdio.h>
#include<math.h>
long n,q;
long sum[100010];
long count;
long a1,b1;
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

void solve()
{
	long i,j,ii,temp=0,s,cl,cr;
	int k;
	for(i=1,cl=sum[1];;)
		if(cl>=a1)break;
		else cl+=sum[++i];
	for(j=i,cr=cl;;)
		if(cr>=b1)break;
		else cr+=sum[++j];
	if(i<j-1)
		k=(int)(log((float)(j-i-1))/log((float)(2)));
	else k=0;
	s=j-(long)pow((double)2,k);

	if(i<j-1)
		temp=max[k][i+1]>max[k][j-s]?max[k][i+1]:max[k][j-s];
	
	if(temp<cl-a1+1)temp=cl-a1+1;
	if(temp<sum[j]-cr+b1)temp=sum[j]-cr+b1;
	
	printf("%ld\n",temp);
}

int main()
{
	while(scanf("%ld",&n),n){
		long i,j=1,a,b;
		count=1;
		scanf("%ld",&q);
		scanf("%ld",&a);
		for(i=1;i<n;i++){
			scanf("%ld",&b);
			if(b==a){count++;a=b;continue;}
			sum[j++]=count;
			count=1;
			a=b;
		}
		n=j;
		sum[j]=count;
		initial_rmq();
		for(i=0;i<q;i++){
			scanf("%ld%ld",&a1,&b1);
			solve();
		}
	}
	return 0;
}