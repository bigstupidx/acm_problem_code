#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
bool visit[102];
int n,top,order[102],id[102],in[102],out[102];
vector<int>front[102],back[102];
void DFS(int s){
    visit[s]=1;
    for(int i=0;i<front[s].size();i++){
        int v=front[s][i];
        if(!visit[v]){
            DFS(v);
        }
    }
    order[top++]=s;
}
void DFS_RG(int s){
    visit[s]=1;
    id[s]=top;
    for(int i=0;i<back[s].size();i++){
        int v=back[s][i];
        if(!visit[v]){
            DFS_RG(v);
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            front[i].clear();
            back[i].clear();
        }
        for(int v,i=0;i<n;i++){
            while(scanf("%d",&v),v){
                --v;
                front[i].push_back(v);
                back[v].push_back(i);
            }
        }
        top=1;
        memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++){
            if(!visit[i])DFS(i);
        }
        
        top=0;
        memset(visit,0,sizeof(visit));
        for(int i=n;i>0;i--){
            if(!visit[order[i]]){
                DFS_RG(order[i]);
                top++;
            }
        }
        if(top==1)
            printf("1\n0\n");
        else{
            memset(in,0,sizeof(in));
            memset(out,0,sizeof(out));
            for(int i=0;i<n;i++){
                int u=id[i];
                for(int j=0;j<front[i].size();j++){
                    int v=id[front[i][j]];
                    if(u!=v){
                        in[v]++;
                        out[u]++;
                    }
                } 
            }
            int mx=0,my=0,mz=0;
            for(int i=0;i<top;i++){
                if(!in[i]&&!out[i])mz++;
                else if(!in[i]&&out[i])my++;
                else if(in[i]&&!out[i])mx++;
            }
            int ans=mz+(mx>my?mx:my);
            printf("%d\n%d\n",mz+my,ans);
        }
    }
    return 0;
}
