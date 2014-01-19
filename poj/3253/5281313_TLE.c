#include<stdio.h>
#include<stdlib.h>
#define MAX 20001
int a[2*MAX];

int cmp(const void *e1,const void *e2)
{
    return *(int *)e1-*(int *)e2;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
                               int i,ans=0;
                               for(i=0;i<n;i++) scanf("%d",a+i);
                               qsort(a,n,sizeof(int),cmp);
                               for(i=1;i<n;i++)
                               {
                                               ans+=a[i]+a[i-1];
                                               a[i]+=a[i-1];
                                               qsort(a+i,n-i,sizeof(int),cmp);
                               }                               
                               printf("%d\n",ans);
                               
    }
    return 0;
}
                               
