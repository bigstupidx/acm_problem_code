#include<stdio.h>

long sum;
long knight(int day)
{
     long n,i;
     for(n=1;;n++)
         if(n*(n+1)/2>day)break;
     for(i=1;i<n;i++)
         sum+=i*i;
     i=day-n*(n-1)/2;
     sum+=i*(n);
     return sum;
}
         
int main()
{
    int days;
    while(scanf("%d",&days)&&days!=0){
                                      sum=0;
                                      printf("%d ",days);
                                      sum=knight(days);
                                      printf("%ld\n",sum);
    }
    return 0;
}
