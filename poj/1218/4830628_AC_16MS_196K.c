#include<stdio.h>
int cell[102];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int i,count=0,n;
		memset(cell,1,sizeof(cell));
		scanf("%d",&n);
		for(i=2;i<=n;i++){
			int j;
			for(j=1*i;j<=n;j+=i)
				if(cell[j]) cell[j]=0;
				else cell[j]=1;
		}
		for(i=1;i<=n;i++)
			if(cell[i])count++;
		printf("%d\n",count);
	}
	return 0;
}