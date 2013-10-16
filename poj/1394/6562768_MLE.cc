#include <map>
#include <string>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[100000],*vert[102];
struct QN{
    int u;
    int d;
    bool operator <(const QN &a)const{
        return a.d<d;
    }
};
void add_edge(int x,int y,int st,int ed,int &top){
    //printf("%d -> %d %d %d\n",x,y,st,ed);
    edge *p=&edg[++top];
    p->to=y;
    p->d=st*10000+ed;
    p->next=vert[x];    vert[x]=p;
}
int BFS(int s,int t,edge *p){
    QN now;
    priority_queue<QN>Q;
    now.u=p->to;    now.d=p->d%10000;
    Q.push(now);
    while(!Q.empty()){
        now=Q.top();Q.pop();
        int u=now.u;
        int d=now.d;
        //printf("%d %d\n",u,d);
        if(u==t)return now.d;
        for(edge *p=vert[u];p;p=p->next){
            int st=p->d/10000;
            if(st>=d){
                now.u=p->to;
                now.d=p->d%10000;
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
        char start[50],end[50];
        map<string,int>mp;
        map<string,int>::iterator p,q;
        for(int i=0;i<n;i++){
            scanf("%s",start);
            mp[start]=i;
        }
        int T,top=-1;
        scanf("%d",&T);
        memset(vert,0,sizeof(vert));
        for(int i=0;i<T;i++){
            int tim1,tim2,m;
            scanf("%d",&m);
            for(int j=0;j<m;j++){
                scanf("%d%s",&tim2,end);
                if(j!=0){
                    int u=-1,v=-1;
                    p=mp.find(start);
                    q=mp.find(end);
                    if(p!=mp.end()&&q!=mp.end()&&tim1<=tim2){
                        u=p->second;
                        v=q->second;
                        add_edge(u,v,tim1,tim2,top);
                    }
                }
                strcpy(start,end);
                tim1=tim2;
            }
        }
        scanf("%d%s%s",&T,start,end);
        printf("Scenario #%d\n",nca++);
        int u=-1,v=-1,tim1=-1,tim2=-1;
        p=mp.find(start);
        q=mp.find(end);
        if(p!=mp.end()&&q!=mp.end()){
            u=p->second;
            v=q->second;
            for(edge *p=vert[u];p;p=p->next){
                int st=p->d/10000;
                if(st>=T){
                    int tem=BFS(u,v,p);
                    //printf("%d\n",tem);
                    if(tem!=-1&&(tim2==-1||tim2>tem||tim2==tem&&tim1<st)){
                        tim1=st;
                        tim2=tem;
                    }
                }
            }
            if(tim2==-1)
                puts("No connection");
            else{
                printf("Departure %.4d %s\n",tim1,start);
                printf("Arrival   %.4d %s\n",tim2,end);
            }
        }
        else
            puts("No connection");
        puts("");
    }
    return 0;
}
