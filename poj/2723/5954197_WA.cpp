#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int top,oppo[1200],n,m,door[2500][2],v[2400],id[2400],order[2400];
vector<int>map[2400],r_map[2400];
void DFS(int s)
{
    v[s]=1;
    for(int j=0;j<map[s].size();j++)
        if(!v[map[s][j]])DFS(map[s][j]);
    order[top++]=s;
}
void DFS_RG(int s)
{
    v[s]=1;
    id[s]=top;
    for(int j=0;j<r_map[s].size();j++)
        if(!v[r_map[s][j]])DFS_RG(r_map[s][j]);
}
bool Solve(int mid)
{
    for(int i=0;i<2*n;i++)
    {
        map[i].clear();
        r_map[i].clear();
    }
    for(int i=0;i<=mid;i++)
    {
        map[door[i][0]].push_back(oppo[door[i][1]]);
        map[door[i][1]].push_back(oppo[door[i][0]]);
        r_map[oppo[door[i][0]]].push_back(door[i][1]);
        r_map[oppo[door[i][1]]].push_back(door[i][0]);
    }
    memset(v,0,sizeof(v));top=0;
    for(int i=0;i<2*n;i++)
        if(!v[i])DFS(i);

    memset(v,0,sizeof(v));top=1;
    for(int i=2*n-1;i>=0;i--)
        if(!v[order[i]]){DFS_RG(order[i]);top++;}

    for(int i=0;i<2*n;i++)
        if(id[i]==id[oppo[i]])return false;
    return true;
}

int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            oppo[x]=y;  oppo[y]=x;
        }
        for(int i=0;i<m;i++)
            scanf("%d%d",&door[i][0],&door[i][1]);
        int l=0,r=m-1,ans=-1,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            //printf("left right %d %d try mid %d\n",l,r,mid);
            if(Solve(mid)){
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
