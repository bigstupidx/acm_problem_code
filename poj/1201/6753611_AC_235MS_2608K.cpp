#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[10000010],*vert[50010];
const int inf= 100000000;
int n,dis[50010],flag[50010];
void add_edge(int x,int y,int va,int &top){
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
int spfa(int s,int t){
    queue<int>Q;
    for(int i=s;i<=t;i++){flag[i]=0;dis[i]=-inf;}
    flag[s]=1;dis[s]=0;
    Q.push(s);
    while(!Q.empty()){
        int i=Q.front();Q.pop();
        for(edge *p=vert[i];p;p=p->next){
            if(dis[p->to]<dis[i]+p->d){
                dis[p->to]=dis[i]+p->d;
                if(!flag[p->to]){
                    flag[p->to]=1;
                    Q.push(p->to);
                }
            }
        }
        flag[i]=0;
    }
    return dis[t];
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        int top=-1,maxi=-inf,mini=inf;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<n;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(a-1<mini)mini=a-1;
            if(b>maxi)maxi=b;
            add_edge(a-1,b,c,top);
        }
        for(int i=mini;i<maxi;i++){
            add_edge(i,i+1,0,top);
            add_edge(i+1,i,-1,top);
        }
        printf("%d\n",spfa(mini,maxi));
    }
    return 0;
}
