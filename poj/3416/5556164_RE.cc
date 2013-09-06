
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define lowbit(x) ((x)&(x^(x-1)))
using namespace std;
struct node{
    int i;
    int x,y;
    int ss;/*mark the state is weither check or other*/
    int sum1,sum2;
}nod[10010];
int m,n,c[500010],MAX;
bool cmp(node a,node b)
{
    return a.x<b.x;
}
bool mycmp(node a,node b)
{
    return a.i<b.i;
}
void check1()
{
    memset(c,0,sizeof(c));
    for(int i=0;i<m+n;i++)
    {
        int j=nod[i].y+1;
        if(nod[i].ss==1)
        {
            int sum=0;
            while(j>0){
                sum+=c[j];
                j-=lowbit(j);
            }
            nod[i].sum1=sum;
            continue;
        }
        j=nod[i].y+1;
        while(j<=MAX){
            c[j]++;
            j+=lowbit(j);
        }
    }
}
void check2()
{
    int count=0;
    memset(c,0,sizeof(c));
    for(int i=m+n-1;i>=0;i--)
    {
        int j=nod[i].y+1;
        if(nod[i].ss==1)
        {
            int sum=0;
            while(j>0){
                sum+=c[j];
                j-=lowbit(j);
            }
            nod[i].sum2=count-sum;
            continue;
        }
        count++;
        j=nod[i].y+1;
        while(j<=MAX){
            c[j]++;
            j+=lowbit(j);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        MAX=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&nod[i].x,&nod[i].y);
            nod[i].ss=0;nod[i].i=0;
            if(MAX<nod[i].y+1)MAX=nod[i].y+1;
        }
        for(int i=n;i<m+n;i++)
        {
            scanf("%d%d",&nod[i].x,&nod[i].y);
            nod[i].ss=1;nod[i].i=i;
        }
        sort(nod,nod+n+m,cmp);
        check1();
        check2();
        sort(nod,nod+n+m,mycmp);
        for(int i=n;i<m+n;i++)
        {
            int temp=nod[i].sum1+nod[i].sum2;
            printf("%d\n",abs(temp-(n-temp)));
        }
    }
    return 0;
}
