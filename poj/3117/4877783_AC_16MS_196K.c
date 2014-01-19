#include<stdio.h>
int t,n;
int main()
{
	while(scanf("%d%d",&t,&n),t){
		char name[12];
		int i,temp,ans=0;
		for(i=0;i<t;i++){
			scanf("%s%d",name,&temp);
		    ans+=temp;
		}
		printf("%d\n",3*n-ans);
	}
	return 0;
}