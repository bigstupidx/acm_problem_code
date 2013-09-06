#include <cstdio>
#include <cstring>
#define ones(x) (2*x+1)
#define zeros(x) (2*x)
struct edge{
    int to;
    edge *next;
}edg[10000000],*vert[2020],*r_vert[2020];
int n,top,order[2020],id[2020];
bool v[2020];
void Add_Edge(int x,int y)
{
    edge *p=&edg[top++];
    p->to=y;
    p->next=vert[x];vert[x]=p;

    p=&edg[top++];
    p->to=x;
    p->next=r_vert[y];r_vert[y]=p;
}
void Go_And(int a,int b,int c)
{
    if(c==1){
        Add_Edge(ones(a),ones(b));
        Add_Edge(ones(b),ones(a));
        Add_Edge(zeros(a),ones(a));
        Add_Edge(zeros(b),ones(b));
    }
    else{
        Add_Edge(ones(a),zeros(b));
        Add_Edge(ones(b),zeros(a));
    }
}
void Go_Xor(int a,int b,int c)
{
    if(c==1){
        Add_Edge(ones(a),zeros(b));
        Add_Edge(ones(b),zeros(a));
        Add_Edge(zeros(a),ones(b));
        Add_Edge(zeros(b),ones(a));
    }
    else{
        Add_Edge(ones(a),ones(b));
        Add_Edge(zeros(a),zeros(b));
        Add_Edge(ones(b),ones(a));
        Add_Edge(zeros(b),zeros(a));
    }
}
void Go_Or(int a,int b,int c)
{
    if(c==1){
        Add_Edge(zeros(a),ones(b));
        Add_Edge(zeros(b),ones(a));
    }
    else{
        Add_Edge(zeros(a),zeros(b));
        Add_Edge(ones(a),zeros(a));
        Add_Edge(ones(b),zeros(b));
    }
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
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        char str[10];
        int a,b,c;
        top=0;
        for(int i=0;i<2*n;i++){vert[i]=NULL;r_vert[i]=NULL;}
        while(m--){
            scanf("%d%d%d%s",&a,&b,&c,str);
            if(strcmp(str,"AND")==0)Go_And(a,b,c);
            else if(strcmp(str,"XOR")==0)Go_Xor(a,b,c);
            else Go_Or(a,b,c);
        }
        memset(v,0,sizeof(v));top=0;
        for(int i=0;i<2*n;i++)
            if(!v[i])DFS(i);
/*        for(int i=0;i<2*n;i++)
            printf("%d ",order[i]);
        puts("");*/
        memset(v,0,sizeof(v));top=0;
        for(int i=2*n-1;i>=0;i--)
            if(!v[order[i]]){DFS_RG(order[i]);top++;}
/*
        for(int i=0;i<2*n;i++)
            printf("%d ",id[i]);
        puts("");*/
        bool flag=false;
        for(int i=0;i<n;i++)
            if(id[zeros(i)]==id[ones(i)]){flag=true;break;}
        if(flag)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
