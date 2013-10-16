#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <string>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[100002],*vert[102];
struct QN{
    int u;
    int start,d;
    bool operator <(const QN &a)const{
        if(a.d==d)
            return a.start>start;
        return a.d<d;
    }
};
int dis[102];
void add_edge(int x,int y,int tim1,int tim2,int &top){
    edge *p=&edg[++top];
    p->to=y;
    p->d=tim1*10000+tim2;
    p->next=vert[x];    vert[x]=p;
}
void dijkstra(int s,int t,int &st,int &ed,int X,int n){
    QN now,next;
    priority_queue<QN>Q;
    for(int i=0;i<n;i++)dis[i]=10000;
    for(edge *p=vert[s];p;p=p->next){
        if(p->d/10000>=X){
            now.u=p->to;
            now.start=p->d/10000;
            now.d=p->d%10000;
            Q.push(now);
        }
    }
    while(!Q.empty()){
        now=Q.top();Q.pop();
        //printf("%d %d\n",now.u,now.d);
        if(now.u==t){
            st=now.start;ed=now.d;
            return ;
        }
        int u=now.u;
        int d=now.d;
        for(edge *p=vert[u];p;p=p->next){
            if(p->d/10000>=d&&(p->d%10000<dis[p->to])){
                now.u=p->to;
                now.d=p->d%10000;
                dis[p->to]=p->d%10000;
                Q.push(now);
            }
        }
    }
}
int main()
{
    int nca=1,n;
    while(scanf("%d",&n),n){
        char sta[50],end[50];
        map<string,int>mp;
        map<string,int>::iterator p,q;
        for(int i=0;i<n;i++){
            scanf("%s",sta);
            mp[sta]=i;
        }
        int T,top=-1;
        memset(vert,0,sizeof(vert));
        scanf("%d",&T);
        for(int i=0;i<T;i++){
            int u,v,m,tim1,tim2;
            scanf("%d",&m);
            for(int j=0;j<m;j++){
                scanf("%d%s",&tim2,end);
                if(j!=0){
                    p=mp.find(sta);
                    q=mp.find(end);
                    if(p!=mp.end()&&q!=mp.end()&&tim1<=tim2){
                        u=p->second;
                        v=q->second;
                        add_edge(u,v,tim1,tim2,top);
                    }
                }
                strcpy(sta,end);
                tim1=tim2;
            }
        }
        scanf("%d%s%s",&T,sta,end);
        int u=-1,v=-1;
        p=mp.find(sta);
        if(p!=mp.end())
            u=p->second;
        p=mp.find(end);
        if(p!=mp.end())
            v=p->second;
        printf("Scenario #%d\n",nca++);
        if(u==-1||v==-1){
            puts("No connection\n");
        }
        else{
            int tim1=-1,tim2=1000000;
            dijkstra(u,v,tim1,tim2,T,n);
            if(tim2==1000000)
                puts("No connection\n");
            else{
                printf("Departure %.4d %s\n",tim1,sta);
                printf("Arrival   %.4d %s\n\n",tim2,end);
            }
        }
    }
    return 0;
}
