#include<stdio.h>
#include<stdlib.h>

int solve(int n)
{
	int count=1;
	while(n!=1){
		count ++;
		if(n%2)
			n=3*n+1;
		else
			n/=2;
	}
	return count;
}

int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
		int i,max=0,temp,x=m,y=n;
		if(x>y)
			temp=x,x=y,y=temp;
		for(i=x;i<=y;i++){
			temp=solve(i);
			if(temp>max)
				max=temp;
		}
		printf("%d %d %d\n",m,n,max);
	}
	system("pause");
	return 0;
}
