#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int n,ppl[1010];
struct QN{int tg,cc,dd;};
int main()
{
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&ppl[i]);
        sort(ppl+1,ppl+n+1);
        if(n==1)
        {
            printf("%d\n%d\n",ppl[1],ppl[1]);
            continue;
        }
        QN now;
        queue<QN>Q;
        __int64 ans=0;
        int a=1,b=2,c=n-1,d=n;
        int t1=ppl[a],t2=ppl[b];
        while(b<c)
        {
            int t3=ppl[c];
            int t4=ppl[d];
            if(2*t2<t3+t1)
            {
                ans+=2*t2+t1+t4;
                now.tg=1;
                now.cc=ppl[a];   now.dd=ppl[b];
                Q.push(now);
                now.tg=0;
                now.cc=ppl[a];   Q.push(now);
                now.tg=1;
                now.cc=ppl[c];   now.dd=ppl[d];
                Q.push(now);
                now.tg=0;
                now.cc=ppl[b];   Q.push(now);
            }
            else
            {
                ans+=t4+t1+t3+t1;
                now.tg=1;
                now.cc=ppl[a];   now.dd=ppl[d];
                Q.push(now);
                now.tg=0;
                now.cc=ppl[a];   Q.push(now);
                now.tg=1;
                now.cc=ppl[a];   now.dd=ppl[c];
                Q.push(now);
                now.tg=0;
                now.cc=ppl[a];   Q.push(now);
            }
            c-=2;d-=2;
        }
        if(d==b+1)
        {
            ans+=ppl[d]+t1+t2;
            now.tg=1;
            now.cc=ppl[a];   now.dd=ppl[d];
            Q.push(now);
            now.tg=0;
            now.cc=ppl[a];   Q.push(now);
            now.tg=1;
            now.cc=ppl[a];   now.dd=ppl[b];
            Q.push(now);
        }
        else
        {
            ans+=t2;
            now.tg=1;
            now.cc=ppl[a];   now.dd=ppl[b];
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
