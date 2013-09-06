#include<cstdio>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;
struct edge{
    int to;
    edge *next;
}edg[10010],*vert[100];
int n,anc[100],visit[100],dep[100],tem[100],color[100];
char str[1000];
void Add_Edge(int x,int y,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
void DFS(int k,int k_father,int depth)
{
    color[k]=1;
    anc[k]=dep[k]=depth;
    int tot=0;
    for(edge *p=vert[k];p;p=p->next)
    {
        int i=p->to;
        if(i!=k_father && color[i]==1)
            anc[k]=anc[k]>dep[i]?dep[i]:anc[k];
        if(color[i]==0)
        {
            tot++;
            DFS(i,k,depth+1);
            anc[k]=anc[i]>anc[k]?anc[k]:anc[i];
            if(k==0&&tot>1||k!=0&&anc[i]>=dep[k])
                visit[k]=1;
        }
    }
    color[k]=2;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        int top=-1;
        memset(vert,0,sizeof(vert));
        while(1){
            gets(str);
            string st(str);
            istringstream in(st);
            int m=0;
            while(in>>tem[m])m++;
            if(tem[0]==0)break;
            for(int i=1;i<m;i++){
                Add_Edge(tem[0],tem[i],top);
                Add_Edge(tem[i],tem[0],top);
            }
        }
        memset(color,0,sizeof(color));
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=n;i++)
            if(!color[i])DFS(i,0,1);
        int ans=0;
        for(int i=1;i<=n;i++)
            if(visit[i])ans++;
        printf("%d\n",ans);
    }
    return 0;
}
