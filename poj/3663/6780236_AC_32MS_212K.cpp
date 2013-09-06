#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, s, arr[20002];

int my_search(int x){
    int lf=0,rt=n-1;
    while(rt>=lf){
        int mid=(lf+rt)/2;
        if(arr[mid]>x)
            rt=mid-1;
        else
            lf=mid+1;
    }
    return lf;
}

int main() {
    while (scanf("%d%d", &n, &s) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", arr + i);
        }
        sort(arr,arr+n);
        long long ans=0;
        for(int i=0;i<n;i++){
            int tem=s-arr[i];
            if(tem<arr[i])break;
            int j=my_search(tem);
            //printf("%d %d %d\n",tem,j,ans);
            if(j>i)ans+=j-i-1;
            else break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
