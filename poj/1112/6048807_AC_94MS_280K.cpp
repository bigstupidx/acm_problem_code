#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct node{
    int nn[2];
    vector<int>aa[2];
}st[102];
int n,top,map[102][102],visit[102],pp[102][102];
bool flag,dp[102][102];
vector<int>ans1,ans2;
bool DFS(int s,int cc)
{
    visit[s]=cc;
    st[top].nn[cc]++;
    st[top].aa[cc].push_back(s);
    for(int i=1;i<=n;i++)
    {
        if(map[s][i]||map[i][s])
        {
            if(visit[i]==-1)
            {
                if(!DFS(i,cc^1))return false;
            }
            else if(visit[i]==visit[s])
            {
                flag=false;return false;
            }
        }
    }
    return true;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                map[i][j]=1;
        for(int i=1;i<=n;i++)map[i][i]=0;
        for(int j,i=1;i<=n;i++)
        {
            while(scanf("%d",&j),j)map[i][j]=0;
        }
        top=1;flag=true;
        for(int i=0;i<=n;i++){
            st[i].nn[0]=st[i].nn[1]=0;
            st[i].aa[0].clear();st[i].aa[1].clear();
        }
        memset(visit,-1,sizeof(visit));
        for(int i=1;i<=n;i++){
            if(visit[i]==-1){
                if(!DFS(i,0))break;
                top++;
            }
        }
        if(!flag)puts("No solution");
        else{
            memset(dp,0,sizeof(dp));
            dp[0][0]=1;
            for(int i=1;i<top;i++){
                for(int j=0;j<=n;j++){
                    if(dp[i-1][j]){
                        dp[i][j+st[i].nn[0]]=1;pp[i][j+st[i].nn[0]]=0;
                        dp[i][j+st[i].nn[1]]=1;pp[i][j+st[i].nn[1]]=1;
                    }
                }
            }
            int k=n/2;
            while(k>=0&&!dp[top-1][k])k--;
            printf("%d",k);
            ans1.clear();ans2.clear();
            for(int j=top-1,i=k;j>=0;j--)
            {
                int x=pp[j][i];
                for(int ii=0;ii<st[j].aa[x].size();ii++)
                    ans1.push_back(st[j].aa[x][ii]);
                for(int ii=0;ii<st[j].aa[x^1].size();ii++)
                    ans2.push_back(st[j].aa[x^1][ii]);
                i-=st[j].nn[x];
            }
            for(int i=0;i<ans1.size();i++)
                printf(" %d",ans1[i]);
            printf("\n%d",n-k);
            for(int i=0;i<ans2.size();i++)
                printf(" %d",ans2[i]);
            puts("");
        }
    }
    return 0;
}
