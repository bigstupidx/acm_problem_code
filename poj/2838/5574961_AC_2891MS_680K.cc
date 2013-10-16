#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct node{
    int to;
    node *next;
}nod[40010],*vert[1010];

int n,top;
bool v[1010];
int Bfs(int x,int y)
{
    queue<int>Q;
    if(x==y)return 1;
    memset(v,false,sizeof(v));
    Q.push(x);
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        v[u]=true;
        for(node *p=vert[u];p;p=p->next)
        {
            if(!v[p->to])
            {
                if(p->to==y)return 1;
                Q.push(p->to);
            }
        }
    }
    return 0;
}
int main()
{
    int m,x,y;
    char str[5];
    top=-1;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%s%d%d",str,&x,&y);
        if(str[0]=='I')
        {
            nod[++top].to=y;
            nod[top].next=vert[x];vert[x]=nod+top;

            nod[++top].to=x;
            nod[top].next=vert[y];vert[y]=nod+top;
        }
        else if(str[0]=='D')
        {
            node *p,*q;
            p=vert[x];
            if(p->to==y)vert[x]=p->next;
            else{
                q=p;p=p->next;
                for(;p;q=p,p=p->next)
                    if(p->to==y)q->next=p->next;
            }
            p=vert[y];
            if(p->to==x)vert[y]=p->next;
            else{
                q=p;p=p->next;
                for(;p;q=p,p=p->next)
                    if(p->to==x)q->next=p->next;
            }
        }
        else
        {
            if(Bfs(x,y))puts("Y");
            else puts("N");
        }
    }
    return 0;
}