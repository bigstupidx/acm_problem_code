#include <cstdio>
#include <cstring>
using namespace std;
double arr[10010];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        double lf=0,rt=-1,mid;
        for(int i=0;i<n;i++){
            scanf("%lf",arr+i);
            if(rt<arr[i])rt=arr[i];
        }
        while(rt-lf>1e-6){
            mid=(lf+rt)/2;
            __int64 sum=0;
            for(int i=0;i<n;i++)
                sum+=(__int64)(arr[i]/mid);
            if(sum>=k)lf=mid;
            else    rt=mid;
        }
        if((int)(10*lf)<1)
            puts("0.00");
        else
            printf("%.2lf\n",lf);
    }
    return 0;
}
