#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int>map1[4000],map2[4000];
bool v[4000];
int n,id[4000],top,oppo[4000],door[4000][2],order[4000];
void DFS(int s)
{
    v[s]=1;
    for(int i=0;i<map1[s].size();i++)
        if(!v[map1[s][i]])DFS(map1[s][i]);
    order[top++]=s;
}
void RG_DFS(int s)
{
    v[s]=1;
    id[s]=top;
    for(int i=0;i<map2[s].size();i++)
        if(!v[map2[s][i]])RG_DFS(map2[s][i]);
}
bool solve(int mid)
{
    top=0;
    for(int i=0;i<2*n;i++)
    {
        map1[i].clear();
        map2[i].clear();
    }
    for(int i=0;i<=mid;i++)
    {
        map1[door[i][0]].push_back(oppo[door[i][1]]);
        map1[door[i][1]].push_back(oppo[door[i][0]]);
        map2[oppo[door[i][0]]].push_back(door[i][1]);
        map2[oppo[door[i][1]]].push_back(door[i][0]);
    }
    memset(v,0,sizeof(v));top=0;
    for(int i=0;i<2*n;i++)
        if(!v[i])DFS(i);

    memset(v,0,sizeof(v));top=1;
    for(int i=2*n-1;i>=0;i--)
        if(!v[order[i]]){RG_DFS(order[i]);top++;}

    for(int i=0;i<2*n;i++)
        if(id[i]==id[oppo[i]])return false;
    return true;
}
int main( )
{
    int m;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            oppo[x]=y;oppo[y]=x;
        }
        for(int i=0;i<m;i++)
            scanf("%d%d",&door[i][0],&door[i][1]);
        int l=0,r=m-1,ans=-1,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(solve(mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        printf("%d\n",ans+1);
    }
    return 0;
}