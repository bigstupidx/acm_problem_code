#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <cstdlib>
#include <map>
using namespace std;

struct edge{
    int to;
    int d;
    edge *next;
}edg[100002],*vert[102];
struct QN{
    int u;
    int d;
    bool operator <(const QN &a)const{
        return a.d<d;
    }
};
int n,dis[102],mark[102];
const int inf = 10000;
void add_edge(int x,int y,int t1,int t2,int &top){
    edge *p=&edg[++top];
    p->to=y;
    p->d=t1*10000+t2;
    p->next=vert[x];    vert[x]=p;
}
void dijkstra(int s,int t,int st){
    QN now;
    priority_queue<QN>Q;
    for(int i=0;i<n;i++){dis[i]=inf;mark[i]=0;}
    now.u=s;    now.d=st;   dis[s]=st;
    Q.push(now);
    while(!Q.empty()){
        now=Q.top();Q.pop();
        if(now.u==t)return ;
        int u=now.u;
        int d=now.d;
        for(edge *p=vert[u];p;p=p->next){
            if((p->d/10000>=d)&&((p->d%10000)<dis[p->to])){
                dis[p->to]=p->d%10000;
                now.u=p->to;
                now.d=p->d%10000;
                Q.push(now);
            }
        }
    }
}
int main()
{
    int nca=1;
    while(scanf("%d",&n)!=EOF){
        char sta[50],end[50];
        int id=0,top=-1,T;
        map<string,int>mp;
        map<string,int>::iterator p,q;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<n;i++){
            scanf("%s",sta);
            p=mp.find(sta);
            if(p==mp.end()){
                mp[sta]=id++;
            }
        }
        n=id;
        scanf("%d",&T);
        for(int j=0;j<T;j++){
            int m,tim1,tim2;
            scanf("%d",&m);
            for(int i=0;i<m;i++){
                scanf("%d%s",&tim2,end);
                if(i!=0){
                    p=mp.find(sta);
                    q=mp.find(end);
                    if(p!=mp.end()&&q!=mp.end()&&tim1<=tim2){
                        add_edge(p->second,q->second,tim1,tim2,top);
                    }
                }
                strcpy(sta,end);
                tim1=tim2;
            }
        }
        scanf("%d%s%s",&T,sta,end);
        int u=-1,v=-1;
        p=mp.find(sta);
        q=mp.find(end);
        if(p!=mp.end())
            u=p->second;
        if(q!=mp.end())
            v=q->second;
        printf("Scenario #%d\n",nca++);
        if(u==-1||v==-1){
            puts("No connection\n");
            continue;
        }
        else{
            dijkstra(u,v,T);
            int best=dis[v];
            if(best==10000)
                puts("No connection\n");
            else{
                int l=0,r=2500,mid;
                while(l<=r){
                    mid=(l+r)/2;
                    dijkstra(u,v,mid);
                    int tem=dis[v];
                    if(tem==best)
                        l=mid+1;
                    else
                        r=mid-1;
                }
                printf("Departure %.4d %s\n",r,sta);
                printf("Arrival   %.4d %s\n\n",best,end);
            }
        }
    }
    return 0;
}
