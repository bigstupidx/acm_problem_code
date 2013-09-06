#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <queue>
using namespace std;
struct edge{
    int to;
    int st,ed;
    edge *next;
}edg[100002],*vert[102];
struct QN{
    int u;
    int ed;
    bool operator <(const QN &a)const{
        return a.ed<ed;
    }
};
char st[100],ed[100];
void add_edge(int x,int y,int st,int ed,int &top){
    //printf("%d -> %d %d %d\n",x,y,st,ed);
    edge *p=&edg[++top];
    p->to=y;
    p->st=st;
    p->ed=ed;
    p->next=vert[x];    vert[x]=p;
}
int BFS(int s,int t,int tim){
    QN now,next;
    priority_queue<QN>Q;
    for(edge *p=vert[s];p;p=p->next){
        if(p->st==tim){
            now.u=p->to;
            now.ed=p->ed;
            Q.push(now);
        }
    }
    while(!Q.empty()){
        now=Q.top();Q.pop();
        int u=now.u;
        tim=now.ed;
        if(u==t)return tim;
        for(edge *p=vert[u];p;p=p->next){
            if(p->st>=tim){
                now.u=p->to;
                now.ed=p->ed;
                Q.push(now);
            }
        }
    }
    return -1;
}
int main()
{
    int nca=1,n;
    while(scanf("%d",&n),n){
        int T,top=-1,u,v,tim1,tim2,tim;
        
        map<string,int>mp;
        map<string,int>::iterator p;
        
        for(int i=0;i<n;i++){
            scanf("%s",st);
            mp[st]=i;
        }
        scanf("%d",&T);
        memset(vert,0,sizeof(vert));
        for(int m,i=0;i<T;i++){
            scanf("%d",&m);
            for(int j=0;j<m;j++){
                scanf("%d%s",&tim2,ed);
                if(j!=0){
                    p=mp.find(st);
                    u=p->second;
                    p=mp.find(ed);
                    v=p->second;
                    add_edge(u,v,tim1,tim2,top);
                }
                strcpy(st,ed);
                tim1=tim2;
            } 
        }
        scanf("%d%s%s",&tim,st,ed);
        p=mp.find(st);u=p->second;
        p=mp.find(ed);v=p->second;
        tim1=-1;    tim2=-1;
        for(edge *p=vert[u];p;p=p->next){
            if(p->st >= tim){
                int temp=BFS(u,v,p->st);
                if(temp!=-1&&(tim2==-1||temp<tim2||(temp==tim2&&tim1>p->st))){
                    tim1=p->st;
                    tim2=temp;
                }
            }
        }
        printf("Scenario #%d\n",nca++);
        if(tim2==-1)puts("No connection");
        else{
            printf("Departure %.4d %s\n",tim1,st);
            printf("Arrival   %.4d %s\n",tim2,ed);
        }
        puts("");
    }
    return 0;
}
