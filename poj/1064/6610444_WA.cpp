#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
double arr[10010];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        double lf=0,rt=1000000;
        for(int i=0;i<n;i++)
            scanf("%lf",&arr[i]);
        while(fabs(rt-lf)>1e-6){
            double mid=(rt+lf)/2;
            __int64 sum=0;
            for(int i=0;i<n;i++)
                sum+=(__int64)(arr[i]/mid);
            //printf("%lld %lf\n",sum,mid);
            if(sum>=k)
                lf=mid;
            else
                rt=mid;
        }
        //printf("%lf %lf\n",lf,0.01);
        if(0.01>lf){
            if(fabs(lf-0.01)<1e-3)
                puts("0.01");
            else
                puts("0.00");
        }
        else
            printf("%.2lf\n",lf);
    }
    return 0;
}
