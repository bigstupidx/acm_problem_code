#include<stdio.h>
#include<iostream>
using namespace std;

int map[505][505];
int flag[505],y[505];
int n;

int path(int s)
{
    for(int i=1;i<=n;i++)
    {
        if(map[s][i]&&!flag[i])
        {
            flag[i]=1;
            if(y[i]==0||path(y[i]))
            {
                y[i]=s;
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
    int k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(map,0,sizeof(map));
        for(int i=0;i<k;i++)
        {
            int u,v;
            cin>>u>>v;
            map[u][v]=1;
        }
        printf("%d\n",MaxMatch());
    }
    return 0;
}
