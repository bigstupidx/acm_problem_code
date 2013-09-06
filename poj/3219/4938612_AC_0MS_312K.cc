/*
> 题目的本质是求n! mod 2
> n!质因数分解，只需算出2的阶数
> n! / (k! (n - k)!) 判断分子和分母的大小即可
嗯，而且计算N！中2的阶数，只要计算N/2+N/4……
*/

#include<stdio.h>
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
                                    int m=n-k;
                                    int a=0,b=0,c=0;
                                    while(n=n>>1)a+=n;
                                    while(m=m>>1)b+=m;
                                    while(k=k>>1)c+=k;
                                    if(a>b+c)printf("0\n");
                                    else printf("1\n");
    }
    return 0;
}
