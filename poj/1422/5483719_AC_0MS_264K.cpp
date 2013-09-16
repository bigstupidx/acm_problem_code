#include<iostream>
using namespace std;
int map[122][122];
int y[122],flag[122];
int n;
int path(int u)
{
    for(int i=1;i<=n;i++)
    {
        if(!flag[i] && map[u][i])
        {
            flag[i]=1;
            if(y[i]==0||path(y[i]))
            {
                y[i]=u;
                return 1;
            }
        }
    }
    return 0;
}
int MaxMatch()
{
    int ans=0;
    memset(y,0,sizeof(y));
    for(int i=1;i<=n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(path(i))ans++;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        memset(map,0,sizeof(map));
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            map[u][v]=1;
        }
        printf("%d\n",n-MaxMatch());
    }
}
