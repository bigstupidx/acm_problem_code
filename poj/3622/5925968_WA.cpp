#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
struct node{
    __int64 p,gg;
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
            scanf("%I64d%I64d",&cow[i].p,&cow[i].gg);
        for(int i=0;i<m;i++)
            scanf("%I64d%I64d",&shop[i].p,&shop[i].gg);
        
        sort(cow,cow+n);    sort(shop,shop+m);
       // for(int i=0;i<n;i++)
       //     printf("%d->%d\n",cow[i].gg,cow[i].p);
       // for(int i=0;i<m;i++)
       //     printf("%d->%d\n",shop[i].gg,shop[i].p);
        
        __int64 sum=0;
        int flag=0,t=m-1;
        multimap<__int64,int>mp;
        multimap<__int64,int>::iterator p;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=t;j>=0;j--)
            {
                if(shop[j].gg<cow[i].gg){t=j;break;}
                mp.insert(make_pair(shop[j].p,1));
            }
            p=mp.lower_bound(cow[i].p);
            if(p==mp.end()){flag=1;break;}
            sum=sum+p->first;
            mp.erase(p);
        }
        if(flag)puts("-1");
        else printf("%I64d\n",sum);
    }
    return 0;
}
