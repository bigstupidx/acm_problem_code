#include <cstdio>
#include <cstring>
#define MAXN 40010
int aa[MAXN],bb[MAXN];
int bina_search(int n,int x)
{
    int l=0,r=n,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(bb[mid]>x)
            r=mid-1;
        else if(bb[mid]==x)return mid;
        else
            l=mid+1;
    }
    return l;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k=0,n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",aa+i);
        bb[0]=aa[0];
        for(int i=1;i<n;i++)
        {
            int j=bina_search(k,aa[i]);
            //printf("%d %d\n",aa[i],j);
            bb[j]=aa[i];
            if(j>k)k++;
        }
        printf("%d\n",k+1);
    }
    system("pause");
    return 0;
}
