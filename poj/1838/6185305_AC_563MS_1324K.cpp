#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#define MAXN 16010
using namespace std;
int par[MAXN],n,k,cnt[MAXN],dir[4][2]={0,1,1,0,0,-1,-1,0};
int Find(int x)
{
    if(par[x]==x)
        return x;
    return par[x]=Find(par[x]);
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        map<pair<int,int>,int>mp;
        map<pair<int,int>,int>::iterator p;
        for(int i=0;i<n;i++)par[i]=i;
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            mp.insert(make_pair(make_pair(x,y),i));
            for(int j=0;j<4;j++)
            {
                p=mp.find(make_pair(x+dir[j][0],y+dir[j][1]));
                if(p!=mp.end())
                {
                    int ii=Find(p->second);
                    par[ii]=i;
                }
            }
        }
        for(int i=0;i<n;i++)Find(i);
        sort(par,par+n);
        memset(cnt,0,sizeof(cnt));
        int top=0;cnt[0]=1;
        for(int i=1;i<n;i++)
        {
            if(par[i]!=par[i-1])
                cnt[++top]=1;
            else
                cnt[top]++;
        }
        sort(cnt,cnt+top+1);
        
        //for(int i=0;i<=top;i++)
        //    printf("%d ",cnt[i]);
        //puts("");
        
        int ans=0;
        for(int i=top;i>=0&&i>top-k;i--)
            ans+=cnt[i];
        printf("%d\n",ans);
    }
    return 0;
}
