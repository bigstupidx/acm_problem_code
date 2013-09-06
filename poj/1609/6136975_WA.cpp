#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int aa[100010],bb[100010];
struct node{int x,y;}nod[100010];
bool cmp1(node a,node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
bool cmp2(node a,node b)
{
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}
int bina_search(int n,int x)
{
    int l=1,r=n,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(bb[mid]>x)
            l=mid+1;
        else
            r=mid-1;
    }
    return l;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int k1=1,k2=1;
        for(int i=0;i<n;i++)
            scanf("%d%d",&nod[i].x,&nod[i].y);
        sort(nod,nod+n,cmp1);
        //for(int i=0;i<n;i++)
        //    printf("%d %d\n",nod[i].x,nod[i].y);
        bb[1]=nod[0].y;
        for(int i=1;i<n;i++)
        {
            int j=bina_search(k1,nod[i].y);
            bb[j]=nod[i].y;
            if(j>k1)k1++;
        }
        sort(nod,nod+n,cmp2);
        bb[1]=nod[0].x;
        for(int i=1;i<n;i++)
        {
            int j=bina_search(k2,nod[i].x);
            bb[j]=nod[i].x;
            if(j>k2)k2++;
        }
        printf("%d\n",k1>k2?k1:k2);
    }
    puts("*");
    return 0;
}
