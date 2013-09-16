#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#define MAXN 1002
#define MAXM 100010
struct edge{
	int to,next;
	double d;
}e[100010];
struct node{
    double x,y;
}nd[120];
int n,pre[120],head[120],r_head[120];
bool flag[120],visit[120];
const double inf=1000000000;
/*
邻接表实现，0 为根结点，结点编号0~n-1
*/
double Distance(int i,int j)
{
    return sqrt((nd[i].x-nd[j].x)*(nd[i].x-nd[j].x)+
        (nd[i].y-nd[j].y)*(nd[i].y-nd[j].y));
}
void Add_Edge(int x,int y,double d,int &top)
{
	e[++top].to=y;		e[top].d=d;
	e[top].next=head[x];	head[x]=top;
	
	e[++top].to=x;		e[top].d=d;
	e[top].next=r_head[y];	r_head[y]=top;
}
void DFS(int s)
{
	visit[s]=true;
	for(int j=head[s];j!=-1;j=e[j].next){
		if(!visit[e[j].to])DFS(e[j].to);
	}
}
double Mini_ST()
{
	double ans=0;
	memset(flag,0,sizeof(flag));
	while(1){
		int i;
        double mini;
		for(i=1;i<n;i++)
        {
			if(flag[i])continue;
			mini=inf;
			for(int j=r_head[i];j!=-1;j=e[j].next)
            {
				if(!flag[e[j].to]&&e[j].d<mini)
                {
					pre[i]=j;
					mini=e[j].d;
				}
			}
		}
		for(i=1;i<n;i++)
		{
			if(flag[i])continue;
			int j=i;
			memset(visit,0,sizeof(visit));
			visit[0]=true;
			do{
				visit[j]=true;
				j=e[pre[j]].to;
			}while(!visit[j]);
			
			if(!j)continue;
			i=j;
			ans+=e[pre[i]].d;
			for(j=e[pre[i]].to;j!=i;j=e[pre[j]].to)
            {
				flag[j]=1;
				ans+=e[pre[j]].d;
			}
			for(j=r_head[i];j!=-1;j=e[j].next)
			{
			     if(!flag[e[j].to])
                 {
			         e[j].d-=e[pre[i]].d;
			         e[j^1].d-=e[pre[i]].d;
                }
            }
            for(j=e[pre[i]].to;j!=i;j=e[pre[j]].to)
            {
                for(int k=head[j];k!=-1;)
                {
                    int x=e[k].next;
                    if(!flag[e[k].to]&&e[k].to!=i)
                    {
                        e[k].next=head[i];    head[i]=k;
                        e[k^1].to=i;
                    }
                    k=x;
                }
                for(int k=r_head[j];k!=-1;)
                {
                    int x=e[k].next;
                    if(!flag[e[k].to]&&e[k].to!=i)
                    {
                        e[k].next=r_head[i];    r_head[i]=k;
                        e[k^1].d=(e[k].d-=e[pre[j]].d);
                        e[k^1].to=i;
                    }
                    k=x;
                }
            }
            break;
		}
		if(i==n){
			for(i=1;i<n;i++)
				if(!flag[i])
					ans+=e[pre[i]].d;
			break;
		}
	}
	return ans;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int top=-1;
		memset(head,-1,sizeof(head));
		memset(r_head,-1,sizeof(r_head));
		for(int i=0;i<n;i++)
		    scanf("%lf%lf",&nd[i].x,&nd[i].y);
		while(m--)
        {
			int x,y;
			scanf("%d%d",&x,&y);
			x--;y--;
			if(x==y)continue;//消除自环 
			Add_Edge(x,y,Distance(x,y),top);
		}
		
        memset(visit,0,sizeof(visit));	DFS(0);
		for(int i=0;i<n;i++)
			if(!visit[i])goto exit;
		
        printf("%.2lf\n",Mini_ST());
		continue;
	exit:puts("poor snoopy");
    }
	return 0;
}
