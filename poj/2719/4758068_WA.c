#include<stdio.h>

int main()
{
   long n,a[10];
   int i;
   for(i=1,a[0]=9;i<10;i++)
      a[i]=a[i-1]*9;
   while(scanf("%ld",&n),n){
        int t;
        long m,sum=0;
        m=n/10;i=0;
        while(m){
        t=m%10;sum+=t*a[i++];m/=10;}
        t=n%10;
        if(t<4)sum+=t;
        else sum+=t-1;
        printf("%ld: %ld",n,sum);
  }
   return 0;
}
        