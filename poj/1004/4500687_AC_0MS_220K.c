#include<stdio.h>
int main()
{
   double a[12],sum=0;
   int i;
   for(i=0;i<12;i++)
      scanf("%lf",&a[i]);
   for(i=0;i<12;i++)
      sum+=a[i];
   printf("$%.2lf\n",sum/12);
   return 0;
}