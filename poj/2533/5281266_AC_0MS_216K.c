#include<stdio.h>
#define MAX 10001
int a[MAX],c[MAX];
int search(int len,int x)
{
    int l=1,h=len,m;
    while(l<=h){
                m=(l+h)/2;
                if(c[m]>x)h=m-1;
                else if(c[m]<x)l=m+1;
                else return m;
    }
    return l;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
                               int i,ans=1;
                               for(i=0;i<n;i++) scanf("%d",a+i);
                               c[1]=a[0];
                               for(i=1;i<n;i++)
                               {
                                               int j=search(ans,a[i]);
                                               c[j]=a[i];
                                               if(j>ans)ans++;
                               }
                               printf("%d\n",ans);
                               
    }
    return 0;
}
                               
