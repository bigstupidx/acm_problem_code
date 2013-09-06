
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 4005

int n,len;
__int64 a[maxn][4],b[maxn*maxn],ans;
__int64 s;

int find(__int64 s)
{
       int l,r,m,key;
       l=0;r=len-1;
       while(l<=r)
       {
              m=(l+r)>>1;
              if(b[m]>s){
                     r=m-1;
              }
              else if(b[m]==s)
                   return 1;
              else if(b[m]<s){
                     l=m+1;
              }
       }
       return 0;
}

int main()
{
       int i,j,k;
       scanf("%d",&n);
       for(i=0;i<n;i++)
       {
              for(j=0;j<4;j++)
                     scanf("%I64d",&a[i][j]);
       }
       len=0;
       for(i=0;i<n;i++)
              for(j=0;j<n;j++)
                     b[len++]=a[i][0]+a[j][1];
       sort(b,b+len);
       ans=0;
       for(i=0;i<n;i++)
       {
              for(j=0;j<n;j++)
              {
                     s=-a[i][2]-a[j][3];
                     if(s<b[0] || s>b[len-1])
                            continue;
                     if(find(s))ans++;
              }
       }
       printf("%I64d\n",ans);
       return 0;
}


