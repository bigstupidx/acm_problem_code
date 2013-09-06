#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
struct node{
    int p,gg;
    bool operator<(const node nw)const
    {
        if(nw.gg==gg)
            return nw.p>p;
        return nw.gg>gg;
    }
}cow[100010],shop[100010];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&cow[i].p,&cow[i].gg);
        for(int i=0;i<m;i++)
            scanf("%d%d",&shop[i].p,&shop[i].gg);
        sort(cow,cow+n);    sort(shop,shop+m);
    //  for(int i=0;i<n;i++)
    //        printf("%d->%d\n",cow[i].gg,cow[i].p);
        __int64 sum=0,flag=0,t=m-1;
        multimap<int,int>mp;
        multimap<int,int>::iterator p;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=t;j>=0;j--)
            {
                if(shop[j].gg<cow[i].gg){t=j;break;}
                mp.insert(make_pair(shop[j].p,1));
            }
            p=mp.lower_bound(cow[i].p);
            if(p==mp.end()){flag=1;break;}
            sum+=p->first;
            mp.erase(p);
        }
        if(flag)puts("-1");
        else printf("%I64d\n",sum);
    }
    return 0;
}
