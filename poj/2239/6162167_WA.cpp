#include <cstdio>
#include <cstring>
bool map[320][100],flag[100];
int n,my[320];
bool path(int s)
{
    for(int i=1;i<=84;i++)
    {
        if(!flag[i]&&map[s][i])
        {
            flag[i]=true;
            if(my[i]==-1||path(my[i]))
            {
                my[i]=s;
                return true;
            }
        }
    }
    return false;
}
int max_match()
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
        memset(map,0,sizeof(map));
        for(int i=0;i<n;i++)
        {
            int m;
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
                int p,q;
                scanf("%d%d",&p,&q);
                map[i][p*q]=true;
            }
        }
        printf("%d\n",max_match());
    }
    return 0;
}
