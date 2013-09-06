#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int f[25][1000];
int path[25][1000];
int d[300],p[300];

int ans[30];
int m,n;
int i,j,k;

int cmp(const void *e1,const void *e2)
{
	return *(int *)e1-*(int *)e2;
}

void solve(int t)
{
	int middle;

	for(i=1;i<=n;i++)
		scanf("%d%d",&d[i],&p[i]);
	
	middle=m*20;
	memset(f,-1,sizeof(f));
	memset(path,0,sizeof(path));
	f[0][middle]=0;
	
	for(j=0;j<m;j++)
		for(k=0;k<=middle*2;k++)
		{
			if(f[j][k]>=0)
			{
				for(i=1;i<=n;i++)
					if(f[j][k]+d[i]+p[i]>f[j+1][k+d[i]-p[i]])
					{
						int t1,t2;
						t1=j;t2=k;
						while(t1>0&&path[t1][t2]!=i)
						{
							t2-=d[path[t1][t2]]-p[path[t1][t2]];
							t1--;
						}
						if(t1==0)
						{
							f[j+1][k+d[i]-p[i]]=f[j][k]+d[i]+p[i];
							path[j+1][k+d[i]-p[i]]=i;
						}
					}
			}
		}
	i=middle;j=0;
	while(f[m][i+j]<0&&f[m][i-j]<0)
		j++;
	if(f[m][i+j]>f[m][i-j])
		k=i+j;
	else
		k=i-j;
	printf("Jury #%d\n",t);
	printf("Best jury has value %d for prosecution and value %d for defence:\n",(k-middle+f[m][k])/2,(f[m][k]-k+middle)/2);

	for(i=1;i<=m;i++)
	{
		ans[i]=path[m-i+1][k];
		k-=d[ans[i]]-p[ans[i]];
	}
	qsort(ans+1,m,sizeof(int),cmp);
	
	for(i=1;i<m;i++)
		printf("%d ",ans[i]);
	printf("%d\n\n",ans[i]);
	return ;
}

int main()
{
	int t=0;
	while(scanf("%d%d",&n,&m),m||n){
		t++;
		solve(t);
	}
	return 0;
}