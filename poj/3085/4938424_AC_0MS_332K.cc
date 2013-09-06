/*水题啊*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
               int sum,q,d,n,p;
               scanf("%d",&sum);
               q=sum/25;
               sum-=q*25;
               d=sum/10;
               sum-=d*10;
               n=sum/5;
               p=sum-n*5;
               printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",i,q,d,n,p);
    }
    system("pause");
    return 0;
}
               
               
