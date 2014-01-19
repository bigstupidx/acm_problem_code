#include<stdio.h>
int aa[10001];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int i,j,ans=0,n,temp;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",aa+i);
		for(i=1;i<=n;i++){
			if(aa[i]==i)continue;
			for(j=i;j<=n;j++)
				if(aa[j]==i){
					ans++;
					temp=aa[i];
					aa[i]=i;
					aa[j]=temp;
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}