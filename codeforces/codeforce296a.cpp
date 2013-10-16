#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, arr[102];

int main(){
    while(scanf("%d", &n)!=EOF){
        for(int i = 0;i<n;i++){
            scanf("%d", arr+i);
        }
        sort(arr, arr+n);
        int temp = -1, count = 0;
        bool flag = true;
        for(int i =0;i<n;i++){
            if(arr[i]==temp){
                ++count;
                if(count>(n+1)/2){
                    flag = false;
                    break;
                }
            }else{
                temp = arr[i];
                count = 1;
            }
        }
        if(flag){
            puts("YES");
        }else{
            puts("NO");
        }
    }
    return 0;
}
