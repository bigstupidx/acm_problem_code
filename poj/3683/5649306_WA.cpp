#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#include<algorithm>
#define ones(x) (2*x+1)
#define zeros(x) (2*x)
using namespace std;
struct edge{
    int to;
    edge *next;
}edg[200010],*vert[2020],*r_vert[2020];
int n,top,order[2020],id[2020],start[2020],end[2020],in[2020];
bool v[2020],map[2020][2020];
void Add_Edge(int x,int y)
{
    edge *p=&edg[top++];
    p->to=y;
    p->next=vert[x];vert[x]=p;

    p=&edg[top++];
    p->to=x;
    p->next=r_vert[y];r_vert[y]=p;
}
bool intersect(int i,int j)
{
    if(end[i]<=start[j]||start[i]>=end[j])return false;
    return true;
}
void DFS(int s)
{
    v[s]=1;
    for(edge *p=vert[s];p;p=p->next)
        if(!v[p->to])DFS(p->to);
    order[top++]=s;
}
void DFS_RG(int s)
{
    v[s]=1;
    id[s]=top;
    for(edge *p=r_vert[s];p;p=p->next)
        if(!v[p->to])DFS_RG(p->to);
}
void Color_DFS(int s)
{
    order[s]=2;
    for(edge *p=r_vert[s];p;p=p->next)
        if(order[p->to]==0)Color_DFS(p->to);
}
void Display()
{
    int ret=top;
    for(int i=0;i<ret;i++)
        for(int j=0;j<top;j++)map[i][j]=0;
    memset(in,0,sizeof(in));
    memset(r_vert,0,sizeof(r_vert));top=0;
    for(int i=0;i<2*n;i++)
    {
        for(edge *p=vert[i];p;p=p->next)
        {
            if(id[i]!=id[p->to]&&!map[id[p->to]][id[i]])
            {
                edge *q=&edg[top++];
                q->to=id[i];
                q->next=r_vert[id[p->to]];r_vert[id[p->to]]=q;
                in[id[i]]++;
                map[id[p->to]][id[i]]=1;
            }
        }
    }
    stack<int>S;
    vector<int>aa;
    for(int i=0;i<ret;i++)
        if(!in[i])S.push(i);
    while(!S.empty())
    {
        int i=S.top();S.pop();
        aa.push_back(i);
        for(edge *p=vert[i];p;p=p->next)
        {
            int k=p->to;
            in[k]--;
            if(in[k]==0)S.push(k);
        }
    }
    memset(order,0,sizeof(order));//use to color the node
    for(int i=0;i<aa.size();i++)
    {
        if(order[aa[i]]==0){Color_DFS(aa[i]);order[aa[i]]=1;}
    }
    aa.clear();
    for(int i=0;i<ret;i++)
    {
        if(order[i]==1)
        {
            for(int j=0;j<2*n;j++)
                if(id[j]==i)aa.push_back(j);
        }
    }
    sort(aa.begin(),aa.end());
    for(int i=0;i<aa.size();i++)
        printf("%.2d:%.2d %.2d:%.2d\n",start[aa[i]]/60,start[aa[i]]%60,end[aa[i]]/60,end[aa[i]]%60);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        top=0;
        for(int i=0;i<2*n;i++){vert[i]=NULL;r_vert[i]=NULL;}
        for(int i=0;i<n;i++)
        {
            int a1,a2,b1,b2,c;
            scanf("%d:%d %d:%d %d",&a1,&a2,&b1,&b2,&c);
            a1=a1*60+a2;b1=b1*60+b2;
            start[zeros(i)]=a1;end[zeros(i)]=a1+c;
            start[ones(i)]=b1-c;end[ones(i)]=b1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(intersect(zeros(i),zeros(j)))
                {
                    printf("%d->%d %d->%d\n",2*i,2*j+1,2*j,2*i+1);
                    Add_Edge(zeros(i),ones(j));
                    Add_Edge(zeros(j),ones(i));
                }
                if(intersect(zeros(i),ones(j)))
                {
                    printf("%d->%d %d->%d\n",2*i,2*j,2*j+1,2*i+1);
                    Add_Edge(zeros(i),zeros(j));
                    Add_Edge(ones(j),ones(i));
                }
                if(intersect(ones(i),zeros(j)))
                {
                    printf("%d->%d %d->%d\n",2*i+1,2*j+1,2*j,2*i);
                    Add_Edge(ones(i),ones(j));
                    Add_Edge(zeros(j),zeros(i));
                }
                if(intersect(ones(i),ones(j)))
                {
                    printf("%d->%d %d->%d\n",2*i+1,2*j,2*j+1,2*i);
                    Add_Edge(ones(i),zeros(j));
                    Add_Edge(ones(j),zeros(i));
                }
            }
        }
        memset(v,0,sizeof(v));top=0;
        for(int i=0;i<2*n;i++)
        {
            printf("i :%d\n",i);
            for(edge *p=vert[i];p;p=p->next)
                printf("%d ",p->to);
            puts("");
        }
        for(int i=0;i<2*n;i++)
            if(!v[i])DFS(i);

        memset(v,0,sizeof(v));top=0;
        for(int i=2*n-1;i>=0;i--)
            if(!v[order[i]]){DFS_RG(order[i]);top++;}
        bool flag=false;
        for(int i=0;i<n;i++)
            if(id[ones(i)]==id[zeros(i)]){flag=true;break;}
        if(flag){puts("NO");continue;}
        else{
            puts("YES");
            Display();
        }
    }
    return 0;
}
