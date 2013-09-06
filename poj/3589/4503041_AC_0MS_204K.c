#include<stdio.h>
void main()
{
	char x[5],y[5];
	int m,n,i,j,t,k;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%s%s",x+1,y+1);
		m=n=0;
		for(j=1;j<5;j++)
			for(k=1;k<5;k++){
				if(x[j]==y[k])
					n++;
				if(x[j]==y[k]&&k==j)
					m++;
			}
		n=n-m;
		printf("%dA%dB\n",m,n);
	}
}



	