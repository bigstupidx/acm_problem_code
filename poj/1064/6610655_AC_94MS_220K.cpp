#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char str[20];
int get_num(){
    int len=strlen(str),ans=0;
    for(int i=0;i<len;i++){
        if(str[i]=='.')continue;
        ans=ans*10+str[i]-'0';
    }
    return ans;
}
int arr[10010],n,k;
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s",str);
            arr[i]=get_num();
        }
        sort(arr,arr+n);
        int lf=1,rt=arr[n-1],mid;
        while(lf<=rt){
            mid=(lf+rt)/2;
            __int64 sum=0;
            for(int i=0;i<n;i++)
                sum+=arr[i]/mid;
            if(sum>=k)
                lf=mid+1;
            else
                rt=mid-1;
        }
        if(lf==1){
            __int64 sum=0;
            for(int i=0;i<n;i++)
                sum+=arr[i];
            if(sum>=k)puts("0.01");
            else
                puts("0.00");
        }
        else{
            lf--;
            printf("%.2lf\n",lf/100.0);
        }
    }
    return 0;
}
