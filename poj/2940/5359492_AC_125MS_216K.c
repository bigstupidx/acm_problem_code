#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    while(scanf("%d",&n),n){
                            __int64 rest=0,total=0;
                            int x;
                            while(n--){
                                       scanf("%d",&x);
                                       x+=rest;
                                       total+=fabs(x);
                                       rest=x;
                            }
                            printf("%I64d\n",total);
    }
    return 0;
}
