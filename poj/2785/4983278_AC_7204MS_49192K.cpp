//2785 先枚举前面两列之和然后排序，然后枚举后两列之和，再二分查找

//    用hash也是先枚举，然后hash存贮。感觉hash要快一些，但由于我的hash水平不够，
//两个程序都是7000＋ms

//二分

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
              if(b[m]>=s){
                     key=m;
                     r=m-1;
              }
              else{
                     l=m+1;
              }
       }
       return key;
}

int main()
{
       int i,j,k,id;
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
                     id=find(s);
                     for(k=id;k<len;k++)
                     {
                            if(b[k]>s)
                                   break;
                            ans++;
                     }
              }
       }
       printf("%I64d\n",ans);
       return 0;
}


