#include<stdio.h>
#include<algorithm>
#define lowdigit(x) ((x)&((x)^(x-1)))
#define MAX 500010
using namespace std;

struct node{
    int data;
    int ii;
    int sit;
}nodes[MAX];
int c[MAX];
bool op(node a,node b)
{
    return a.ii<b.ii;
}    
bool cmp(node a,node b)
{
    return a.data<b.data;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&nodes[i].data);
            nodes[i].ii=i;
            c[i]=0;
        }
        sort(nodes+1,nodes+1+n,cmp);
        nodes[1].sit=1;
        for(int i=2;i<=n;i++)
        {
            nodes[i].sit=nodes[i-1].sit;
            if(nodes[i].data!=nodes[i-1].data)
                nodes[i].sit++;
        }
        sort(nodes+1,nodes+1+n,op);
        for(int j=1;j<=n;j++)
        {
            int i,temp=nodes[j].sit;
            ans+=j-1;
            i=temp;
            while(i)
            {
                ans-=c[i];
                i-=lowdigit(i);
            }
            i=temp;
            while(i<=n)
            {
                c[i]++;
                i+=lowdigit(i);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
