#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

bool mark[10010];
long long fic[52];
double tim[10010], inf = 1e100;
int v, r, c, t, map[102][102],dir[4][2]={-1,0,1,0,0,-1,0,1};

struct QN{
    int u;
    double time, x, y;
    bool operator <(const QN &a)const{
        return a.time < time;
    }
}now, next;

double BFS(){
    priority_queue<QN>Q;
    now.u=0;
    now.time=0;
    now.x=1;
    now.y=1;
    Q.push(now);
    for(int i=0;i<=t;i++){mark[i]=0;tim[i]=inf;}
    tim[0]=0;
    while(!Q.empty()){
        now=Q.top();
        Q.pop();
        if(mark[now.u])continue;
        mark[now.u]=true;
        if(now.u==t)return now.time;
        int rr=now.u/c;
        int cc=now.u%c;
        for(int j=0;j<4;j++){
            int ii=rr+dir[j][0];
            int jj=cc+dir[j][1];
            if(ii>=0&&ii<r&&jj>=0&&jj<c){
                next.u=ii*c+jj;
                if(mark[next.u]||tim[next.u]<now.time+now.y/now.x)continue;
                tim[next.u]=now.time+now.y/now.x;
                next.time=tim[next.u];
                int tem = map[ii][jj]-map[rr][cc];
                if(tem<0){
                    next.x=now.x*fic[-tem];
                    next.y=now.y;
                }
                else{
                    next.y=now.y*fic[tem];
                    next.x=now.x;
                }
                Q.push(next);
            }
        }
    }
}
void pre_done(){
    fic[0]=1;
    for(int i=1;i<51;i++){
        fic[i]=fic[i-1]*2;
    }
}
int main(){
    pre_done();
    while(scanf("%d%d%d", &v, &r, &c)!=EOF){
        t = r * c - 1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                scanf("%d", &map[i][j]);
            }
        }
        printf("%.2lf\n", BFS());
    }
    return 0;
}