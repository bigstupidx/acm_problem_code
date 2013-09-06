#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <string>
using namespace std;
struct edge{
    int to;
    double d;
    edge *next;
}edg[10010],*vert[50];
double dis[50];
int n,m,cnt[50],flag[50];
char str[2][100];
void add_edge(int x,int y,double va,int &top){
    //printf("%d -> %d %lf\n",x,y,va);
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
bool bellman_ford(){
    queue<int>Q;
    for(int i=0;i<n;i++){dis[i]=0;cnt[i]=0;flag[i]=1;Q.push(i);}
    while(!Q.empty()){
        int s=Q.front();Q.pop();
        flag[s]=0;
        for(edge *p=vert[s];p;p=p->next){
            if(dis[p->to]<dis[s]+p->d){
                dis[p->to]=dis[s]+p->d;
                if(!flag[p->to]){
                    if(++cnt[p->to]>n)return true;
                    flag[p->to]=1;
                    Q.push(p->to);
                }
            }
        }
    }
    return false;
}
int main()
{
    int nca=1;
    while(scanf("%d",&n),n){
        int top=-1,u,v;
        map<string,int>mp;
        map<string,int>::iterator p;
        for(int i=0;i<n;i++){
            scanf("%s",str[0]);
            mp[str[0]]=i;
        }
        scanf("%d",&m);
        memset(vert,0,sizeof(vert));
        for(int i=0;i<m;i++){
            double tem;
            scanf("%s%lf%s",str[0],&tem,str[1]);
            p=mp.find(str[0]);
            u=p->second;
            p=mp.find(str[1]);
            v=p->second;
            add_edge(u,v,log(tem),top);
        }
        printf("Case %d: ",nca++);
        if(bellman_ford())
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
