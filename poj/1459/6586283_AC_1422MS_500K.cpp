#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;
struct edge{
    int to,c,f,next;
}e[30010];
int n,np,nc,m,head[120],L[120],p[120][2];
void add_edge(int x,int y,int va,int &top){
    e[++top].to=y;  e[top].c=va;
    e[top].f=0;     e[top].next=head[x];    head[x]=top;
    
    e[++top].to=x;  e[top].c=0;
    e[top].f=0;     e[top].next=head[y];    head[y]=top;
}
int max_flow(int s,int t){
    int flow=0;
    while(1){
        queue<int>Q;
        memset(L,-1,sizeof(L));
        Q.push(s);L[s]=0;
        while(!Q.empty()){
            int i=Q.front();Q.pop();
            for(int j=head[i];j!=-1;j=e[j].next){
                if(L[e[j].to]==-1&&e[j].c>e[j].f){
                    L[e[j].to]=L[i]+1;
                    Q.push(e[j].to);
                }
            }
        }
        if(L[t]==-1)return flow;
        int top=0;
        p[0][0]=s;  p[0][1]=head[s];
        while(top>=0){
            if(p[top][0]!=t){
                while(p[top][1]>=0){
                    int x=p[top][1];
                    if(L[p[top][0]]<L[e[x].to]&&e[x].c>e[x].f){
                        p[top+1][0]=e[x].to;
                        p[top+1][1]=head[p[top+1][0]];
                        top++;break;
                    }
                    p[top][1]=e[x].next;
                }
                if(p[top][1]<0){
                    top--;
                    if(top<0)break;
                    p[top][1]=e[p[top][1]].next;
                }
            }
            else{
                int mini=1000000000,k=top-1;
                for(int i=0;i<top;i++){
                    if(mini>e[p[i][1]].c-e[p[i][1]].f)
                        mini=e[p[i][1]].c-e[p[i][1]].f;
                }
                flow+=mini;
                for(int i=top-1;i>=0;i--){
                    e[p[i][1]].f+=mini;
                    e[p[i][1]^1].f-=mini;
                    if(e[p[i][1]].f==e[p[i][1]].c)
                        k=i;
                }
                top=k;
                p[top][1]=e[p[top][1]].next;
            }
        }
    }
}
int main(){
    while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF){
        char ch;
        int top=-1,u,v,d;
        memset(head,-1,sizeof(head));
        for(int i=0;i<m;i++){
            while((ch=getchar())!='(');
            scanf("%d%c%d",&u,&ch,&v);
            scanf("%c%d",&ch,&d);
            add_edge(u,v,d,top);
        }
        for(int i=0;i<np;i++){
            while((ch=getchar())!='(');
            scanf("%d%c%d",&u,&ch,&d);
            add_edge(n,u,d,top);
        }
        for(int i=0;i<nc;i++){
            while((ch=getchar())!='(');
            scanf("%d%c%d",&u,&ch,&d);
            add_edge(u,n+1,d,top);
        }
        printf("%d\n",max_flow(n,n+1));
    }
        //system("pause");
    return 0;
}
