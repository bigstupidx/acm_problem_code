#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[1010][1010],dp[1010][1010];
int main()
{
	int i,j,n,c;
	
	while (scanf("%d",&c)!=EOF) {
		scanf("%d",&n);
		int k,ans=1000000000;
		for (i=1;i<=n;i++) for (j=i;j<=n;j++) scanf("%d",a[i]+j);
		memset(dp,0,sizeof(dp));
		for (i=1;i<=n;i++) for (j=n;j>i;j--)a[i][j]-=a[i][j-1];
		for (i=1;i<=n;i++)
			dp[1][i]=a[1][i]+c;
		for (i=1;i<=n;i++) 
			for (j=i;j<=n;j++) {
			if (j>i) dp[i][j]=dp[i][j-1]+a[i][j];
			if (i>1&&i==j) {
				for (k=1;k<=i-1;k++)
				if(dp[i][j]<dp[k][j-1]+a[i][j]+c)
					dp[i][j]=dp[k][j-1]+a[i][j]+c;
			}
		}
		for (i=1;i<=n;i++)
			if(ans<dp[i][n])
				ans=dp[i][n];
		printf("%d\n",ans);
	}
        system("pause");
        return 0;
}
