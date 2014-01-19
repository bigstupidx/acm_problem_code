#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{int x,y;}nod[800];
int par[800],n,m;
struct edge{
    int x,y;
    double va;
    bool operator<(const edge a)const
    {
        return a.va>va;
    }
}edg[600000];
vector<pair<int,int> >ans;
inline double Distance(int i,int j)
{
    double ax=nod[i].x-nod[j].x;
    double by=nod[i].y-nod[j].y;
    return sqrt(ax*ax+by*by);
}
int Find(int x){if(par[x]==-1)return x;return par[x]=Find(par[x]);}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(par,-1,sizeof(par));
        for(int i=1;i<=n;i++)
            scanf("%d%d",&nod[i].x,&nod[i].y);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            int x,y,ii,jj;
            scanf("%d%d",&x,&y);
            ii=Find(x);jj=Find(y);
            if(ii!=jj)par[ii]=jj;
        }
        ans.clear();
        int k=0;
        for(int i=1;i<=n;i++)
        {
            int ii=Find(i);
            for(int j=i+1;j<=n;j++)
            {
                int jj=Find(j);
                if(par[ii]!=jj){
                    edg[k].x=i;
                    edg[k].y=j;
                    edg[k++].va=Distance(i,j);
                }
            }
        }
        sort(edg,edg+k);
        for(int i=0;i<k;i++)
        {
            int ii=Find(edg[i].x);
            int jj=Find(edg[i].y);
            if(ii!=jj)
            {
                par[ii]=jj;
                ans.push_back(make_pair(edg[i].x,edg[i].y));
            }
        }
        if(ans.size()==0)puts("");
        else{
            for(int i=0;i<ans.size();i++)
                printf("%d %d\n",ans[i].first,ans[i].second);
        }
    }
    return 0;
}
