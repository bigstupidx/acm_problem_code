#include<stdio.h>
#include<algorithm>
#define MAX 20001
using namespace std;
int a[2*MAX];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
                               int i,ans=0;
                               for(i=0;i<n;i++) scanf("%d",a+i);
                               sort(a,a+n);
                               for(i=1;i<n;i++)
                               {
                                               ans+=a[i]+a[i-1];
                                               a[i]+=a[i-1];
                                               sort(a+i,a+n);
                               }                               
                               printf("%d\n",ans);
                               
    }
    return 0;
}
                               
