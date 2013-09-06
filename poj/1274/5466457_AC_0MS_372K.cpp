#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int map[204][204],m,n;
int flag[204],y[204];

int path(int s)
{
    for(int i=1;i<=m;i++)
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
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(map,0,sizeof(map));
        for(int i=1;i<=n;i++)
        {
            int t;
            cin>>t;
            for(int j=0;j<t;j++)
            {
                int u;
                cin>>u;
                map[i][u]=1;
            }
        }
        printf("%d\n",MaxMatch());
    }
    return 0;
}
