/*

*/

#include<stdio.h>
int arrey[10001];
int main()
{
    int i,n;
    long long t;
    arrey[0]=1;
    arrey[1]=1;
    t=1;
    for(i=2;i<10001;i++){
       t*=i;
       while((t%10)==0)t/=10;
       t=t%100000;
       arrey[i]=t%10;
    }
    while(scanf("%d",&n)!=EOF)
        printf("%5d -> %d\n",n,arrey[n]);
    return 0;
}
