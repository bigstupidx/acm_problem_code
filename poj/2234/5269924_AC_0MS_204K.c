#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,ans,temp;
		scanf("%d",&ans);
		for(i=1;i<n;i++){
			scanf("%d",&temp);
			ans^=temp;
		}
		if(!ans)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}