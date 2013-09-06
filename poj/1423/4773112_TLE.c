//double log10(double x) 返回log10x的值

#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
               
                            double sum;
                            int i,n;
                            sum=0;
                            scanf("%d",&n);
                            for(i=2;i<=n;i++)
                                sum+=log10(i);
                            printf("%d\n",(int)sum+1);
    }
    return 0;
    
}
