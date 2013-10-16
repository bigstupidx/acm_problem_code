#include<stdio.h>
int arrey[10001];
int a[10001];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,ans=0;
		for(i=0;i<n;i++)
			scanf("%d",arrey+i);
		a[0]=1;
		for(i=1;i<n;i++)
		{
			int j,temp=1;
			for(j=0;j<i;j++)
				if(arrey[i]>arrey[j]&&a[j]+1>=temp)
					temp=a[j]+1;
			a[i]=temp;
		}
		for(i=0;i<n;i++)
			if(a[i]>ans)
				ans=a[i];
		printf("%d\n",ans);
	}
	return 0;
}