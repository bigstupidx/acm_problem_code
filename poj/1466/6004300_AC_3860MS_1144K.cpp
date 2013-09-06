#include <cstdio>
#include <cstring>
int n,map[502][502],flag[502],my[502];
bool path(int s)
{
    for(int i=0;i<n;i++)
    {
        if(!flag[i]&&map[s][i])
        {
            flag[i]=1;
            if(my[i]==-1||path(my[i]))
            {
                my[i]=s;
                return true;
            }
        }
    }
    return false;
}
int Max_Match()
{
    int ans=0;
    memset(my,-1,sizeof(my));
    for(int i=0;i<n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(path(i))ans++;
    }
    return ans;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int m,x,y;
        memset(map,0,sizeof(map));
        for(int i=0;i<n;i++)
        {
            scanf("%d%*c%*c%*c%d%*c",&x,&m);
            for(int i=0;i<m;i++)
            {
                scanf("%d",&y);
                map[x][y]=1;
            }
        }
        printf("%d\n",n-Max_Match()/2);
    }
    return 0;
}
