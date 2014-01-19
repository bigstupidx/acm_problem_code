/*
第一问：E(x)=k/p;D(x)=k(1-p)/p^2;D(x)=E(x^2)-E(x)^2
第二问：E(x^2)=D(x)+E(x)^2; 
*/
#include <cstdio>
#include <cstring>
int main()
{
    int k;
    double p;
    while(scanf("%d",&k),k)
    {
        scanf("%lf",&p);
        printf("%.3lf %.3lf\n",k/p,(k+k*k-k*p)/(p*p));
    }
    return 0;
}
