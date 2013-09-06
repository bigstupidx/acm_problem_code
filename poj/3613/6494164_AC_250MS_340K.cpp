#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
const int inf = 1000000000;
int m,k,n,g[120][120],ans[120][120],tem[120][120];
void multi_by(int k){
    if(k==1){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ans[i][j]=g[i][j];
        return ;
    }
    multi_by(k/2);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tem[i][j]=inf;
            for(int k=0;k<n;k++)
                if(tem[i][j]>ans[i][k]+ans[k][j])
                    tem[i][j]=ans[i][k]+ans[k][j];
        }
    }
    if(k%2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=inf;
                for(int k=0;k<n;k++)
                    if(ans[i][j]>tem[i][k]+g[k][j])
                        ans[i][j]=tem[i][k]+g[k][j];
            }
        }
    }
    else{
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ans[i][j]=tem[i][j];
    }
}
int main()
{
    int s,t;
    while(scanf("%d%d%d%d",&k,&m,&s,&t)!=EOF){
        map<int,int>mp;
        map<int,int>::iterator p;
        mp[s]=0;    mp[t]=1;
        int id=2;
        for(int i=0;i<120;i++)
            for(int j=0;j<120;j++)
                g[i][j]=inf;
        for(int i=0;i<m;i++){
            int u,v,va,x,y;
            scanf("%d%d%d",&va,&u,&v);
            p=mp.find(u);
            if(p==mp.end()){
                mp[u]=id;
                x=id++;
            }
            else x=p->second;
            p=mp.find(v);
            if(p==mp.end()){
                mp[v]=id;
                y=id++;
            }
            else y=p->second;
            if(g[x][y]>va)
                g[x][y]=g[y][x]=va;
        }
        n=id;
        multi_by(k);
        printf("%d\n",ans[0][1]);
    }
    return 0;
}
