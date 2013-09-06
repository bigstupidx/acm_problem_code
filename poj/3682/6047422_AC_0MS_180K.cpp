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
