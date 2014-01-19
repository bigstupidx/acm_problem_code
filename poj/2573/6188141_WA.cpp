#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
    int id;
    int tt;
    bool operator<(const node a)const
    {
        return a.tt>tt;
    }
}nod[1010];
struct QN{int tg,cc,dd;};
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            nod[i].id=i;
            scanf("%d",&nod[i].tt);
        }
        sort(nod,nod+n);
        
        QN now;
        queue<QN>Q;
        __int64 ans=0;
        int a=1,b=2,c=n-1,d=n;
        int t1=nod[a].tt,t2=nod[b].tt;
        while(b<c)
        {
            int t3=nod[c].tt;
            int t4=nod[d].tt;
            if(2*t2<t3+t1)
            {
                ans+=2*t2+t1+t4;
                now.tg=1;
                now.cc=nod[a].id;   now.dd=nod[b].id;
                Q.push(now);
                now.tg=0;
                now.cc=nod[a].id;   Q.push(now);
                now.tg=1;
                now.cc=nod[c].id;   now.dd=nod[d].id;
                Q.push(now);
                now.tg=0;
                now.cc=nod[b].id;   Q.push(now);
            }
            else
            {
                ans+=t4+t1+t3+t1;
                now.tg=1;
                now.cc=nod[a].id;   now.dd=nod[d].id;
                Q.push(now);
                now.tg=0;
                now.cc=nod[a].id;   Q.push(now);
                now.tg=1;
                now.cc=nod[a].id;   now.dd=nod[c].id;
                Q.push(now);
                now.tg=0;
                now.cc=nod[a].id;   Q.push(now);
            }
            c-=2;d-=2;
        }
        if(d==b+1)
        {
            ans+=nod[d].tt+t1+t2;
            now.tg=1;
            now.cc=nod[a].id;   now.dd=nod[d].id;
            Q.push(now);
            now.tg=0;
            now.cc=nod[a].id;   Q.push(now);
            now.tg=1;
            now.cc=nod[a].id;   now.dd=nod[b].id;
            Q.push(now);
        }
        else
        {
            ans+=t2;
            now.tg=1;
            now.cc=nod[a].id;   now.dd=nod[b].id;
            Q.push(now);
        }
        printf("%I64d\n",ans);
        while(!Q.empty())
        {
            now=Q.front();Q.pop();
            if(now.tg==0)
                printf("%d\n",now.cc);
            else
                printf("%d %d\n",now.cc,now.dd);
        }
    }
    return 0;
}
