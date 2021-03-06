#include<cstdio>
#include<cstring>
#include<queue>
#include<malloc.h>

using namespace std;
int n,top;
struct node{
    int to;
    node *next;
}nd[40010],*vert[1010];
bool v[1010];
int Bfs(int s,int t)
{
    queue<int>Q;
    if(s==t)return 1;
    Q.push(s);
    memset(v,false,sizeof(v));
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        v[u]=true;
        for(node *p=vert[u]; p ;p=p->next)
        {
            if(p->to==t)return 1;
            if(!v[p->to])
                Q.push(p->to);
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
            if(p->to==v){q->next=p->next;free(p);}
    }
    p=vert[v];
    if(p->to==u)vert[v]=p->next;
    else{
        q=p;p=p->next;
        for(;p;p=p->next)
            if(p->to==u){q->next=p->next;free(p);}
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
            char ch;
            getchar();
            scanf("%c %d %d",&ch,&x,&y);
            if(ch=='Q')
            {
                if(Bfs(x,y))puts("Y");
                else puts("N");
            }
            else if(ch=='D') Delete(x,y);
            else Insert(x,y);
        }
    }
    return 0;
}
