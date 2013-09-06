#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
double arr[10010];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        double lf=0,rt=-1;
        for(int i=0;i<n;i++){
            scanf("%lf",&arr[i]);
            if(rt<arr[i])rt=arr[i];
        }
        while(fabs(rt-lf)>1e-8){
            double mid=(rt+lf)/2;
            long long sum=0;
            for(int i=0;i<n;i++)
                sum+=(long long)(arr[i]/mid);
            //printf("%lld %lf\n",sum,mid);
            if(sum>=k)
                lf=mid;
            else
                rt=mid;
        }
        if(lf<0.01)
            puts("0.00");
        else
            printf("%.2lf\n",lf);
    }
    return 0;
}
