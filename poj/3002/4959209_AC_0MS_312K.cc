
#include<stdio.h>
#include<stdlib.h>
int data[6];

/*int cmp(const void *e1,const void *e2)
{
    return *(int *)e1-*(int *)e2;
}
*/
__int64 lcm(int start,int over)
{
    int t,mid;
    __int64 mul,a,b;
    if(start!=over){
                    mid=(start+over)/2;
                    a=lcm(start,mid);
                    b=lcm(mid+1,over);
                    mul=a*b;
                    if(a<b)
                           t=a,a=b,b=t;
                    while(b)
                            t=a,a=b,b=t%b;
                    return mul/a;
    }
    else return data[start];
}
    
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
               int i,n;
               __int64 ans;
               scanf("%d",&n);
               for(i=0;i<n;i++)
               scanf("%d",&data[i]);
               //qsort(data,n,sizeof(int),cmp);
               ans=lcm(0,n-1);
               if(ans<=1000000000)
                                  printf("%d\n",ans);
               else
                   printf("More than a billion.\n");
    }
    return 0;
}
