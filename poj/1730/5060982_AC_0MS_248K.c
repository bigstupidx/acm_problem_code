#include<stdio.h>
#include<math.h>

__int64 fin(int n,int i)
{
        __int64 temp=n;
        int j;
        for(j=2;j<=i;j++)
        temp*=n;
        return temp;
}
int main()
{
    __int64 p;
    while(scanf("%I64d",&p),p){
                               __int64 x;
                               int n,i;
                               x=p>0?p:-p;
                               for(i=32;i>0;i--){
                                                 n=(int)(pow(x,1.0/i)+0.5);
                                                 if(fin(n,i)==x){
                                                                      if(p<0&&i%2==0)continue;
                                                                      printf("%d\n",i);
                                                                      break;
                                                 }
                               }
    }
    return 0;
}
