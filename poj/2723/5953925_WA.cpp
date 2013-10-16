#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int top,oppo[1200],n,m,door[2500][2],visit[2400],id[2400],order[2400];
vector<int>map[2400],r_map[2400];
void DFS(int s)
{
    visit[s]=1;
    for(int j=0;j<map[s].size();j++)
        if(!visit[map[s][j]])DFS(map[s][j]);
    order[top++]=s;
}
void DFS_RG(int s)
{
    visit[s]=1;
    id[s]=top;
    for(int j=0;j<r_map[s].size();j++)
        if(!visit[r_map[s][j]])DFS_RG(r_map[s][j]);
}
bool Solve(int md)
{
    for(int i=0;i<2*n;i++)map[i].clear();
    for(int i=1;i<=md;i++){
        map[door[i][0]].push_back(oppo[door[i][1]]);
        map[door[i][1]].push_back(oppo[door[i][0]]);
        r_map[oppo[door[i][1]]].push_back(door[i][0]);
        r_map[oppo[door[i][0]]].push_back(door[i][1]);
    }
    top=1;
    memset(visit,0,sizeof(visit));
    for(int i=0;i<2*n;i++)
        if(!visit[i])DFS(i);
    top=0;
    memset(visit,0,sizeof(visit));
    for(int i=2*n;i>0;i--)
        if(!visit[order[i]]){DFS_RG(order[i]);top++;}
    for(int i=0;i<2*n;i++)
        if(id[i]==id[oppo[i]])return false;
    return true;
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        int x,y;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            oppo[x]=y;  oppo[y]=x;
        }
        for(int i=1;i<=m;i++)
            scanf("%d%d",&door[i][0],&door[i][1]);
        int l=1,r=m,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(Solve(mid))
                l=mid+1;
            else
                r=mid-1;
        }
        printf("%d\n",l);
    }
    return 0;
}
