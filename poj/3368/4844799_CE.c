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
	long i,j,ii,temp,s,cl,cr;
	int k;
	for(i=1,cl=sum[1];;)
		if(cl>=a1)break;
		else cl+=sum[++i];
	for(j=i,cr=cl;;)
		if(cr>=b1)break;
		else cr+=sum[++j];
	if(i<j-1)
		k=(int)(log(j-i-1)/log(2));
	else k=0;
	s=j-(int)pow(2,k);
	
	temp=cl-a1+1;
	for(ii=i+1;ii<=s;ii++)
		if(max[k][ii]>temp)temp=max[k][ii];
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
		sum[j]=count;
		n=j;
		initial_rmq();
		for(i=0;i<q;i++){
			scanf("%ld%ld",&a1,&b1);
			solve();
		}
	}
	return 0;
}