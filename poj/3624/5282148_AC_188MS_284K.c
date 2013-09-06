#include<stdio.h>
#include<string.h>
#define MAX 3404

int c[13000];
int w[MAX],p[MAX];
int n,m;
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		int i,j;
		for(i=1;i<=n;i++)
			scanf("%d%d",w+i,p+i);
		memset(c,0,sizeof(c));
		for(i=1;i<=n;i++)
			for(j=m;j>=w[i];j--){
				if(p[i]+c[j-w[i]]>c[j])
					c[j]=p[i]+c[j-w[i]];
			}
		printf("%d\n",c[m]);
	}
	return 0;
}