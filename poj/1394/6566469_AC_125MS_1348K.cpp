#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[100000],*vert[102];
const int inf = 10000;
int dis[102],mark[102],n;
struct QN{
    int ii;
    bool operator <(const QN &a)const{
        return dis[a.ii]<dis[ii];
    }
};
void add_edge(int x,int y,int t1,int t2,int &top){
    edge *p=&edg[++top];
    p->to=y;
    p->d=t1*10000+t2;
    p->next=vert[x];    vert[x]=p;
}
int dijkstra(int s,int t,int T){
    QN now;
    priority_queue<QN>Q;
    for(int i=0;i<n;i++){dis[i]=inf;mark[i]=0;}
    now.ii=s;   dis[s]=T;   mark[s]=1;
    Q.push(now);
    while(!Q.empty()){
        now=Q.top();Q.pop();
        int i=now.ii;
        if(i==t)break;
        mark[i]=0;
        for(edge *p=vert[i];p;p=p->next){
            if(p->d/10000>=dis[i]&&p->d%10000<=dis[p->to]){
                dis[p->to]=p->d%10000;
                if(!mark[p->to]){
                    mark[p->to]=1;
                    now.ii=p->to;
                    Q.push(now);
                }
            }
        }
    }
    return dis[t];
}
int main()
{
    int nca=1;
    while(scanf("%d",&n),n){
        char sta[50],end[50];
        int T,top=-1,id=0;
        map<string,int>mp;
        map<string,int>::iterator p,q;
        for(int i=0;i<n;i++){
            scanf("%s",sta);
            p=mp.find(sta);
            if(p==mp.end()){
                mp[sta]=id++;
            }
        }
        n=id;
        scanf("%d",&T);
        memset(vert,0,sizeof(vert));
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
        int s=-1,t=-1;
        p=mp.find(sta);
        q=mp.find(end);
        if(p!=mp.end())
            s=p->second;
        if(q!=mp.end())
            t=q->second;
        printf("Scenario #%d\n",nca++);
        if(s!=-1&&t!=-1){
            int best=dijkstra(s,t,T);
            if(best==inf)puts("No connection");
            else{
                int l=0,r=2400;
                while(l<=r){
                    int mid=(l+r)/2;
                    int tem=dijkstra(s,t,mid);
                    if(tem==best)l=mid+1;
                    else
                        r=mid-1;
                }
                printf("Departure %.4d %s\n",r,sta);
                printf("Arrival   %.4d %s\n",best,end);
            }
        }
        else
            puts("No connection\n");
        puts("");
        
    }
    return 0;
}
