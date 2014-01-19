#include<iostream>
using namespace std;
int p[1005][1005];
int main()
{
	int n,i,j;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&p[i][j]);
		int ture=1;
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-1;j++)
				if(p[i][j]+p[i+1][j+1]!=p[i][j+1]+p[i+1][j])
				{
					ture=0;
					break;
				}
			if(ture==0)
				break;
		}
		if(ture==1)
			printf("homogeneous\n");
		else
			printf("not homogeneous\n");
	}
	return 0;

}
