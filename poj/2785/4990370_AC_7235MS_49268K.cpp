#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define MAX 4001

__int64 a[MAX][4],hash[MAX*MAX];
__int64 s,ans;
int len,n,id;


int find(__int64 s)
{
    int left,right,middle,key;
    left=0;right=len;
    while(left<=right){
                       middle=(left+right)/2;
                       if(hash[middle]>=s){
                                           key=middle;
                                           right=middle-1;
                       }
                       else
                           left=middle+1;
    }
    return key;
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
                    for(j=0;j<4;j++)
                                    scanf("%I64d",&a[i][j]);
    k=0;
    for(i=0;i<n;i++)
                    for(j=0;j<n;j++)
                                    hash[k++]=a[i][0]+a[j][1];
                                    
    len=k-1;
    sort(hash,hash+k);
    ans=0;
    for(i=0;i<n;i++)
                    for(j=0;j<n;j++)
                    {
                                    s=-a[i][2]-a[j][3];
                                    if(s<hash[0]||s>hash[len])
                                                            continue;
                                    id=find(s);
                                    for(k=id;k<=len;k++)
                                    {
                                                        if(s<hash[k])
                                                                     break;
                                                        ans++;
                                    }
                    }
    printf("%I64d\n",ans);
    return 0;
}
                                    
