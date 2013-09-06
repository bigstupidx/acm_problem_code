#include<stdio.h>
#include<algorithm>
using namespace std;
int arrey[102];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
           for(int i=0;i<n;i++)scanf("%d",arrey+i);
           sort(arrey,arrey+n);
           if(k==n||k%2&&arrey[n-1]<0)
           {
                 for(int i=n-1;i>=n-k;i--)
                 printf("%d ",arrey[i]);
                 printf("\n");
           }
           int i=0,j=n-1;
           if(k%2){j--;k--;}
           while(k)
           {
                   k-=2;
                   if(arrey[i]*arrey[i+1]>arrey[j]*arrey[j-1])
                   i+=2;
                   else
                   j-=2;
           }
           for(k=n-1;k>j;k--)printf("%d ",arrey[k]);
           for(k=i-1;k>=0;k--)printf("%d ",arrey[k]);
           printf("\n");
    }
    return 0;
}
