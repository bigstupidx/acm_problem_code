#include<cstdio>
#include<cstring>

int n,top,v[1010],queue[100000];
struct node{
    int to;
    node *next;
}nd[40010],*vert[1010];
int Bfs(int s,int t)
{
    int u,front,tail;
    if(s==t)return 1;
    memset(v,0,sizeof(v));
    v[s]=1;
    front=0;tail=0;
    queue[tail++]=s;
    while(front<tail)
    {
        u=queue[front++];
        for(node *p=vert[u]; p ;p=p->next)
        {
            if(p->to==t)return 1;
            if(!v[p->to])
            {
                v[p->to]=1;
                queue[tail++]=p->to;
            }
        }
    }
    return 0;
}
void Insert(int u,int v)
{
    node *p=&nd[top++];
    p->to=v;
    p->next=vert[u];vert[u]=p;

    p=&nd[top++];
    p->to=u;
    p->next=vert[v];vert[v]=p;
}
void Delete(int u,int v)
{
    node *p,*q;
    p=vert[u];
    if(p->to==v)vert[u]=p->next;
    else{
        q=p;p=p->next;
        for(;p;p=p->next)
            if(p->to==v)q->next=p->next;
    }
    p=vert[v];
    if(p->to==u)vert[v]=p->next;
    else{
        q=p;p=p->next;
        for(;p;p=p->next)
            if(p->to==u)q->next=p->next;
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int x,y,q;
        top=0;
        for(int i=1;i<=n;i++)
            vert[i]=NULL;
        scanf("%d",&q);
        while(q--)
        {
            char str[5];
            scanf("%s %d %d",&str,&x,&y);
            if(str[0]=='Q')
            {
                if(Bfs(x,y))puts("Y");
                else puts("N");
            }
            else if(str[0]=='D') Delete(x,y);
            else Insert(x,y);
        }
    }
    return 0;
}
