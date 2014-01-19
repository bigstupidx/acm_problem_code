#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int c[100][100],pre[100],n;
vector<int>mp[100];
const int inf = 1000000000;
int get_size(char ch)
{   //S - small, M - medium, L - large,
    // X - extra large, T - extra extra large
    if(ch=='S')return 1;
    if(ch=='M')return 2;
    if(ch=='L')return 3;
    if(ch=='X')return 4;
    if(ch=='T')return 5;
}
int max_flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        queue<int>Q;
        memset(pre,-1,sizeof(pre));
        Q.push(s);
        while(!Q.empty()&&pre[t]==-1)
        {
            int i=Q.front();Q.pop();
            for(int j=0;j<=t;j++)
            {
                if(pre[j]==-1&&c[i][j]>0)
                {
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[t]==-1)return flow;
        int mini=inf;
        for(int i=t;i!=s;i=pre[i])
            if(mini>c[pre[i]][i])
                mini=c[pre[i]][i];
        flow+=mini;
        for(int i=t;i!=s;i=pre[i])
        {
            c[pre[i]][i]-=mini;
            c[i][pre[i]]+=mini;
        }
    }
}
int main()
{
    char str[100];
    while(scanf("%s",str),strcmp(str,"ENDOFINPUT")!=0)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",str);
            mp[i].clear();
            int l=get_size(str[0]);
            int r=get_size(str[1]);
            if(l==r)mp[i].push_back(l);
            else{
                for(int j=l;j<=r;j++)
                    mp[i].push_back(j);
            }
        }
        memset(c,0,sizeof(c));
        for(int i=1;i<=5;i++)
        {
            int tem;
            scanf("%d",&tem);
            c[n+i][n+6]=tem;
        }
        for(int i=1;i<=n;i++)
        {
            c[0][i]=1;
            for(int j=0;j<mp[i].size();j++)
                c[i][mp[i][j]]=1;
        }
        if(max_flow(0,n+6)==n)puts("T-shirts rock!");
        else puts("I'd rather not wear a shirt anyway...");
        scanf("%s",str);
    }
    return 0;
}
